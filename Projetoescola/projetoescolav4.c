//Projeto-escola minha versão IV
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAMALUNO 2
#define TAMPROF 2
#define TAMDIS 2
int main() { 
  int opcao, i, opcaoaluno, dataerrada=1;
  
  struct data {
    int dia, mes, ano;
  } nasc;
  
  struct fichaluno {
    int matricula;
    char nome[50];
    char sexo; // M ou m -> masculino e F ou f -> feminino
    struct data nasc;
    char cpf[15];
  } alunos[TAMALUNO];
  
  struct fichaprof {
    int matricula;
    char nome[50];
    char sexo;
    struct data nasc;
    char cpf[15];
  } prof[TAMPROF];

  struct fichadisc {
    char nome[50];
    char codigo[15];
    int semestre; //somente numeros
    char professor[30];
  } disciplinas[TAMDIS];

  do {
    if (opcao == 4) 
      break;
    
    printf("*****MENU DA ESCOLA*****\n");
    printf("Digite 1 para setor dos alunos:\n");
    printf("Digite 2 para setor dos professores\n");
    printf("Digite 3 para setor das disciplinas:\n");
    printf("Digite 4 para sair:\n");
    scanf("%d", &opcao); fflush(stdin);
  
    switch(opcao) {
      do {
        case 1: 
        printf("*****Menu do Aluno*****\n");
        printf("Digite 1 para cadastrar um aluno:\n");
        printf("Digite 2 para listar um aluno:\n");
        printf("Digite 3 para atualizar um aluno:\n");
        printf("Digite 4 para excluir um aluno:\n");
        printf("Digite 5 para sair:\n");
        scanf("%d", &opcaoaluno);

          switch (opcaoaluno) {
            case 1: 
            printf("*****Cadastro de alunos*****\n");
              for(i=0;i<TAMALUNO;i++) {
            printf("Aluno %d:\n", i+1);
                fflush(stdin);
                 do {
                printf("Informe a matricula: ");
                scanf("%d", &alunos[i].matricula); fflush(stdin);
                }while(alunos[i].matricula < 0);  //teste de matrícula
                getchar();
                printf("Informe o nome: ");
                fgets(alunos[i].nome, 50, stdin); 
                int ln = strlen(alunos[i].nome) - 1; 
                if (alunos[i].nome[ln] == '\n')
                  alunos[i].nome[ln] = '\0';
                do {
                printf("Informe o sexo: ");
                scanf("%c", &alunos[i].sexo); fflush(stdin);
                }while(alunos[i].sexo != 'F' && alunos[i].sexo != 'f' && alunos[i].sexo != 'M' && alunos[i].sexo != 'm');
                getchar();
                do {
                printf("Informe o cpf corretamente: ");
                fgets(alunos[i].cpf, 15, stdin);
                }while(alunos[i].cpf[3] != '.' && alunos[i].cpf[7] != '.' && alunos[i].cpf[11] !='-');

                do {
                    dataerrada=0;
                    printf("Informe a data de nascimento no formato dd mm aaaa: ");
                    scanf("%d%d%d", &alunos[i].nasc.dia, &alunos[i].nasc.mes, &alunos[i].nasc.ano); fflush(stdin);
                    printf("\n");
                    if(alunos[i].nasc.dia > 32 || alunos[i].nasc.mes > 12 || alunos[i].nasc.ano > 2022 || alunos[i].nasc.ano < 1930)
                    dataerrada++;
                }while(dataerrada > 0);
              }
            break;

            case 2: 
            printf("*****Listar aluno*****\n");
              for(i=0;i<TAMALUNO;i++) {
                printf("Aluno %d:\n", i+1);
                printf("Nome: %s\n", alunos[i].nome );
                fflush(stdin);
                printf("Matricula: %d\n", alunos[i].matricula); 
                fflush(stdin);
                printf("Sexo: %c\n", alunos[i].sexo);
                fflush(stdin);
                printf("CPF: %s\n", alunos[i].cpf);
                fflush(stdin);
                printf("Data de nascimento: %d/%d/%d\n", alunos[i].nasc.dia, alunos[i].nasc.mes, alunos[i].nasc.ano);
                fflush(stdin);
                printf("\n");
              }           
            break;

            case 3: 
            printf("*****Atualizar aluno*****\n");
            break;

            case 4: 
            printf("*****Excluir aluno*****\n");
            break;

            case 5: 
            printf("Saindo do setor de alunos...\n");
            break;

            default: 
            printf("Opção inválida!\n");
            break;
          }
        } while(opcaoaluno != 5);
        break;
        
        case 2: 
        printf("*****Menu do Professor*****\n");

        for(i=0;i<TAMPROF;i++) {
            printf("Informe o nome: ");
            fgets(prof[i].nome, 50, stdin);
            do {
            printf("Informe a matricula: ");
            scanf("%d", &prof[i].matricula); fflush(stdin);
            }while(prof[i].matricula<0); fflush(stdin);
          
            do {
            printf("Informe o sexo: ");
            scanf("%c", &prof[i].sexo); fflush(stdin);
              }while(prof[i].sexo != 'F' && prof[i].sexo != 'f' && prof[i].sexo != 'm' && prof[i].sexo != 'M' ); fflush(stdin);
            printf("Informe o cpf: ");
            fgets(prof[i].cpf, 15, stdin);
            
            do {
            dataerrada=0;
            printf("Informe a data de nascimento no formato dd mm aaaa: ");
            scanf("%d%d%d", &prof[i].nasc.dia, &prof[i].nasc.mes, &prof[i].nasc.ano); fflush(stdin);
            if(prof[i].nasc.dia > 31 || prof[i].nasc.mes > 12 || prof[i].nasc.ano > 2020)
            dataerrada++;
            printf("\n");
            }while(dataerrada > 0); 
        }
        break;
        
        case 3: 
        printf("*****Menu da Disciplina*****\n");
        break;

        case 4: 
        printf("Saindo do programa...");
        break;

        default: 
        printf("Opcao invalida!");
        break;
    }
  }while(opcao !=  4);
  return 0;
}