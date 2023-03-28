// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: Sérgio Cerqueira Santos
//  email: sergiocerq11@gmail.com
//  Matrícula: 20222160016
//  Semestre: 1/2023

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 28/03/2023 - 19/08/2016

// #################################################
#include <stdio.h>
#include <stdlib.h>
#include "SergioSantos20222160016.h"

int quebraData(char *data) {
    int i=0, j=0, retorno;
    char dia[3], mes[3], ano[5];
    int dia1, mes1, ano1;
    //teste para verificar se a data contem outros caracteres
    //quebrando o dia  
    for(i=0;data[i] != '/';i++) {
        if (data[i] >= '0' && data[i] <= '9') {
            dia[i] = data[i];
        } else {
            return 0;
        }
    }
    if(i == 1 || i == 2) {
    dia[i] = '\0';
    } else {
        return 0;
    }
    //quebrando o mes
    i++;
    j=0;
    for(; data[i] != '/';i++) {
        if(data[i] >= '0' && data[i] <= '9') {
            mes[j] = data[i];
            j++;
        } else {
            return 0;
        }
    }
    if(j == 1 || j == 2) {
    mes[j] = '\0';
    } else { 
       return 0;
    }
    
    ++i;
    j=0;
    //quebrando o ano
    for(;data[i] != '\0';i++) {
        if(data[i] >= '0' && data[i] <= '9') {
        ano[j] = data[i];
        j++;
        } else {
            return 0;
        }
    }
    if(j == 2 || j == 4) {
        ano[j] = '\0';
    } else {
        return 0;
    }
    //convertendo o conteudo da string em 
    dia1 = atoi(dia);
    mes1 = atoi(mes);
    ano1 = atoi(ano);
    //chamada para a função que valida a data
    retorno = validaData(dia1, mes1, ano1);
    if(retorno < 1) {
        return 0;
    } else {
        return 1;
    }
}
int validaData(int dia, int mes, int ano){
    if(dia > 31 || dia < 1 || mes > 12 || mes < 1 || ano < 0 || ano > 2023){
        return 0;
    } else {
        if(mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12) {
            if(dia > 31)
                return 0;
            else
                return 1;
        }
        if(mes == 4 || mes == 6 || mes == 9 || mes == 11) {
            if(dia > 30) 
                return 0;
            else 
                return 1;
        }
        if(mes == 2) {
            if ((ano%4 == 0 && ano%100 != 0) || (ano%400 == 0)) {
                if (dia > 29)
                    return 0;
                else
                    return 1;
            }
            else {
                if(dia > 28) 
                    return 0;
                else
                    return 1;
            }     
        }
    }
    return 1;
}