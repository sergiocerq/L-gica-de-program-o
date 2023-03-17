#include <stdio.h>
int fatorial();

int main() {
  int numero, resultado;
  printf("Informe um numero para caluclar o fatorial:\n");
  scanf("%d", &numero);
  resultado = fatorial(numero);
  if (resultado < 0)
    printf("n foi possivel calcular o fatorial");
  else
    printf("Resultado: %d", resultado);
  return 0;
}
int fatorial(int numero) {
  int i, resultado = 0;
  if (numero <= 0)
    return -1;
  else {
    for (i = numero - 1, resultado = numero; i >= 1; i--) {
      resultado *= i;
    }
    return resultado;
  }
}