#include <stdio.h>
#include <stdlib.h>
int main () {

    int l, c, tam=2, resposta[2][3], mat[2][2], somalinhas=0;

    for(l=0;l<tam;l++) {
        for(c=0;c<tam;c++) {
            printf("posicao[%d][%d]:\n", l, c);
            scanf("%d", &mat[l][c]);
            resposta[l][c] = mat[l][c];
        }
    }
    tam = 3;
    printf("\n");
    for(l=0;l<2;l++) {
        somalinhas=0;
        for(c=0;c<2;c++) {
            somalinhas+=mat[l][c];
        }
        if(somalinhas % 2 == 0){
        resposta[l][2] = 0;
        }
        else {
        resposta[l][2] = 1;
        }
    }
     for(l=0;l<2;l++) {
        for(c=0;c<3;c++) {
            printf("%d ", resposta[l][c]);
        }
        printf("\n");
    }

    return 0;
}