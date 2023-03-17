#include <stdio.h>
#include <stdlib.h>
int main() {

  struct data {
    int dia;
    int mes;
    int ano;
  } nasc;

  struct fichaluno {
    int matricula;
    char nome[50];
    char sexo;
    data nasc;
    int cpf; // somente numeros
  } alunos[200];

  struct fichaprof {
    int matricula;
    char nome[50];
    char sexo;
    data nasc;
    int cpf; // somente numeros
  } prof[100];

  struct fichadisc {
    char nome[50];
    char codigo[15];
    int semestre; // somente numeros
    char professor[30];
  } disciplinas[20];

  int opcao;

  do {
    printf("*****MENU DA ESCOLA*****\n");
    printf("Digite 1 para aluno:\n");
    printf("Digite 2 para professor\n;");
    printf("Digite 3 para disciplina:\n");
    printf("Digite 4 para sair:\n");
    scanf("%d", &opcao);
  } while (opcao < 4);

  return 0;
}