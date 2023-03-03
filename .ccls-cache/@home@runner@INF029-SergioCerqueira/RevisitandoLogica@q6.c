//Faça um programa que leia a idade de uma pessoa e informe de ela é de maior ou de menor. O programa deve repetir essa ação até que uma idade negativa seja informada
#include <stdio.h>
int main () {
  int x;
  do {
  printf("Informe a idade:\n");
  scanf("%d", &x);
    if(x>=18)
      printf("Maior de idade!\n");
    else
      printf("Menor de idade!\n");
  }while(x >= 0);

  return 0;
}