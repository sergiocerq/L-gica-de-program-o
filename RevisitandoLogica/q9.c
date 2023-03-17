// Faça um programa que leia 10 números do usuário e informe quais deles são
// primos. Além disso, mostre a soma de todos os números primos existentes.
#include <stdio.h>
int main() {
  int x[10], i, j, cont, total = 0;
  for (i = 0; i < 10; i++) {
    printf("Informe um numero:\n");
    scanf("%d", &x[i]);
  }
  for (j = 0; j < 10; j++) {
    cont = 0;
    for (i = 1; i < x[j]; i++) {
      if (x[j] % i == 0)
        cont++;
    }
    if (cont > 1)
      printf("Nao e primo\n");
    else {
      printf("E primo!\n");
      total += x[j];
    }
  }
  printf("Total dos numeros primos: %d\n", total);
  return 0;
}