// Função subtrai
#include <stdio.h>
#include <stdlib.h>
int subtrai();
int main() {
  int a, b, c, resultado;
  printf("Informe o primeiro valor: ");
  scanf("%d", &a);
  printf("Informe o segundo valor: ");
  scanf("%d", &b);
  printf("Informe o terceiro valor: ");
  scanf("%d", &c);
  resultado = subtrai(a, b, c);
  printf("resulado: %d", resultado);
  return 0;
}
int subtrai(int a, int b, int c) {
  int resultado;
  resultado = a - b;
  resultado -= c;
  return resultado;
}