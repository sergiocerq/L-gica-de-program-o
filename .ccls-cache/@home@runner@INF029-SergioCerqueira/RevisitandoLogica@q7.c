//Faça um programa que verifique se um número é primo
#include <stdio.h>
int main () {
  int x, i, cont;
  printf("Informe um numero:\n");
  scanf("%d", &x);

  for(i=1;i<x;i++) {
    if (x % i == 0)
      cont++;
  }
  if (cont >1)
    printf("Nao e primo");
  else
    printf("E primo!");
  
  return 0;
}