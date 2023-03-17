#include <stdio.h>
#include <stdlib.h>
#define TAMALUNO 2
#define TAMPROF 2
#define TAMDIS 2

int main() {

  int opcao, i;
  struct data {
    int dia, mes, ano;
  } nasc;

  struct fichaluno {
    int matricula;
    char nome[50];
    char sexo;
    struct data nasc;
    char cpf[16];
  } alunos[TAMALUNO];

  struct fichaprof {
    int matricula;
    char nome[50];
    char sexo;
    struct data nasc;
    char cpf[16];
  } prof[TAMPROF];

  struct fichadisc {
    char nome[50];
    char codigo[15];
    int semestre; // somente numeros
    char professor[30];
  } disciplinas[TAMDIS];

  do {
    if (opcao == 4) {
      break;
    }
    printf("*****MENU DA ESCOLA*****\n");
    printf("Digite 1 para inserir o aluno:\n");
    printf("Digite 2 para inserir o professor\n");
    printf("Digite 3 para inserir uma disciplina:\n");
    printf("Digite 4 para sair:\n");
    scanf("%d", &opcao);
    fflush(stdin);

    switch (opcao) {
    case 1: {
      printf("*****Menu do Aluno*****\n");

      for (i = 0; i < TAMALUNO; i++) {
        printf("Informe o nome: \n");
        fgets(alunos[i].nome, 50, stdin);
        printf("Informe a matricula: \n");
        scanf("%d", &alunos[i].matricula);
        fflush(stdin);
        printf("Informe o sexo: \n");
        scanf("%c", &alunos[i].sexo);
        fflush(stdin);
        printf("Informe o cpf: \n");
        fgets(alunos[i].cpf, 15, stdin);
        printf("Informe a data de nascimento no formato dd mm aaaa:\n ");
        scanf("%d%d%d", &alunos[i].nasc.dia, &alunos[i].nasc.mes,
              &alunos[i].nasc.ano);
        fflush(stdin);
      }
      break;
    }

    case 2: {
      printf("*****Menu do Professor*****\n");

      for (i = 0; i < TAMPROF; i++) {
        printf("Informe o nome: \n");
        fgets(prof[i].nome, 50, stdin);
        printf("Informe a matricula: \n");
        scanf("%d", &prof[i].matricula);
        fflush(stdin);
        printf("Informe o sexo: \n");
        scanf("%c", &prof[i].sexo);
        fflush(stdin);
        printf("Informe o cpf: \n");
        fgets(prof[i].cpf, 15, stdin);
        printf("Informe a data de nascimento no formato dd mm aaaa: \n");
        scanf("%d%d%d", &prof[i].nasc.dia, &prof[i].nasc.mes,
              &prof[i].nasc.ano);
        fflush(stdin);
      }
      break;
    }

    case 3: {
      printf("*****Menu da Disciplina*****\n");
      break;
    }

    case 4: {
      printf("Saindo do programa...");
      break;
    }

    default: {
      printf("Opção invalida!");
      break;
    }
    }
    while (opcao < 4)
      ;

    return 0;
  }