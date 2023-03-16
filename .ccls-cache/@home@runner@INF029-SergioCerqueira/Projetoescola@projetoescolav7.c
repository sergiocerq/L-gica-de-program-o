#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define TAMALUNO 10 
#define TAMPROF 10 
#define TAMDIS 5 
/*TAMALUNO é o tamanho da struct de aluno
  TAMPROF é o tamanho da struct de professores
  TAMDIS é o tamanho da struct de disciplinas*/
//Declaração das structs
  typedef struct data{ //struct para data de nascimento
    int dia, mes, ano;
  }nasc;
  
  typedef struct { //struct aluno
    int matricula;
    char nome[50];
    char sexo; //M -> masculino e F -> feminino
    struct data nasc; //chamada para struct da data de nascimento
    char cpf[15];
    int ativo; //váriavel auxiliar para verificação de exclusão de cadastro
  } fichaluno;
  
  typedef struct { //struct professor
    int ativo;
    int matricula;
    char nome[50];
    char sexo;
    struct data nasc; //chamada para struct da data de nascimento
    char cpf[16];
  } fichaprof;

  typedef struct { //struct disciplinas
    char nome[50];
    int codigo;
    int semestre; //somente numeros
    char professor[50];
    fichaluno alunodisc[60]; // chamada para a struct de alunos
    int alunocad;
  } fichadisc;
  
  //Declaração de funções
  int menuprincipal(int opcao);
  int menualuno(int opcaoaluno);
  int menuprof(int opcaoprof);
  int menudisciplina(int opcaodisc);
  int menuopcoesdiversas(int opcaodiversa);

