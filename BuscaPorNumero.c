//verifica quantas vezes um número buscado aparece em um número principal
#include <stdio.h>
#include <stdio.h>
void testeNumeros();
int buscaNumeros(int numerobase, int numerobusca);
int main() {
    testeNumeros();
    return 0;
}
void testeNumeros() {
    printf("%d\n",buscaNumeros(34567368, 3) == 2);
    printf("%d\n",buscaNumeros(34567368, 4576) == 0);
    printf("%d\n",buscaNumeros(3539343, 3) == 4);
    printf("%d\n",buscaNumeros(3539343, 39) == 1);
    printf("%d\n",buscaNumeros(5444, 44) == 1);
    printf("%d\n",buscaNumeros(54444, 44) == 2);
    printf("%d\n",buscaNumeros(1234562354, 23) == 2);
    printf("%d\n",buscaNumeros(1234, 13) == 0);
    printf("%d\n",buscaNumeros(544444, 4) == 5);
    printf("%d\n",buscaNumeros(1234562354, 32) == 0);
    printf("%d\n",buscaNumeros(7777777, 7) == 7);
}
int buscaNumeros(int numerobase, int numerobusca) {
    int i, vetnumerobase[15], vetnumerobusca[15], qtdocorrencias=0;
    int posvetnumerobase, posvetnumerobusca, cont=0, tamnumbusca=0;

    for(i=0; numerobase != 0;i++) {
        vetnumerobase[i] = numerobase % 10;
        numerobase = numerobase / 10;   
    }
    
    vetnumerobase[i] = -2;
    for(i=0; numerobusca != 0;i++) {
        vetnumerobusca[i] = numerobusca % 10;
        numerobusca = numerobusca / 10;
        tamnumbusca++;
    }
    vetnumerobusca[i] = -1;

    for(i=0;vetnumerobase[i] != -2; ++i) {
        //mesmo procedimento da questão IV
        if(vetnumerobase[i] == vetnumerobusca[0]) {
            posvetnumerobase = i;
            cont=0;
            posvetnumerobusca = 0;
            while(vetnumerobusca[posvetnumerobusca] != -1) { 
                if(vetnumerobase[posvetnumerobase] == vetnumerobusca[posvetnumerobusca]) {
                    ++cont;
                     if(cont == tamnumbusca) {
                        //se o tamanho do numero é maior que 1, por exemplo, (44)(396)...
                        //ele aumenta incrementa para a próxima casa decimal
                        //evitando assim contagens e repetições desnecessárias
                        if(tamnumbusca > 1) {
                            i++;
                        }
                        ++qtdocorrencias;
                        break;
                    }
                    ++posvetnumerobase;
                    ++posvetnumerobusca;
                } else {
                    break;
                }
            } 
        }
    }
    return qtdocorrencias;
}