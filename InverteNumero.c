//Pega um número e o inverte
#include <stdio.h>
#include <stdlib.h>
void teste();
int inverteNumero(int num);
int main() {
    teste();
    return 0;
}
void teste() {
    //Possui 10 testes
    printf("%d\n",inverteNumero(345) == 543);
    printf("%d\n",inverteNumero(78) == 87);
    printf("%d\n",inverteNumero(3) == 3);
    printf("%d\n",inverteNumero(5430) == 345);
    printf("%d\n",inverteNumero(1000) == 1);
    printf("%d\n",inverteNumero(0) == 0);
    printf("%d\n",inverteNumero(707) == 707);
    printf("%d\n",inverteNumero(80) == 8);
    printf("%d\n",inverteNumero(8) == 8);
    printf("%d\n",inverteNumero(1234) == 4321);
}
int inverteNumero(int num) {
    int resposta=0, i, numeros[11];
    if(num < 0) {
        num*=-1;
    }
    //Quebrando o numero e o armazenando invertido
    for(i=0; num != 0;i++) {
        numeros[i] = num % 10;
        num = num / 10;
    }
    --i;//Decrementa o i para que ele fique exatamente na posição do ultimo numero
    int multiplicador=1;//variável para multiplicar pela casa decimal em que se encontra
    while(i>=0) {
        resposta+=numeros[i] * multiplicador;
        multiplicador*=10;
        --i;
    }
    return resposta;
}