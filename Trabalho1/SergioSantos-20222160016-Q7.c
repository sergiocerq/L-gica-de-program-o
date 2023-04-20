//Jogo da velha implementado na lingugagem c
#include <stdio.h>
#include <stdlib.h>
void imprimejogo(char jogo[][3]);
void partidas(char jogo[][3]);
int verificavencedor(char jogo[][3]);
int verificacelula(char *linha1, int coluna);
int main() {
    char jogo[3][3] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    partidas(jogo);
    return 0;
}
void imprimejogo(char jogo[][3]) {
    printf("  1   2   3\n");
    printf("a %c | %c | %c\n", jogo[0][0], jogo[0][1], jogo[0][2]);
    printf(" -----------\n");
    printf("b %c | %c | %c\n", jogo[1][0], jogo[1][1], jogo[1][2]);
    printf(" -----------\n");
    printf("c %c | %c | %c\n\n", jogo[2][0], jogo[2][1], jogo[2][2]);
}
void partidas(char jogo[][3]) {
    int retorno = -3, celulaerrada;
    int rodadas=0, jogador = 1;
    char linha1[2];
    int coluna, linha;
        imprimejogo(jogo);
        while(rodadas < 9) {
            do{
                setbuf(stdin, 0);
                printf("Jogador %d, informe a sua jogada:\n", jogador);
                puts("Informe a coluna em que deseja jogar");
                scanf("%d", &coluna); 
                setbuf(stdin, 0);
                puts("Informe a linha em que deseja jogar");
                fgets(linha1, 2, stdin);
                celulaerrada = verificacelula(linha1, coluna);
                
                if(linha1[0] == 'a' || linha1[0] == 'A') {
                    linha = 0;
                } else if(linha1[0] == 'b' || linha1[0] == 'B') {
                    linha = 1;
                } else if(linha1[0] == 'c' || linha1[0] == 'C') {
                    linha = 2;
                }
                setbuf(stdin, 0);
            }while(celulaerrada > 0);
            coluna--;
            if(jogo[linha][coluna] == ' ') {
                if(rodadas % 2 == 0)
                    jogo[linha][coluna] = 'X';
                else
                    jogo[linha][coluna] = '0';
            }
            imprimejogo(jogo);
            rodadas++;
            if(rodadas > 2) {
                retorno = verificavencedor(jogo);
                if(retorno > 0) {
                    break;
                }
            }
            if(jogador == 1 && celulaerrada == 0) 
                jogador = 2;
            else 
                jogador = 1;
        }
    if(retorno == 0) {
        puts("Empate.");
    }
    puts("Fim de jogo.");
}
int verificavencedor(char jogo[][3]) {
    //verifica as colunas
    if((jogo[0][0] == 'X' && jogo[0][1] == 'X' && jogo[0][2] == 'X') ||
       (jogo[0][0] == '0' && jogo[0][1] == '0' && jogo[0][2] == '0')) {
        printf("Jogador %c venceu!\n", jogo[0][1]);
        return 1;
    }
    if((jogo[1][0] == 'X' && jogo[1][1] == 'X' && jogo[1][2] == 'X') ||
       (jogo[1][0] == '0' && jogo[1][1] == '0' && jogo[1][2] == '0')) {
        printf("Jogador %c venceu!\n", jogo[1][1]);
        return 1;
    }
    if((jogo[2][0] == 'X' && jogo[2][1] == 'X' && jogo[2][2] == 'X') ||
       (jogo[2][0] == '0' && jogo[2][1] == '0' && jogo[2][2] == '0')) {
        printf("Jogador %c venceu!\n", jogo[2][1]);
        return 1;
    }
    //verifica as linhas
    if((jogo[0][0] == 'X' && jogo[1][0] == 'X' && jogo[2][0] == 'X') ||
       (jogo[0][0] == '0' && jogo[1][0] == '0' && jogo[2][0] == '0')) {
        printf("Jogador %c venceu!\n", jogo[2][0]);
        return 1;
    }
    if((jogo[0][1] == 'X' && jogo[1][1] == 'X' && jogo[2][1] == 'X') ||
       (jogo[0][1] == '0' && jogo[1][1] == '0' && jogo[2][1] == '0')) {
        printf("Jogador %c venceu!\n", jogo[2][1]);
        return 1;
    }
    if((jogo[0][2] == 'X' && jogo[1][2] == 'X' && jogo[2][2] == 'X') ||
       (jogo[0][2] == '0' && jogo[1][2] == '0' && jogo[2][2] == '0')) {
        printf("Jogador %c venceu!\n", jogo[2][2]);
        return 1;
    }
    //verifica a diagonal principal
    if((jogo[0][0] == 'X' && jogo[1][1] == 'X' && jogo[2][2] == 'X') ||
       (jogo[0][0] == '0' && jogo[1][1] == '0' && jogo[2][2] == '0')) {
        printf("Jogador %c venceu!\n", jogo[1][1]);
        return 1;
    }
    //verifica a diagonal secundaria
    if((jogo[0][2] == 'X' && jogo[1][1] == 'X' && jogo[2][0] == 'X') ||
       (jogo[0][2] == '0' && jogo[1][1] == '0' && jogo[2][0] == '0')) {
        printf("Jogador %c venceu!\n", jogo[1][1]);
        return 1;
    }
    return 0;
}
int verificacelula(char *linha1, int coluna) {
    if(coluna < 1 || coluna > 3) 
        return 1;
    else if(linha1[0] < 'a' || linha1[0] > 'c') 
        return 1;
    return 0;
}