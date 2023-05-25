#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int q4(char *string, char *palavra, int vet[]);
void testeQ4();
int main() {
    testeQ4();
    return 0;
}
void testeQ4() {
    char string[250], palavra[20];
    int posicao[50], i;
    //inicialização do vetor de posicoes
    for(i=0;i<50;i++) {
        posicao[i] = -1;
    }
    //Tteste I
    strcpy(string,"Programar é legal?");
    strcpy(palavra,"sim");
    printf("%d\n",q4(string, palavra, posicao) == 0);
    printf("\n");
    //Teste II
    strcpy(string, "ããããee");
    strcpy(palavra, "ee");
    printf("%d\n", q4(string, palavra, posicao)== 1);
    printf("%d\n",posicao[0]==5);
    printf("%d\n",posicao[1]==6);
    printf("\n");
    //Teste III
    strcpy(string, "welcome to freecodecamp");
    strcpy(palavra, "co");
    printf("%d\n", q4(string, palavra, posicao)== 2);
    printf("%d\n",posicao[0]==4);
    printf("%d\n",posicao[1]==5);
    printf("%d\n",posicao[2]==16);
    printf("%d\n",posicao[3]==17);
    printf("\n");
    //Teste V
    strcpy(string, "7777777");
    strcpy(palavra, "77");
    printf("%d\n", q4(string, palavra, posicao)== 3);
    printf("%d\n",posicao[0]==1);
    printf("%d\n",posicao[1]==2);
    printf("%d\n",posicao[2]==3);
    printf("%d\n",posicao[3]==4);
    printf("%d\n",posicao[4]==5);
    printf("%d\n",posicao[5]==6);
    
    printf("\n");
    //Teste IV
    strcpy(string, "o avião é da nicarágua");
    strcpy(palavra, "ca");
    printf("%d\n", q4(string, palavra, posicao)== 1);
    printf("%d\n",posicao[0]==16);
    printf("%d\n",posicao[1]==17);
    printf("\n");
    //Teste V
    strcpy(string, "êu aámo você minhaa lindaa");
    strcpy(palavra, "aa");
    printf("%d\n", q4(string, palavra, posicao)== 3);
    printf("%d\n",posicao[0]==4);
    printf("%d\n",posicao[1]==5);
    printf("%d\n",posicao[2]==18);
    printf("%d\n",posicao[3]==19);
    printf("%d\n",posicao[4]==25);
    printf("%d\n",posicao[5]==26);
    printf("\n");
    //for(i=0;posicao[i] != -1; i++) {
    //    printf("Posicao: %d\n", posicao[i]);
    //}
}
int q4(char *string, char *palavra, int vet[]) {
    int i=0, j=0, cont=0, posicaostr=0, posvetor=0, ocorrencias=0;
    while(string[i] != '\0') {
        setbuf(stdin, 0);
        if(string[i] != -61) {
            string[j] = string[i];
            j++;
        } 
        i++;
    }

    string[j] = '\0';
    
    for(i=0;i<strlen(string);++i) {
        setbuf(stdin, 0);
        j=0;
        if(string[i] == palavra[j]) {
            cont=0;
            posicaostr = i;
            for(j=0;j<strlen(palavra);j++) {
                if(string[posicaostr] == palavra[j]) {
                    posicaostr++;
                    cont++;
                }
                if(cont == strlen(palavra)) {
                    i++;
                    ocorrencias++;
                    vet[posvetor] = i;
                    ++posvetor;
                    vet[posvetor] = posicaostr;
                    ++posvetor;
                    vet[posvetor] = -1;
                }
            }
        }
    }
    return ocorrencias;
}
