#include <stdio.h>
#include <stdlib.h>
void mudaVariavel(int *pA,int *pB);
int main(){
  int a, b;
  printf("Informe o valor de a:\n");
  scanf("%d", &a);
  printf("Informe o valor de b:\n");
  scanf("%d", &b);
  
  int *pA, *pB;
  pA = &a;
  pB = &b;
  
  mudaVariavel(pA, pB);

  printf("Valor de a: %d\n", a);
  printf("Valor de b: %d\n", b);
  return 0;
}
void mudaVariavel(int *pA,int *pB) {
  int c;
  c = *pA;
  *pA = *pB;
  *pB = c;
}