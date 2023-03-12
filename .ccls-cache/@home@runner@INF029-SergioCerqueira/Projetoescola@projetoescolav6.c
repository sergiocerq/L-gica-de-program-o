//Projeto-escola minha versão V
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define TAMALUNO 2 
#define TAMPROF 2 
#define TAMDIS 2 
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
    int matricula;
    char nome[50];
    char sexo;
    struct data nasc; //chamada para struct da data de nascimento
    char cpf[15];
  } fichaprof;

  typedef struct fichadisc{ //struct disciplinas
    char nome[50];
    int codigo;
    int semestre; //somente numeros
    char professor[50];
    fichaluno alunodisc; // chamada para a struct de alunos
  } fichadisc;
  
  //Declaração de funções
  int menuprincipal(int opcao);
  int menualuno(int opcaoaluno);
  int menuprof(int opcaoprof);
  int menudisciplina(int opcaodisc);
  
//Inicialização da função main
int main() { 
  setlocale(LC_ALL, "Portuguese"); //função que permite a acentuação em português
  int opcao, i, opcaoaluno, opcaoprof, opcaodisc, dataerrada=1, qtdalunos=0, qtdprof=0, qtddisc=0, ln, matricula; //declaração de váriaveis auxiliares
  
  fichaluno alunos[TAMALUNO]; // declaração da struct alunos
  fichaprof prof[TAMPROF]; // declaração da struct professor
  fichadisc disciplinas[TAMDIS]; // declaração da struct discipinas
  
  do {
    opcao = menuprincipal(opcao); //chamada da função do menu principal
    switch(opcao) {
     
        case 1: {
          opcaoaluno = menualuno(opcaoaluno); //chamada da função do menu aluno
          switch (opcaoaluno) {
            case 1: {
                printf("*****Cadastro de alunos*****\n");
            if(qtdalunos == TAMALUNO) //teste para bloquear a inserção de alunos acima do limite
                printf("Lista de alunos cheia!");
                else {
                printf("Aluno %d:\n", qtdalunos + 1);
                do {
                    printf("Informe a matricula: ");
                    scanf("%d", &alunos[i].matricula);
                }while(alunos[i].matricula < 0);  //teste de matrícula
                getchar();
                printf("Informe o nome: ");//cadastro do nome do aluno
                fgets(alunos[i].nome, 49, stdin); 
                ln = strlen(alunos[i].nome) - 1; //processo para remoção do '\n' do fgets
                if (alunos[i].nome[ln] == '\n')
                  alunos[i].nome[ln] = '\0';
                do { //cadastro do sexo do aluno (apenas com F ou M)
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
                printf("Informe o cpf corretamente: ");//cadastro de cpf do aluno
                fgets(alunos[i].cpf, 15, stdin);
                ln = strlen(alunos[i].cpf) - 1; //remoção do '\n' do fgets
                if (alunos[i].cpf[ln] == '\n')
                  alunos[i].cpf[ln] = '\0';
                  qtdalunos++;
                  alunos[i].ativo = 1;
                  printf("\n");
              }
              getchar();
            break;
            }
            break;
            case 2: {
                printf("*****Listar alunos*****\n");
                if (qtdalunos == 0) { //teste para verificar se a matrícula existe
                    printf("Nenhum aluno cadastrado!\n");
                    break;
                  }
                else {
                  for(i=0;i<qtdalunos;i++) { //listagem dos alunos sem ordem
                    printf("Aluno %d:\n", i+1);
                    printf("Nome: %s\n", alunos[i].nome );
                    printf("Matricula: %d\n", alunos[i].matricula); 
                    printf("Sexo: %c\n", alunos[i].sexo);
                    printf("CPF: %s\n", alunos[i].cpf);
                    printf("Data de nascimento: %d/%d/%d\n", alunos[i].nasc.dia, alunos[i].nasc.mes, alunos[i].nasc.ano);
                    printf("\n");
                  }           
                }
            break;
            }
            break;

            case 3: {//atualização dos dados de um aluno
                printf("*****Atualizar aluno*****\n");
                printf("Informe a matricula que deseja Atualizar: ");
                scanf("%d", &matricula);
                for(i=0;i<qtdalunos;i++) { //procura para ver se uma matrícula existe
                    int achou=0;
                    if(matricula == alunos[i].matricula) {
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
                    if (alunos[i].cpf[ln] == '\n')
                      alunos[i].cpf[ln] = '\0';
                      alunos[i].ativo = 1;
                      printf("\n");
                    } 
                if(achou == 0) {
                  printf("Aluno não encontrado ou inativo!\n");
                  }
                }
                break;
            }
            break;
            
            case 4: {//exclusão de um aluuno
                printf("*****Excluir aluno*****\n");
                break;
            }

            case 5: {//saída do setor de alunos
                printf("Saindo do setor de alunos...\n");
                break;
            }

            default: {
                printf("Opção inválida!\n");
                break;
            }
          
        } while(opcaoaluno != 5);
        break;
    }
    break;
        case 2: {
        menuprof(opcaoprof);
          switch (opcaoprof) {
            case 1: { //cadastro de professores
                getchar();
                printf("Professor %d\n", i+1);
                printf("Informe o nome: ");
                fgets(prof[i].nome, 50, stdin);
                do {
                  printf("Informe a matricula: ");
                  scanf("%d", &prof[i].matricula); 
                }while(prof[i].matricula<0); 
                getchar();
                do {
                  printf("Informe o sexo com F ou M: ");
                  scanf("%c", &prof[i].sexo); 
                }while(prof[i].sexo != 'F' && prof[i].sexo != 'M' ); 
                getchar();
                printf("Informe o cpf: ");
                fgets(prof[i].cpf, 15, stdin);
                do {
                    dataerrada=0;
                    printf("Informe a data de nascimento no formato dd mm aaaa: ");
                    scanf("%d%d%d", &prof[i].nasc.dia, &prof[i].nasc.mes, &prof[i].nasc.ano); 
                    if(prof[i].nasc.dia > 31 || prof[i].nasc.mes > 12 || prof[i].nasc.ano > 2023 || prof[i].nasc.ano < 1920)
                        dataerrada++;
                    printf("\n");
                }while(dataerrada > 0); 
                qtdprof++;
                break;
            }
            break;

            case 2: {//listar professores
              for(i=0;i<qtddisc;i++) {
                printf("Nome: %s\n", prof[i].nome );
                printf("Matricula: %d\n", prof[i].matricula); 
                printf("Sexo: %c\n", prof[i].sexo);
                printf("CPF: %s\n", prof[i].cpf);
                printf("Data de nascimento: %d/%d/%d\n", prof[i].nasc.dia, prof[i].nasc.mes, prof[i].nasc.ano);
                printf("\n");  
              }
            }
            break;
        }
        
        break;
        }
        break;
        case 3: {//disciplinas
            do {
            getchar();
            opcaodisc = menudisciplina(opcaodisc);
            switch (opcaodisc) {
                case 1: {
                     //cadastro de disciplinas
                  if(qtddisc == TAMDIS) {
                      printf("Lista de discipinas cheia!");
                      break;
                  }
                  else {
                    do {
                      printf("Informe o codigo da disciplina: ");
                      scanf("%d", &disciplinas[qtddisc].codigo);
                    }while(disciplinas[qtddisc].codigo < 0);  //teste de codigo da discipina
                    getchar();
                    printf("Informe o nome do professor: "); //nome do professor
                    fgets(disciplinas[qtddisc].professor, 49, stdin); 
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
                    qtddisc++;
                    getchar();
                  }
                  break;
                }
                break;
                case 2: {//inserção/exclusão de um aluno de uma disciplina
                    break;
                  }
                
                case 3: { //listagem das discipinas if(qtddisc == 0)
                    if(qtddisc == 0)
                      printf("Não existe nenhum cadastro de disciplinas!\n");
                    else {
                        for(i=0;i<qtddisc;i++) { //listagem dos alunos sem ordem
                            printf("Disciplina %d:\n", i+1);
                            printf("Nome da discipina: %s\n", disciplinas[qtddisc].nome);
                            printf("Codigo: %d\n", disciplinas[i].codigo); 
                            printf("Nome do professor: %s\n", disciplinas[qtddisc].professor);
                            printf("Semestre: %d\n", disciplinas[qtddisc].codigo);
                            printf("\n");
                            getchar();
                          }
                    }
                    
                }
                break;

               case 4: {//saída do setor de disciplinas
               printf("Saindo do setor de disciplinas...\n");
               break;
               }
                
                default: {
                printf("Opção inválida!\n");
                break;
                }
            }
        }while(opcaodisc < 4);
        break;
      }
      break;
    }
  printf("Saindo do programa...\n");
}while (opcao < 4);
 return 0;
}

//função menu principal
int menuprincipal(int opcao) {
    printf("*****MENU DA ESCOLA*****\n");
    printf("Digite 1 para setor dos alunos:\n");
    printf("Digite 2 para setor dos professores\n");
    printf("Digite 3 para setor das disciplinas:\n");
    printf("Digite 4 para sair do programa:\n");
    scanf("%d", &opcao); 
    return opcao;
}
//função menu aluno
int menualuno(int opcaoaluno) {
    printf("*****MENU DO ALUNO*****\n");
    printf("Digite 1 para cadastrar um aluno:\n");
    printf("Digite 2 para listar um aluno:\n");
    printf("Digite 3 para atualizar um aluno:\n");
    printf("Digite 4 para excluir um aluno:\n");
    printf("Digite 5 para sair do menu de alunos:\n");
    scanf("%d", &opcaoaluno);
    return opcaoaluno;
}
//função menu professor
int menuprof(int opcaoprof) {
   printf("*****MENU DO PROFESSOR*****\n");
    printf("Digite 1 para cadastrar um professor:\n");
    printf("Digite 2 para listar um professor:\n");
    printf("Digite 3 para atualizar um professor:\n");
    printf("Digite 4 para excluir um professor:\n");
    printf("Digite 5 para sair do setor de professores:\n");
    scanf("%d", &opcaoprof);
    return opcaoprof;
}
//função menu disciplina
int menudisciplina(int opcaodisc) {
    printf("*****MENU DA DISCIPLINA*****\n");
    printf("Digite 1 para cadasatrar uma disciplina nova:\n");
    printf("Digite 2 para inserir/excluir um aluno de uma disciplina:\n");
    printf("Digite 3 para seção de listagem das discipinas:\n");
    printf("Digite 4 para sair do menu de disciplinas:\n");
    scanf("%d", &opcaodisc);
    return opcaodisc; 
}