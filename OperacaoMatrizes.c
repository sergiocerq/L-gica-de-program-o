//Soma e subtração com matrizes
#include <stdio.h>
#include <stdlib.h>
int main () {
    int i, j, matriz1[2][2], matriz2[2][2], soma[2][2], dif[2][2];

    for(i=0;i<2;i++) {
        for(j=0;j<2;j++) {
            printf("Informe o conteudo da matriz 1 na posicao[%d][%d]:\n", i, j);
            scanf("%d", &matriz1[i][j]);
            printf("Informe o conteudo da matriz 2 na posicao[%d][%d]:\n", i, j);
            scanf("%d", &matriz2[i][j]);
            soma[i][j] = matriz1[i][j] + matriz2[i][j];
            dif[i][j] = matriz1[i][j] - matriz2[i][j];
        }
    }
    printf("Matriz 1:\n");
    for(i=0;i<2;i++) {
        for(j=0;j<2;j++) {
            printf(" %d ", matriz1[i][j]);
        }
        printf("\n");
    }
    printf("Matriz 2:\n");
    for(i=0;i<2;i++) {
        for(j=0;j<2;j++) {
            printf(" %d ", matriz2[i][j]);
        }
        printf("\n");
    }
    printf("Matriz soma:\n");
    for(i=0;i<2;i++) {
        for(j=0;j<2;j++) {
            printf(" %d ", soma[i][j]);
        }
        printf("\n");
    }
    printf("Matriz diferenca:\n");
    for(i=0;i<2;i++) {
        for(j=0;j<2;j++) {
            printf(" %d ", dif[i][j]);
        }
        printf("\n");
    }
    

    return 0;
}
