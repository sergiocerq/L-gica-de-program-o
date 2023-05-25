//verifica quantas vezes um determinado caracter aparece em uma string
//pode ser case sensitive ou não
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
void testeAutomatizado();
int buscaLetra(char *string, char letra, int sensitivecase);
int contacaracter(char *string, char letra, int sensitivecase);
int main() {
    testeAutomatizado();
    return 0;
}   
void testeAutomatizado() {
    char string[250];
    //Teste I
    strcpy(string, "FLaMENgo é cAMPEão da LiBeRtaDORes!");
    printf("%d\n",buscaLetra(string, 'ã', 0) == 1);
    printf("%d\n",buscaLetra(string, 'é', 1) == 1);
    printf("%d\n",buscaLetra(string, 'o', 0) == 3);
    printf("%d\n",buscaLetra(string, 'E', 1) == 2);
    printf("%d\n",buscaLetra(string, 'F', 1) == 1);
    printf("\n");
    //Teste II
    strcpy(string,"Letícia, signifiCa fEliCIdADE");
    printf("%d\n",buscaLetra(string, 'c', 0) == 3);
    printf("%d\n",buscaLetra(string, 'C', 0) == 3);
    printf("%d\n",buscaLetra(string, 'c', 1) == 1);
    printf("%d\n",buscaLetra(string, 'C', 1) == 2);
    printf("%d\n",buscaLetra(string, 'R', 0) == 0);
    printf("%d\n",buscaLetra(string, 'e', 0) == 3);
    printf("%d\n",buscaLetra(string, 'E', 1) == 2);
    printf("%d\n",buscaLetra(string, 'S', 1) == 0);
}
int buscaLetra(char *string, char letra, int sensitivecase) {
    //chamada para a função que vai contar os caracteres
    int qtdocorrencias = contacaracter(string, letra, sensitivecase);
    
    return qtdocorrencias;
}
int contacaracter(char *string, char letra, int sensitivecase) {
    int i, qtdocorrencias = 0;
    //caso o usuário não deseje considerar o case-sensitive, ele entra aqui
    if(sensitivecase != 1) {
        for(i=0; i < strlen(string); i++) {
            if(toupper(string[i]) == toupper(letra)) { 
                //função converte para caracteres maiúsulos, dessa forma, a contagem fica correta
                ++qtdocorrencias;
            }
        }
    } else {
        //caso o usuário deseje considerar o case-sensitive, ele entra aqui
        for(i=0; i < strlen(string); i++) {
            if(string[i] == letra) { 
                ++qtdocorrencias;
            }
        }   
    }
    return qtdocorrencias;
}