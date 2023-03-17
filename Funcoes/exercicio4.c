// Função que lê 3 numeros
#include <stdio.h>
#include <stdlib.h>
int ler3num();
int main() {
  int a[3], i;
  for (i = 0; i < 3; i++) {
    a[i] = ler3num();
  }
  for (i = 0; i < 3; i++) {
    printf("%d\n", a[i]);
  }
}
int ler3num() {
  int a[3], i;
  for (i = 0; i < 3; i++) {
    printf("Informe o valor %d: ", i + 1);
    scanf("%d", &a[i]);
    return a[i];
  }
}