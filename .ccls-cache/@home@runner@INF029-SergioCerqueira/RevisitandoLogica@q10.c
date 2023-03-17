// Faça um programa que leia os dados de nome, idade, sexo e cpf de 5 pessoas.
// Ao final imprima tudo. Utilize vetor e struct.
#include <stdio.h>
int main() {
  int i;
  struct ficha {
    char nome[50];
    int idade;
    char sexo; //'M' -> masculino e 'F' -> feminino
    int cpf;   // Somente os numeros do cpf
  } pessoa[5];

  for (i = 0; i < 5; i++) { // procedimento para a coleta dos dados do vetor de structs
    printf("Informe o seu nome:\n");
    fgets(pessoa[i].nome, 49, stdin);
    fflush(stdin);
    printf("Informe a sua idade:\n");
    scanf("%d", &pessoa[i].idade);
    fflush(stdin);
    printf("Informe o seu sexo com M ou F:\n");
    scanf("%c", &pessoa[i].sexo);
    fflush(stdin);
    printf("Informe o seu cpf somente com numeros:\n");
    scanf("%d", &pessoa[i].cpf);
    fflush(stdin);
  }
  for (i = 0; i < 5; i++) {
    printf("*****Pessoa %d*****", i);
    printf("Nome: %s", pessoa[i].nome);
    printf("Idade: %d", pessoa[i].nome);
    printf("Sexo: %c", pessoa[i].sexo);
    printf("CPF: %d", pessoa[i].cpf);
  }
  return 0;
}