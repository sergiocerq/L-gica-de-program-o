//
#include <stdio.h>
int main () {
  int x, i, total;
  printf("Informe um numero:\n");
  scanf("%d", &x);
  i=x-1;
  for(total=x;i>0;i--) {
    total*=i;
  }
  printf("Total: %d", total);
  return 0;
}