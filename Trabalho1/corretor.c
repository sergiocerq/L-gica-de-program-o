// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo contém exemplos de testes das questões do trabalho.
//  o aluno pode incrementar os testes

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 19/08/2016 - 28/03/2023

// #################################################
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "SergioSantos20222160016.h"

void testQ1();
void testQ2();
void testQ3();
void testQ4();
void testQ5();
void testQ6();

int main(){
    //pridntf("q1\n");
    testQ1(); // 10 testes
    //pridntf("q2\n");
    testQ2(); 
    //prindtf("q3\n");
    testQ3(); // 13 testes
    //prdintf("q4\n");
    testQ4(); // 22 testes
    //prdintf("q5\n");
    testQ5(); // 10 testes
    //prdintf("q6\n");
    testQ6(); // 10 testes 
    
    
}

void testQ1(){
    char str[11];
    strcpy(str,"29/02/2015");
    printf("%d\n",q1(str) == 0);
    strcpy(str,"29/02/2012");
    printf("%d\n",q1(str) == 1);
    strcpy(str,"9/13/2014");
    printf("%d\n",q1(str) == 0);
    strcpy(str,"45/4/2014");
    printf("%d\n",q1(str) == 0);
    strcpy(str,"12/1/15");
    printf("%d\n",q1(str) == 1);
    strcpy(str,"1/9/2016");
    printf("%d\n",q1(str) == 1);
    strcpy(str,"//2016");
    printf("%d\n",q1(str) == 0);
    strcpy(str,"1//20");
    printf("%d\n",q1(str) == 0);
    strcpy(str,"1/R/2016");
    printf("%d\n",q1(str) == 0);
    strcpy(str,"1/12/19");
    printf("%d\n",q1(str) == 1); 

}

void testQ2(){
    char datainicial[11], datafinal[11];
    int qtdDias, qtdMeses, qtdAnos, variavel, retorno;

    strcpy(datainicial, "01/06/2015");
    strcpy(datafinal, "01/06/2016");
    variavel = q2(datainicial, datafinal);
}

void testQ3(){
    char str[250];
    strcpy(str,"Renato Lima Novais");
    printf("%d\n",q3(str, 'a', 0) == 3);
    printf("%d\n",q3(str, 'b', 0) == 0);
    printf("%d\n",q3(str, 'l', 1) == 0);
    printf("%d\n",q3(str, 'l', 0) == 1);
    printf("%d\n",q3(str, 'L', 0) == 1);

    strcpy(str,"Letícia, signifiCa fEliCIdADE");
    printf("%d\n",q3(str, 'c', 0) == 3);
    printf("%d\n",q3(str, 'C', 0) == 3);
    printf("%d\n",q3(str, 'c', 1) == 1);
    printf("%d\n",q3(str, 'C', 1) == 2);
    printf("%d\n",q3(str, 'R', 0) == 0);
    printf("%d\n",q3(str, 'e', 0) == 3);
    printf("%d\n",q3(str, 'E', 1) == 2);
    printf("%d\n",q3(str, 'S', 1) == 0);

    
}

void testQ4(){
    char strTexto[250];
    char strBusca[50];
    int posicoes[30];
    int i;
    for (i = 0; i<30; i++){
        posicoes[i] = -1;
    }
    strcpy(strTexto,"Laboratorio de programacao: para ratos de programação");
    strcpy(strBusca,"rato");
    printf("%d\n",q4(strTexto, strBusca, posicoes) == 2);
    printf("%d\n",posicoes[0]==5);
    printf("%d\n",posicoes[1]==8);
    printf("%d\n",posicoes[2]==34);
    printf("%d\n",posicoes[3]==37);


    for (i = 0; i<30; i++){
        posicoes[i] = -1;
    }
    strcpy(strTexto,"Ola, o mundo e muito grande. Tem muitas pessoas, e muitos problemas");
    strcpy(strBusca,"mui");
    printf("%d\n",q4(strTexto, strBusca, posicoes) == 3);
    printf("%d\n",posicoes[0]==16);
    printf("%d\n",posicoes[1]==18);
    printf("%d\n",posicoes[2]==34);
    printf("%d\n",posicoes[3]==36);
    printf("%d\n",posicoes[4]==52);
    printf("%d\n",posicoes[5]==54);

    for (i = 0; i<30; i++){
        posicoes[i] = -1;
    }
    strcpy(strTexto,"Programar é legal?");
    strcpy(strBusca,"sim");
    printf("%d\n",q4(strTexto, strBusca, posicoes) == 0);

    for (i = 0; i<30; i++){
        posicoes[i] = -1;
    }
    strcpy(strTexto,"maraaaavilha, meu prograaaama funcionou");
    strcpy(strBusca,"aa");
    printf("%d\n",q4(strTexto, strBusca, posicoes) == 4);
    printf("%d\n",posicoes[0]==4);
    printf("%d\n",posicoes[1]==5);
    printf("%d\n",posicoes[2]==6);
    printf("%d\n",posicoes[3]==7);
    printf("%d\n",posicoes[4]==24);
    printf("%d\n",posicoes[5]==25);
    printf("%d\n",posicoes[6]==26);
    printf("%d\n",posicoes[7]==27);

}


void testQ5(){
    printf("%d\n",q5(345) == 543);
    printf("%d\n",q5(78) == 87);
    printf("%d\n",q5(3) == 3);
    printf("%d\n",q5(5430) == 345);
    printf("%d\n",q5(1000) == 1);
    printf("%d\n",q5(0) == 0);
    printf("%d\n",q5(707) == 707);
    printf("%d\n",q5(80) == 8);
    printf("%d\n",q5(8) == 8);
    printf("%d\n",q5(1234) == 4321);
}

void testQ6(){
    printf("%d\n",q6(34567368, 3) == 2);
    printf("%d\n",q6(34567368, 4576) == 0);
    printf("%d\n",q6(3539343, 3) == 4);
    printf("%d\n",q6(3539343, 39) == 1);
    printf("%d\n",q6(5444, 44) == 1);
    printf("%d\n",q6(54444, 44) == 2);
    printf("%d\n",q6(1234562354, 23) == 2);
    printf("%d\n",q6(1234, 13) == 0);
    printf("%d\n",q6(544444, 4) == 5);
    printf("%d\n",q6(1234562354, 32) == 0);

}