//Inicialização da função main
int main() { 
  setlocale(LC_ALL, "Portuguese"); //função que permite a acentuação em português
  int opcao, i, j, k, cont=0, opcaoaluno, opcaoprof, opcaodisc, opcaodiversa, dataerrada=1, qtdalunos=0, qtdprof=0, qtddisc=0, ln, cadastro, matricula, alunocadastrado, alunocad, codigo, achou=0, mes; //declaração de váriaveis auxiliares
  char sexo, letrateste[21];

  fichaluno alunos[TAMALUNO],copia1; // declaração da struct alunos
  fichaprof prof[TAMPROF], copia2; // declaração da struct professor
  fichadisc disciplinas[TAMDIS]; // declaração da struct discipinas
  do {
      setbuf(stdin, 0);
      opcao = menuprincipal(opcao);
      switch (opcao) {
          do {
            case 1: {
              opcaoaluno = menualuno(opcaoaluno);
               switch (opcaoaluno) { 
                   case 1:  {
                     setbuf(stdin, 0);
            printf("*****Cadastro de alunos*****\n");
            if(qtdalunos == TAMALUNO) {//teste para bloquear a inserção de alunos acima do limite
                printf("Lista de alunos cheia!");
                break;
            }
                else {
                printf("Aluno %d:\n", qtdalunos + 1);
                do {
                    printf("Informe a matricula: ");
                    scanf("%d", &alunos[qtdalunos].matricula);
                }while(alunos[qtdalunos].matricula < 0);  //teste de matrícula
                setbuf(stdin, 0);
                
                printf("Informe o nome: ");//cadastro do nome do aluno
                fgets(alunos[qtdalunos].nome, 49, stdin); 
                ln = strlen(alunos[qtdalunos].nome) - 1; //processo para remoção do '\n' do fgets
                if (alunos[qtdalunos].nome[ln] == '\n')
                  alunos[qtdalunos].nome[ln] = '\0';
                  do { //cadastro do sexo do aluno (apenas com F ou M)
                    printf("Informe o sexo com F ou M: ");
                    scanf("%c", &alunos[qtdalunos].sexo); 
                    getchar();
                }while(alunos[qtdalunos].sexo != 'F' && alunos[qtdalunos].sexo != 'M');
                do {
                    dataerrada=0;
                    printf("Informe a data de nascimento no formato dd mm aaaa: ");
                    scanf("%d%d%d", &alunos[qtdalunos].nasc.dia, &alunos[qtdalunos].nasc.mes, &alunos[qtdalunos].nasc.ano); 
                    if(alunos[qtdalunos].nasc.dia > 32 || alunos[qtdalunos].nasc.mes > 12 || alunos[qtdalunos].nasc.ano > 2022 || alunos[qtdalunos].nasc.ano < 1930)
                        dataerrada++;
                }while(dataerrada > 0);
                getchar();
                printf("Informe o cpf corretamente: ");//cadastro de cpf do aluno
                fgets(alunos[qtdalunos].cpf, 15, stdin);
                ln = strlen(alunos[qtdalunos].cpf) - 1; //remoção do '\n' do fgets
                if (alunos[qtdalunos].cpf[ln] == '\n') {
                  alunos[qtdalunos].cpf[ln] = '\0';
                }
                  setbuf(stdin, 0); 
                  
                  
                  alunos[qtdalunos].ativo = 1;
                  printf("Aluno cadastrado com sucesso!\n");
                  printf("\n");
                    if(qtdalunos>0) { //procedimento para ordenar os alunos por ordem alfabetica
                      setbuf(stdin, 0);
                      for(i=qtdalunos;i>0;i--) {
                        copia1 = alunos[i - 1];
                        if(strcmp(copia1.nome, alunos[i].nome) > 0) {
                          alunos[i - 1] = alunos[i];
                          alunos[i] = copia1;
                        }
                        else {
                          continue;
                        }
                      }
                    }
                    
                    qtdalunos++;
                    break;
                   }
                       break;
                   }
                   case 2: {
                       printf("*****Listar alunos*****\n");
                        if (qtdalunos == 0) { //teste para verificar se a matrícula existe
                    printf("Nenhum aluno cadastrado!\n");
                    break;
                  }
                else {
                  ln=1;
                  for(i=0;i<qtdalunos;i++) { //listagem dos alunos
                    if(alunos[i].ativo == 1) {
                    printf("Aluno %d:\n", ln);
                    printf("Nome: %s\n", alunos[i].nome );
                    printf("Matricula: %d\n", alunos[i].matricula); 
                    printf("Sexo: %c\n", alunos[i].sexo);
                    printf("CPF: %s\n", alunos[i].cpf);
                    printf("Data de nascimento: %d/%d/%d\n", alunos[i].nasc.dia, alunos[i].nasc.mes, alunos[i].nasc.ano);
                    printf("\n");
                    ln++;
                    }
                  }           
                }
                       break;
                   }
                   
                   case 3: {
                    if(qtdalunos == 0) {
                        printf("Nenhum aluno cadastrado!\n");
                        break;
                      }
                      else {
                        printf("Atualizar aluno\n");
                        printf("Informe a matricula que deseja atualizar: ");
                        scanf("%d", &matricula);
                        for(i=0;i<qtdalunos;i++) { //procura para ver se uma matrícula existe
                          achou=0;
                          if(matricula == alunos[i].matricula && alunos[i].ativo == 1) {
                              achou++;
                              printf("Informe os novos dados:\n");
                          do {
                              printf("Informe a matricula: ");
                              scanf("%d", &alunos[i].matricula);
                          }while(alunos[i].matricula < 0);  //teste de matrícula
                          getchar();
                          printf("Informe o nome: ");
                          fgets(alunos[i].nome, 49, stdin); 
                          ln = strlen(alunos[i].nome) - 1; 
                          if (alunos[i].nome[ln] == '\n')
                            alunos[i].nome[ln] = '\0';
                          do {
                              printf("Informe o sexo com F ou M: ");
                              scanf("%c", &alunos[i].sexo); 
                              getchar();
                          }while(alunos[i].sexo != 'F' && alunos[i].sexo != 'M');
                          
                          do {
                              dataerrada=0;
                              printf("Informe a data de nascimento no formato dd mm aaaa: ");
                              scanf("%d%d%d", &alunos[i].nasc.dia, &alunos[i].nasc.mes, &alunos[i].nasc.ano); 
                              if(alunos[i].nasc.dia > 32 || alunos[i].nasc.mes > 12 || alunos[i].nasc.ano > 2022 || alunos[i].nasc.ano < 1930)
                                  dataerrada++;
                          }while(dataerrada > 0);
                          getchar();
                          printf("Informe o cpf corretamente: ");
                          fgets(alunos[i].cpf, 15, stdin);
                          ln = strlen(alunos[i].cpf) - 1; 
                          if (alunos[i].cpf[ln] == '\n') {
                            alunos[i].cpf[ln] = '\0';
                          }
                            alunos[i].ativo = 1;
                            qtdalunos++; //verificar se o teste vai dar certo
                            printf("Aluno atualizado com sucesso!\n");

                          if(qtdalunos>0) {
                            //procedimento para ordenar os alunos por ordem alfabetica
                            setbuf(stdin, 0);
                            for(i=qtdalunos;i>0;i--) {
                              copia1 = alunos[i - 1];
                              if(strcmp(copia1.nome, alunos[i].nome) > 0) {
                                alunos[i - 1] = alunos[i];
                                alunos[i] = copia1;
                          }
                          else {
                            continue;
                          }
                        }
                      }
                            printf("\n");
                          break;
                          } 
                        }
                        if(achou == 0) {
                          printf("Aluno não encontrado ou inativo!\n");
                          break;
                        }
                        break;
                      }
                        break;
                      
                      break;
                    }

                   case 4: {
                    if(qtdalunos == 0) {
                        printf("Nenhum aluno cadastrado!\n");
                        break;
                    }
                    else {
                      setbuf(stdin, 0);
                      printf("Excluir aluno\n");
                      printf("Informe a matricula que deseja excluir: ");
                      scanf("%d", &matricula);
                      achou=0;
                      for(i=0;i<qtdalunos;i++) { //procura para ver se uma matrícula existe
                      setbuf(stdin, 0);
                        if(matricula == alunos[i].matricula && alunos[i].ativo == 1) {
                          setbuf(stdin, 0);
                          alunos[i].ativo = 0;
                          for(j=i;j<qtdalunos;j++) {
                              alunos[j] = alunos[j+1];
                          }
                          --qtdalunos;
                          achou++;
                          break;
                        }
                    }
                    if(achou > 0) {
                      printf("Aluno excluido com sucesso!\n");
                          break;
                        }
                    }
                    break;
                   }
                   break;
                   case 5: {
                      getchar();
                      if(qtdalunos == 0) {
                        printf("Nenhum aluno cadastrado!\n");
                        break;
                      }
                       printf("Listar alunos por sexo\n");
                       printf("Informe o sexo que deseja listar com M ou F: ");
                       scanf("%c", &sexo);
                       if(sexo == 'M') { //procedimento para busca do sexo
                       printf("Sexo informado: %c\n", sexo);
                        for(i=0;i<qtdalunos;i++) {
                          if(alunos[i].sexo == 'M' && alunos[i].ativo == 1) {
                            printf("\nAluno: %s\n", alunos[i].nome);
                            ln++;
                          }
                        }
                        break;
                       }
                       if(sexo == 'F') {
                        printf("Sexo informado: %c\n", sexo);
                        for(i=0;i<qtdalunos;i++) {
                          if(alunos[i].sexo == 'F' && alunos[i].ativo == 1) {
                            printf("\nAluna: %s\n", alunos[i].nome);
                            ln++;
                          }
                        }
                        break;
                       }
                       if(sexo != 'F' && sexo != 'M') {
                        printf("Opcao invalida!\n");
                        break;
                       }
                       break;
                   }
                   case 6: {
                       printf("Listar alunos por data de nascimento\n");
                       break;
                   }
                   case 7: {
                       printf("Saindo do setor de alunos...\n");
                       break;
                   }
                   default: {
                       printf("Opcao invalida!\n");
                       break;
                   }
               }
            }  
          }while(opcaoaluno != 7);
          break;
          
          do {
            setbuf(stdin, 0);
            case 2: {
              opcaoprof = menuprof(opcaoprof);
               switch (opcaoprof) { 
                   case 1:  { //cadastro de professores
                   if(qtdprof == TAMPROF) {
                    printf("Lista de professores cheia!\n");
                    break;
                   }
                    else {
                    printf("Professor(a) %d\n", qtdprof+1);
                    do {
                    printf("Informe a matricula: ");
                    scanf("%d", &prof[qtdprof].matricula); 
                    }while(prof[qtdprof].matricula < 0); 
                    setbuf(stdin, 0);
                    
                    printf("Informe o nome: ");
                    fgets(prof[qtdprof].nome, 50, stdin);
                    ln = strlen(prof[qtdprof].nome) - 1; 
                    if (prof[qtdprof].nome[ln] == '\n')
                      prof[qtdprof].nome[ln] = '\0';
                    
                    do {
                    printf("Informe o sexo com F ou M: ");
                    scanf("%c", &prof[qtdprof].sexo); 
                    }while(prof[qtdprof].sexo != 'F' && prof[qtdprof].sexo != 'M' ); 
                    getchar();
                    do {
                        dataerrada=0;
                        printf("Informe a data de nascimento no formato dd mm aaaa: ");
                        scanf("%d%d%d", &prof[qtdprof].nasc.dia, &prof[qtdprof].nasc.mes, &prof[qtdprof].nasc.ano); 
                        if(prof[qtdprof].nasc.dia > 31 || prof[qtdprof].nasc.mes > 12 || prof[qtdprof].nasc.ano > 2023 || prof[qtdprof].nasc.ano < 1920)
                            dataerrada++;
                    }while(dataerrada > 0); 
                    getchar();
                    
                    printf("Informe o cpf: ");
                    fgets(prof[qtdprof].cpf, 15, stdin);
                    ln = strlen(prof[qtdprof].cpf) - 1; 
                    if (prof[qtdprof].cpf[ln] == '\n')
                      prof[qtdprof].cpf[ln] = '\0';
                    setbuf(stdin, 0);
                    prof[qtdprof].ativo = 1;
                    printf("Professor cadastrado com sucesso!\n");
                    printf("\n");
                    //++qtdprof;
                    setbuf(stdin, 0);
                    
                    if(qtdprof>0) { //procedimento para ordenar os professores por ordem alfabetica
                      setbuf(stdin, 0);
                      for(i=qtdprof;i>0;i--) {
                        copia2 = prof[i - 1];
                        if(strcmp(copia2.nome, prof[i].nome) > 0) {
                          prof[i - 1] = prof[i];
                          prof[i] = copia2;
                        }
                        else {
                          continue;
                        }
                      }
                    }
                    ++qtdprof;
                    }
                    break;
                   }
                   break;
                   case 2: {
                       printf("Listar professores em ordem alfabetica\n");
                    if (qtdprof == 0) { //teste para verificar se a matrícula existe
                        printf("Nenhum professor cadastrado!\n");
                        break;
                    }
                    else {
                        ln=1;
                        for(i=0;i<qtdprof;i++) { //listagem dos professores em ordem alfabetica
                            if(prof[i].ativo == 1) {
                            printf("Professor(a) %d:\n", ln);
                            printf("Nome: %s\n", prof[i].nome );
                            printf("Matricula: %d\n", prof[i].matricula); 
                            printf("Sexo: %c\n", prof[i].sexo);
                            printf("CPF: %s\n", prof[i].cpf);
                            printf("Data de nascimento: %d/%d/%d\n", prof[i].nasc.dia, prof[i].nasc.mes, prof[i].nasc.ano);
                            printf("\n");
                            ++ln;
                            }
                        }           
                    }
                       break;
                   }
                   case 3: {//Atualizar professores
                   if(qtdprof == 0) {
                       printf("Nao existe nenhum cadastro de professores!");
                       break;
                   }
                   else {
                    printf("Atualizar professores\n");
                    printf("Informe a matricula que deseja Atualizar: ");
                    scanf("%d", &matricula);
                    for(i=0;i<qtdprof;i++) { //procura para ver se uma matrícula existe
                        achou=0;
                        if(matricula == prof[i].matricula) {
                            achou++;
                            printf("Informe os novos dados:\n");
                        do {
                            printf("Informe a matricula: ");
                            scanf("%d", &prof[i].matricula);
                        }while(prof[i].matricula < 0);  //teste de matrícula
                        getchar();
                        printf("Informe o nome: ");
                        fgets(prof[i].nome, 49, stdin); 
                        ln = strlen(prof[i].nome) - 1; 
                        if (prof[i].nome[ln] == '\n')
                          prof[i].nome[ln] = '\0';
                        do {
                            printf("Informe o sexo com F ou M: ");
                            scanf("%c", &prof[i].sexo); 
                            getchar();
                        }while(prof[i].sexo != 'F' && prof[i].sexo != 'M');
                        
                        do {
                            dataerrada=0;
                            printf("Informe a data de nascimento no formato dd mm aaaa: ");
                            scanf("%d%d%d", &prof[i].nasc.dia, &prof[i].nasc.mes, &prof[i].nasc.ano); 
                            if(prof[i].nasc.dia > 32 || prof[i].nasc.mes > 12 || prof[i].nasc.ano > 2022 || prof[i].nasc.ano < 1930)
                                dataerrada++;
                        }while(dataerrada > 0);
                        getchar();
                        printf("Informe o cpf corretamente: ");
                        fgets(prof[i].cpf, 15, stdin);
                        ln = strlen(prof[i].cpf) - 1; 
                        if (prof[i].cpf[ln] == '\n') {
                          prof[i].cpf[ln] = '\0';
                        }

                          prof[i].ativo = 1;
                          qtdprof++;
                        
                        if(qtdprof>0) { //procedimento para ordenar os professores por ordem alfabetica
                          setbuf(stdin, 0);
                          for(i=qtdprof;i>0;i--) {
                            copia2 = prof[i - 1];
                            if(strcmp(copia2.nome, prof[i].nome) > 0) {
                              prof[i - 1] = prof[i];
                              prof[i] = copia2;
                            }
                            else {
                              continue;
                            }
                          }
                        }
                          printf("\n");
                        }
                      }
                      if(achou == 0) {
                        printf("Professor não encontrado ou inativo!\n");
                        break;
                      }
                    break;
                   }
                   break;
                   }
                   case 4: {
                    if(qtdprof == 0) {
                      printf("Nao existe nenhum cadastro de professores!\n");
                      break;
                    }
                    else {
                      setbuf(stdin, 0);
                      printf("Excluir professor\n");
                      printf("Informe a matricula que deseja excluir: ");
                      scanf("%d", &matricula);
                      achou=0;
                      for(i=0;i<qtdprof;i++) { //procura para ver se uma matrícula existe
                      setbuf(stdin, 0);
                        if(matricula == prof[i].matricula && prof[i].ativo == 1) {
                          setbuf(stdin, 0);
                          prof[i].ativo = 0;
                          for(j=i;j<qtdprof;j++) {
                              prof[j] = prof[j+1];
                          }
                          --qtdprof;
                          achou++;
                          break;
                        }
                    }
                    if(achou > 0) {
                      printf("Professor excluido com sucesso!\n");
                          break;
                        }
                    }
                    break;
                   }
                   case 5: {
                    if(qtdprof == 0) {
                      printf("Nao existe nenhum cadastro de professores!\n");
                      break;
                    }
                    else {
                      achou=0;
                       printf("Listar professores por sexo\n");
                       getchar();
                       printf("Informe o sexo que deseja listar com M ou F: ");
                       scanf("%c", &sexo);
                       if(sexo == 'M') {
                        printf("Sexo informado: %c\n\n", sexo);
                        for(i=0;i<qtdprof;i++) {
                          if(prof[i].sexo == 'M') {
                            achou++;
                            printf("Professor: %s\n", prof[i].nome);
                          }
                        }
                        if(achou == 0) {
                          printf("Nao foi possivel encontrar nenhum professor do sexo informado.\n");
                          break;
                        }
                        break;
                       }
                       if(sexo == 'F') {
                        printf("Sexo informado: %c\n\n", sexo);
                        for(i=0;i<qtdprof;i++) {
                          if(prof[i].sexo == 'F') {
                            achou++;
                            printf("Professora: %s\n", prof[i].nome);
                          }
                        }
                        if(achou == 0) {
                          printf("Nao foi possivel encontrar nenhum professor do sexo informado.\n");
                          break;
                        }
                        break;
                       }
                       }
                       if(sexo != 'F' && sexo != 'M') {
                        printf("Opcao invalida!\n");
                        break;
                    }
                    break;
                   }
                   case 6: {
                    if(qtdprof == 0) {
                      printf("Nao existe nenhum cadastro de professores!\n");
                      break;
                    }
                    else {
                       printf("Listar professores por data de nascimento");
                       break;
                    }
                   }
                   case 7: {
                       printf("Saindo do setor de professores...\n");
                       break;
                   }
                   default: {
                       printf("Opcao invalida!\n");
                       break;
                   }
               }
              
            }  
          }while(opcaoprof != 7);
          break;
          
          do {
            case 3: {
              opcaodisc = menudisciplina(opcaodisc);
               switch (opcaodisc) { 
                   case 1:  {
                       if(qtddisc == TAMDIS) {
                      printf("Lista de discipinas cheia!");
                      break;
                  }
                  else {
                    do {
                      printf("Cadastro de disciplinas\n");
                      printf("Informe o codigo da disciplina: ");
                      scanf("%d", &disciplinas[qtddisc].codigo);
                    }while(disciplinas[qtddisc].codigo < 0);  //teste de codigo da discipina
                    getchar();

                    printf("Informe o nome do professor: "); //nome do professor
                    fgets(disciplinas[qtddisc].professor, 50, stdin); 
                    ln = strlen(disciplinas[qtddisc].professor) - 1; 
                    if (disciplinas[qtddisc].professor[ln] == '\n')
                      disciplinas[qtddisc].professor[ln] = '\0';
                    
                    printf("Informe o semestre somente com numeros: "); //semestre somente com numeros
                    scanf("%d", &disciplinas[qtddisc].semestre);
                    getchar();

                    printf("Informe o nome da discipina: "); //nome da discipina
                    fgets(disciplinas[qtddisc].nome, 50, stdin);
                    ln = strlen(disciplinas[qtddisc].nome) - 1; 
                    if (disciplinas[qtddisc].nome[ln] == '\n')
                      disciplinas[qtddisc].nome[ln] = '\0';
                    printf("\n");
                    disciplinas[qtddisc].alunocad=0;
                    qtddisc++;
                    setbuf(stdin, 0);
                    break;
                    }
                  }
                  //break;
                   case 2: {//atualização de disciplinas
                   if(qtddisc == 0) {
                       printf("Nao existe nenhum cadasatro de disciplinas!\n");
                       break;
                   }
                       printf("*****Atualizar disciplina*****\n");
                printf("Informe o codigo que deseja Atualizar: ");
                scanf("%d", &matricula);
                for(i=0;i<qtddisc;i++) { //procura para ver se uma matrícula existe
                    achou=0;
                    if(matricula == disciplinas[i].codigo) {
                        achou++;
                        setbuf(stdin, 0);
                        printf("Informe os novos dados:\n");
                    do {
                        printf("Informe o novo codigo: ");
                            scanf("%d", &disciplinas[i].codigo);
                        }while(disciplinas[i].codigo < 0);  //teste de matrícula
                    getchar();
                    printf("Informe o nome da disciplina: ");
                    fgets(disciplinas[i].nome, 49, stdin); 
                    ln = strlen(disciplinas[i].nome) - 1; 
                    if (disciplinas[i].nome[ln] == '\n') {
                      disciplinas[i].nome[ln] = '\0';
                    }
                      setbuf(stdin, 0);
                    do {
                        printf("Informe o semestre apenas com numeros: ");
                        scanf("%d", &disciplinas[i].semestre); 
                        getchar();
                    }while(disciplinas[i].semestre < 0 && disciplinas[i].semestre > 16);
                    
                    printf("Informe o nome do professor: ");
                    fgets(disciplinas[i].professor, 49, stdin);
                    ln = strlen(disciplinas[i].professor) - 1; 
                    if (disciplinas[i].professor[ln] == '\n')
                      disciplinas[i].professor[ln] = '\0';
                      printf("\n");
                    } 
                    if(achou == 0) {
                        printf("Disciplina nao encontrada!\n");
                  }
                }
                       break;
                   }
                   case 3: { //listagem das disciplinas
                       if(qtddisc == 0) {
                       printf("Não existe nenhum cadastro de disciplinas!\n");
                       }
                    else {
                      printf("Listagem das disciplinas sem os dados dos alunos\n\n");
                        for(i=0;i<qtddisc;i++) { //listagem das disciplinas
                            setbuf(stdin, 0);
                            printf("Disciplina %d:\n", i+1);
                            printf("Nome da discipina: %s\n", disciplinas[i].nome);
                            printf("Codigo: %d\n", disciplinas[i].codigo); 
                            printf("Nome do professor: %s\n", disciplinas[i].professor); 
                            printf("Semestre: %d\n", disciplinas[i].semestre);
                            printf("\n");
                          }
                    }
                    break;
                }
                break;
 
                   case 4: {
                      if(qtddisc == 0 || qtdalunos == 0) {
                        printf("Nao existe nenhum aluno matriculado em uma disciplina!\n");
                        break;
                        }
                      else {
                        
                        printf("Cadastro de alunos em uma disciplina\n");
                        achou=0;
                        printf("Informe a matricula do aluno a ser adicionada: ");
                        scanf("%d", &matricula);
                        printf("Informe o codigo da disciplina para adicionar o aluno: ");
                        scanf("%d", &codigo);

                        for(ln=0;ln<qtdalunos;ln++) {
                          if(matricula == alunos[ln].matricula)
                            achou++;
                        }
                        --ln;
                        for(i=0;i<qtddisc;i++) {
                          if(codigo == disciplinas[i].codigo)
                            achou++;
                        }
                        --i;
                        alunocad = disciplinas[i].alunocad;
                        if(achou > 1) {
                          disciplinas[i].alunodisc[alunocad] = alunos[ln];
                          disciplinas[i].alunocad+=1;
                          ++alunocadastrado;
                          printf("Aluno cadastrado com sucesso!\n");
                          alunocad++;
                        }
                        else {
                          printf("Aluno nao encontrado!\n");
                        break;
                        }
                        break;
                      }
                      
                      }

                      case 5: {
                        setbuf(stdin, 0);
                       ("Listagem de dados dos alunos\n");
                       if(qtddisc == 0 || qtdalunos == 0) {
                      printf("Não existe nenhum cadastro de disciplinas ou alunos!\n");
                      break;
                       }
                       if(alunocadastrado == 0) {
                        printf("Nao existe nenhum aluno cadastrado em uma disciplina!\n");
                        break;
                       }
                       else {
                        setbuf(stdin, 0);
                        printf("Nome da discipina: %s\n", disciplinas[i].nome);
                        printf("Codigo: %d\n", disciplinas[i].codigo); 
                        printf("Nome do professor: %s\n", disciplinas[i].professor); 
                        printf("Semestre: %d\n", disciplinas[i].semestre);
                        printf("\n");

                        for(i=0;i<qtddisc;++i) { //listagem dos alunos cadastrados sem ordem
                            if(disciplinas[i].alunocad > 0) {
                              for(j=0;j<disciplinas[i].alunocad;++j) {
                                setbuf(stdin, 0);
                                printf("Nome do aluno: %s\n", disciplinas[i].alunodisc[j].nome);
                                printf("Matricula do aluno: %d\n", disciplinas[i].alunodisc[j].matricula); 
                                printf("Sexo do aluno: %c\n", disciplinas[i].alunodisc[j].sexo);
                                printf("CPF do aluno: %s\n", disciplinas[i].alunodisc[j].cpf);
                                printf("Data de nascimento do aluno: %d/%d/%d\n", disciplinas[i].alunodisc[j].nasc.dia, disciplinas[i].alunodisc[j].nasc.mes, disciplinas[i].alunodisc[j].nasc.ano);
                                printf("\n");
                              }
                            }
                          }

                          break;
                       }
                       break; 
                   }

                   case 6: {
                    if(qtddisc == 0) {
                      printf("Nao existe nenhum cadastro de disciplinas!\n");
                      break;
                    }
                    else {
                       printf("Disciplinas com mais de 40 alunos:\n");
                       for(i=0;i<qtddisc;i++) {
                        if(disciplinas[i].alunocad >= 40) {
                          printf("Disciplina: %s\n", disciplinas[i].nome);
                          printf("Professor: %s\n", disciplinas[i].professor);
                        }
                       }
                       break;
                    }
                       break;
                   }

                   case 7: {
                       printf("Saindo do setor de disciplinas...\n");
                       break;
                   }

                   default: {
                       printf("Opcao invalida!\n");
                       break;
                   }
                }
               }
               
            }while(opcaodisc != 7);
          
          break;
          
          
            case 4: {
              do {
                printf("Opcoes diversas\n");
                opcaodiversa = menuopcoesdiversas(opcaodiversa);
                switch (opcaodiversa) {
                  case 1: {
                    printf("Aniversariantes do mes:\n");
                    if(qtdalunos == 0 && qtdprof == 0) {
                      printf("Nao existe nenhum cadastro de professor e de aluno.\n");
                      break;
                    }
                    else {
                      printf("Informe o mes que deseja buscar com numeros: ");
                      scanf("%d", &mes);
                      if(qtdalunos > 0) {
                        for(i=0;i<qtdalunos;i++) {
                          if(mes ==  alunos[i].nasc.mes)
                            printf("%s - %d/%d/%d\n", alunos[i].nome, alunos[i].nasc.dia, alunos[i].nasc.mes, alunos[i].nasc.ano);
                        }
                      }
                      if(qtdprof > 0) {
                        for(j=0;j<qtdprof;j++) {
                          if(mes == prof[j].nasc.mes)
                            printf("%s - %d/%d/%d\n", prof[j].nome, prof[j].nasc.dia, prof[j].nasc.mes, prof[j].nasc.ano);
                        }
                      }
                    }
                    break;
                  }
                  case 2: {
                    if(qtdalunos == 0 && qtdprof == 0) {
                      printf("Nao existe nenhum cadastro de professor e de aluno.\n");
                      break;
                    }
                    else {
                      setbuf(stdin, 0);
                      printf("Buscar uma pessoa por letras:\n");
                      printf("Digite as letras: ");
                      printf("\n");
                      setbuf(stdin, 0);
                      fgets(letrateste, 20, stdin);
                      setbuf(stdin, 0);
                      if(qtdalunos > 0) {
                        for(i=0;i<qtdalunos;i++) { 
                          cont=0;
                          for(j=0;j<strlen(alunos[i].nome);j++) {
                            for(k=0;k<strlen(letrateste);k++) {
                              setbuf(stdin, 0);
                              if(letrateste[k] == alunos[i].nome[j]) {
                                cont++;
                                break;
                              }
                             }
                            }
                            if(cont > 2) { 
                            printf("- %s\n", alunos[i].nome);
                          }
                          }
                        } 
                        if(qtdprof > 0) {
                        for(i=0;i<qtdprof;i++) { 
                          cont=0;
                          for(j=0;j<strlen(prof[i].nome);j++) {
                            for(k=0;k<strlen(letrateste);k++) {
                              setbuf(stdin, 0);
                              if(letrateste[k] == prof[i].nome[j]) {
                                cont++;
                                break;
                              }
                             }
                            }
                            if(cont > 2) { 
                            printf("- %s\n", prof[i].nome);
                            }
                          }
                          break;
                        }
                        break;
                      }
                      break;
                    }
                    case 3: {
                    printf("Saindo do setor de opcoes diversas...\n");
                    break;
                  }
                  default: {
                    printf("Opcao invalida!\n");
                    break;
                  }
                }
            } while(opcaodiversa != 3);
            break;
          }

          case 5: {
            break;
          }
           
          default: {
              printf("Opcao invalida!\n");
              break;
          }
      }
  }while (opcao != 5);
  printf("Finalizando o codigo...\n");
  return 0;
}

