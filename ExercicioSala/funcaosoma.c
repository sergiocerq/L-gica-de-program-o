#include <stdio.h>
int funcaosoma();
int main () {
  int resultado;
  restultado = funcaosoma();
  return 0;
}

int funcaosoma() {
  int a, b, result;
  printf("Informe o primeiro valor: ");
  scanf("%d", &a);
  printf("\nInforme o segundo valor: ");
  scanf("%d", &b);

  resultado = a+b;

  return resultado;
  
}