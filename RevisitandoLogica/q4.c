//Faça um programa que leia dois valores informados pelo usuário e inverta os valores nas variáveis lidas sem utilizar variável auxiliar
#include <stdio.h>
int main () {
  int x, y;
  printf("Informe o primeiro valor:\n");
  scanf("%d", &x);
  y=x;
  printf("Informe o segundo valor:\n");
  scanf("%d", &x);
  printf("primeiro valor: %d\nsegundo valor: %d\n", x, y);
  return 0;
}