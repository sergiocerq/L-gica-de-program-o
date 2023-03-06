//Faça um programa que leia dois valores informados pelo usuário e inverta os valores nas variáveis lidas
#include <stdio.h>
int main () {
  int x, y, z;
    printf("Informe um numero x:\n");
    scanf("%d", &x);
    printf("Informe um numero y:\n");
    scanf("%d", &y);
    z=x;
    x=y;
    y=z;
    printf("Numero x: %d\nNumero y: %d\n", x, y);
  return 0;
}