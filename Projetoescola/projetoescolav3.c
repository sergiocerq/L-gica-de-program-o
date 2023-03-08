//Projeto-escola minha versão III
#include <stdio.h>
#include <stdlib.h>
#define TAMALUNO 2
#define TAMPROF 2
#define TAMDIS 2
int main() { 
  int opcao, i, opcaoaluno;
  struct data {
    int dia, mes, ano;
  }nasc;
  
  struct fichaluno {
    int matricula;
    char nome[50];
    char sexo;
    struct data nasc;
    char cpf[16];
  }alunos[TAMALUNO];
  
  struct fichaprof {
    int matricula;
    char nome[50];
    char sexo;
    struct data nasc;
    char cpf[16];
  }prof[TAMPROF];

  struct fichadisc {
    char nome[50];
    char codigo[15];
    int semestre; //somente numeros
    char professor[30];
  }disciplinas[TAMDIS];

  do {
    if (opcao == 4) {
        break;
    }
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
                fflush(stdin);
                printf("Aluno %d:\n", i+1);
                printf("Informe o nome: ");
                fgets(alunos[i].nome, 50, stdin); 
                do {
                printf("Informe a matricula: ");
                scanf("%d", &alunos[i].matricula); fflush(stdin);
                }while(alunos[i].matricula < 0);  //teste de matrícula

                do {
                printf("Informe o sexo: ");
                scanf("%c", &alunos[i].sexo); fflush(stdin);
                }while(alunos[i].sexo != 'F' && alunos[i].sexo != 'f' && alunos[i].sexo != 'M' && alunos[i].sexo != 'm');
                printf("Informe o cpf: ");
                fgets(alunos[i].cpf, 15, stdin);
                printf("Informe a data de nascimento no formato dd mm aaaa: ");
                scanf("%d%d%d", &alunos[i].nasc.dia, &alunos[i].nasc.mes, &alunos[i].nasc.ano); fflush(stdin);
                printf("\n");
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
            printf("Informe a matricula: ");
            scanf("%d", &prof[i].matricula); fflush(stdin);
            printf("Informe o sexo: ");
            scanf("%c", &prof[i].sexo); fflush(stdin);
            printf("Informe o cpf: ");
            fgets(prof[i].cpf, 15, stdin);
            printf("Informe a data de nascimento no formato dd mm aaaa: ");
            scanf("%d%d%d", &prof[i].nasc.dia, &prof[i].nasc.mes, &prof[i].nasc.ano); fflush(stdin);
            printf("\n");
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