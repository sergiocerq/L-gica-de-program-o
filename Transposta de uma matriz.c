//Transposta de uma matriz
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main () {
//Declaração de variáveis e da função srand
    int i, tam=3, j, matriz[tam][tam], tra[tam][tam];
    srand(time(NULL));//Função que gera valores aleatórios 

    for(i=0;i<tam;i++) {
        for(j=0;j<tam;j++) {
            matriz[i][j]= rand() % 100;
        }
    }
    printf("\n\n");
    for(i=0;i<tam;i++) {
        for(j=0;j<tam;j++) {
            tra[i][j] = matriz[j][i];
        }
    }
    printf("\n");
    for(i=0;i<tam;i++) {
        for(j=0;j<tam;j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

printf("\n");
    for(i=0;i<tam;i++) {
        for(j=0;j<tam;j++) {
            printf("%d ", tra[i][j]);
        }
        printf("\n");
    }

    return 0;
}