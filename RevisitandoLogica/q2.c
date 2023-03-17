// Faça um programa que leia a idade de duas pessoas e imprima a soma das idades
#include <stdio.h>
int main() {
  int x, y;
  printf("Informe a primeira idade:\n");
  scanf("%d", &x);
  printf("Informe a segunda idade:\n");
  scanf("%d", &y);
  x += y;
  printf("Soma das idades: %d", x);
  return 0;
}