//função menu principal
int menuprincipal(int opcao) {
    printf("*****MENU DA ESCOLA*****\n");
    printf("Digite 1 para setor dos alunos:\n");
    printf("Digite 2 para setor dos professores\n");
    printf("Digite 3 para setor das disciplinas:\n");
    printf("Digite 4 para opcoes diversas:\n");
    printf("Digite 5 para finalizar o programa:\n");
    scanf("%d", &opcao); 
    return opcao;
}
//função menu aluno
int menualuno(int opcaoaluno) {
    printf("\n*****MENU DO ALUNO*****\n");
    printf("Digite 1 para cadastrar um aluno:\n");
    printf("Digite 2 para listar os alunos em ordem alfabetica:\n");
    printf("Digite 3 para atualizar um aluno:\n");
    printf("Digite 4 para excluir um aluno:\n");
    printf("Digite 5 para listar os alunos por sexo:\n");
    printf("Digite 6 para listar os alunos por data de nascimento:\n");
    printf("Digite 7 para sair do menu de alunos:\n");
    scanf("%d", &opcaoaluno);
    return opcaoaluno;
}
//função menu professor
int menuprof(int opcaoprof) {
    printf("\n*****MENU DO PROFESSOR*****\n");
    printf("Digite 1 para cadastrar um professor:\n");
    printf("Digite 2 para listar os professores em ordem alfabetica:\n");
    printf("Digite 3 para atualizar um professor:\n");
    printf("Digite 4 para excluir um professor:\n");
    printf("Digite 5 para listar os professores por sexo:\n");
    printf("Digite 6 para listar os professores por data de nascimento:\n");
    printf("Digite 7 para sair do setor de professores:\n");
    scanf("%d", &opcaoprof);
    return opcaoprof;
}
//função menu disciplina
int menudisciplina(int opcaodisc) {
    printf("\n*****MENU DA DISCIPLINA*****\n");
    printf("Digite 1 para cadasatrar uma disciplina nova:\n");
    printf("Digite 2 para atualizar uma disciplina:\n");
    printf("Digite 3 para listar discipinas SEM dados do aluno:\n");
    printf("Digite 4 para adicionar um aluno a uma disciplina:\n");
    printf("Digite 5 para listar discipinas COM dados do aluno\n");
    printf("Digite 6 para listar as disciplinas com mais de 40 alunos:\n");
    printf("Digite 7 para sair do menu de disciplinas:\n");
    scanf("%d", &opcaodisc);
    return opcaodisc; 
}
//função menu opções diversas
int menuopcoesdiversas(int opcaodiversa) {
  printf("Digite 1 para ver os aniversariantes do mes:\n");
  printf("Digite 2 para setor de busca:\n");
  printf("Digite 3 para sair do setor de opcoes diversas:\n");
  scanf("%d", &opcaodiversa);
  return opcaodiversa;
}