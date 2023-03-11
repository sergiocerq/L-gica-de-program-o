#include <stdio.h>
#include <stdlib.h>
int main () {
/* Questão 91
    int i, j, matriz[2][2], somalinhas[] = {0,0}, somacolunas[] = {0,0};

    for(i=0;i<2;i++) {
        for(j=0;j<2;j++) {
            printf("Informe o numero [%d][%d]:\n", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
    for(i=0;i<2;i++) {
        for(j=0; j<2;j++) {
            somalinhas[i] += matriz[i][j]; 
            somacolunas[i] += matriz[j][i];
        }
        printf("Soma da linha %d: %d\n", i+1, somalinhas[i]);     
        printf("Soma das colunas: %d\n", somacolunas[i]);   
 }*/
/* Questão 92
    int i, j, matriz[3][3], igual=0;
    for(i=0;i<3;i++) {
        for(j=0;j<3;j++) {
            printf("Informe o conteudo da matriz na posicao[%d][%d]:\n", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
    j=1;
    for(i=1;i<3;i++) {
        if (matriz[i][j-1] == matriz[i-1][j]) {
        igual++; }
        j++;
        }
    if(igual==2)
    printf("A matriz e simetrica\n");*/
/* Questão 93
int i, j, matriz[5][5], dp=0, ds=0;
    for(i=0;i<5;i++) {
        for(j=0;j<5;j++) {
            printf("Informe o conteudo da matriz na posicao[%d][%d]:\n", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
    j=0;
    for(i=0;i<5;i++) {
        dp+=matriz[i][j];
        j++;
    }
    printf("Soma da diagonal principal: %d\n", dp);
    j=4;
    for(i=0;i<5;i++) {
        ds+=matriz[i][j];
        j--;
    }
    printf("Soma da diagonal secundaria: %d\n", ds); */
/* Questão 94
    int i, j, matriz[6][6], n;
    printf("Informe o numero para realizar a multiplicacao:\n");
    scanf("%d", &n);
    for(i=0;i<6;i++) {
        for(j=0;j<6;j++) {
            printf("Informe o numero da matriz na posicao[%d][%d]:\n", i, j);
            scanf("%d", &matriz[i][j]);
            matriz[i][j] *= n;
            printf("Posicao[%d][%d]: %d\n", i, j, matriz[i][j]);
        }
    } */
/* Questão 95
int i, j, matriz[2][2], copia, menor;
    for(i=0;i<2;i++) {
        for(j=0;j<2;j++) {
            printf("Informe o conteudo da matriz na posicao[%d][%d]:\n", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
    menor = matriz[0][0];
    for(i=0;i<1;i++) {
        for(j=0;j<1;j++) {
            if(matriz[i+1][j+1] < menor) {
                copia = matriz[i][j];
                matriz[i][j] = menor;
                matriz[i+1][j+1] = copia;
            }
        }
    }
    for(i=0;i<2;i++) {
        for(j=0;j<2;j++)
        printf("Posicao[%d][%d]: %d\n", i, j, matriz[i][j]);
    } */
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