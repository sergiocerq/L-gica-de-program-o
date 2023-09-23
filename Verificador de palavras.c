//Verificar se as palavras digitadas são iguais sem usar a biblioteca <string.h>
#include <stdio.h>
#include <stdlib.h>
int main () {
//Declaração de variaveis, strings e atribuição dos seus respectivos valores
    int i=0, j, contador=0;
    char palavra1[30], palavra2[30];
       printf("Informe a primeira palavra:\n");
    fgets(palavra1, 30, stdin);
    printf("Informe a segunda palavra:\n");
    fgets(palavra2, 30, stdin);
//Verificação se as strings são iguais posição por posição
    while (palavra1[i] != '\0') {
        if (palavra1[i] >= 'a' && palavra1[i] <= 'z') {
        palavra1[i] = palavra1[i] - 32; }
        if (palavra2[i] >= 'a' && palavra2[i] <= 'z') {
        palavra2[i] = palavra2[i] - 32; }
        i++;
    }
    for(j=0;j<i;j++) {
        if (palavra1[j] != palavra2[j]) {
        contador++; }
    }
//Resposta
    if (contador == 0)
    printf("Palavras iguais!\n");
    else
    printf("Palavras diferentes!\n");
    return 0;
}