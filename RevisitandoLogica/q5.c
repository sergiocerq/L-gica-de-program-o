//Faça um programa que leia a idade de uma pessoa e informe de ela é de maior ou menor
#include <stdio.h>
int main () {
  int x;
  printf("Informe a sua idade:\n");
  scanf("%d", &x);
  if(x>=18)
    printf("Maior de idade!");
  else
    printf("Nao e maior de idade!");
  
  return 0;
}