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
#include <string.h>
#include "SergioSantos20222160016.h"
int main() {
  testeQ1();
}
void testeQ1() {//função que testa possíveis datas
    char str[11];
    //testes de datas inválidas/válidas
    //Possui 10 testes
    strcpy(str, "K/02/2015");
    printf("%d\n", quebraData(str) == 0);
    strcpy(str, "4/4/2014");
    printf("%d\n", quebraData(str) == 1);
    strcpy(str, "5/9/2020");
    printf("%d\n", quebraData(str) == 1);
    strcpy(str, "33/9/2020");
    printf("%d\n", quebraData(str) == 0);
    strcpy(str, "5/19/2020");
    printf("%d\n", quebraData(str) == 0);
    strcpy(str, "31/4/2012");
    printf("%d\n", quebraData(str) == 0);
    strcpy(str, "-5/7/2019");
    printf("%d\n", quebraData(str) == 0);
    strcpy(str, "29/2/2001");
    printf("%d\n", quebraData(str) == 0);
    strcpy(str, "29/2/2004");
    printf("%d\n", quebraData(str) == 1);
    strcpy(str, "29/2/2008");
    printf("%d\n", quebraData(str) == 1);
}