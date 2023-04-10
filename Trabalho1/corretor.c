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
int main() {
  //O main só faz chamar as funções-testes
  //e printar '\n' para facilitar a visualização
  char data[11];
  testeQ1(data);
  printf("\n");
  testeQ2();
  printf("\n");
  testeQ3();
  printf("\n");
  testeQ4();
  printf("\n");
  testeQ5();
  printf("\n");
  testeQ6();
  printf("\n");
  
}
void testeQ1(char *str) {
    //testes de datas inválidas/válidas
    //Possui 10 testes
    strcpy(str, "K/02/2015");
    printf("%d\n", q1(str) == 0);
    strcpy(str, "4/4/2014");
    printf("%d\n", q1(str) == 1);
    strcpy(str, "5/9/2020");
    printf("%d\n", q1(str) == 1);
    strcpy(str, "33/9/2020");
    printf("%d\n", q1(str) == 0);
    strcpy(str, "5/19/2020");
    printf("%d\n", q1(str) == 0);
    strcpy(str, "31/4/2012");
    printf("%d\n", q1(str) == 0);
    strcpy(str, "-5/7/2019");
    printf("%d\n", q1(str) == 0);
    strcpy(str, "29/2/2001");
    printf("%d\n", q1(str) == 0);
    strcpy(str, "29/2/76");
    printf("%d\n", q1(str) == 0);
    strcpy(str, "29/2/2008");
    printf("%d\n", q1(str) == 1);
}
void testeQ2() {
    //testes de possíveis datas
    char datainicial[11], datafinal[11];
    strcpy(datainicial, "35/2/2008");
    strcpy(datafinal, "9/2/2008");
    printf("%d\n", q2(datainicial, datafinal) == 2);
    strcpy(datainicial, "15/2/2008");
    strcpy(datafinal, "9/45/2008");
    printf("%d\n", q2(datainicial, datafinal) == 3);
    strcpy(datainicial, "15/8/2015");
    strcpy(datafinal, "9/8/2015");
    printf("%d\n", q2(datainicial, datafinal) == 4);
    strcpy(datainicial, "8/4/2004");
    strcpy(datafinal, "23/11/2019");
    printf("%d\n", q2(datainicial, datafinal) == 1);
}
void testeQ3() {
    char string[251];
    //Teste I
    strcpy(string, "FLaMENgo é cAMPEão da LiBeRtaDORes!");
    printf("%d\n",q3(string, 'ã', 0) == 1);
    printf("%d\n",q3(string, 'é', 1) == 1);
    printf("%d\n",q3(string, 'o', 0) == 3);
    printf("%d\n",q3(string, 'E', 1) == 2);
    printf("%d\n",q3(string, 'F', 1) == 1);
    printf("\n");
    //Teste II
    strcpy(string,"Letícia, signifiCa fEliCIdADE");
    printf("%d\n",q3(string, 'c', 0) == 3);
    printf("%d\n",q3(string, 'C', 0) == 3);
    printf("%d\n",q3(string, 'c', 1) == 1);
    printf("%d\n",q3(string, 'C', 1) == 2);
    printf("%d\n",q3(string, 'R', 0) == 0);
    printf("%d\n",q3(string, 'e', 0) == 3);
    printf("%d\n",q3(string, 'E', 1) == 2);
    printf("%d\n",q3(string, 'S', 1) == 0);
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
    strcpy(string, "welcome to freecodecamp");
    strcpy(palavra, "co");
    printf("%d\n", q4(string, palavra, posicao)== 2);
    printf("%d\n",posicao[0]==4);
    printf("%d\n",posicao[1]==5);
    printf("%d\n",posicao[2]==16);
    printf("%d\n",posicao[3]==17);
}
void testeQ5() {
    //Possui 10 testes
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
void testeQ6() {
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
    printf("%d\n",q6(7777777, 7) == 7);
}