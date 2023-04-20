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
#include <string.h>
#include <ctype.h>
#include "SergioSantos20222160016.h"
//Questão I
int q1(char *data) {
    int retorno;
    dma variaveldaq1;
    //variável criada para receber o retorno da função
    //e assim, retornar um valor inteiro
    variaveldaq1 = quebraData(data);
    if(variaveldaq1.retorno < 1) {
      return 0;
    } else {
      return 1;
    }
}
//Questão II
int q2(char *datainicial, char *datafinal) {
    //chama a função que executa a questão
    int retorno = calculodedata(datainicial, datafinal);
    return retorno;
}
//Função que quebra a data
dma quebraData(char *data) {
    int i=0, j=0, retorno;
    char dia[3], mes[3], ano[5];
    dma diasMesesAnos;
    int dia1, mes1, ano1; 
    for(i=0;data[i] != '/';i++) {
        if (data[i] >= '0' && data[i] <= '9') {
            dia[i] = data[i];
        } else {
            diasMesesAnos.retorno = 0;    
            return diasMesesAnos;
        }
    }
    if(i == 1 || i == 2) {
    dia[i] = '\0';
    } else {
        diasMesesAnos.retorno = 0;    
        return diasMesesAnos;
    }
    i++;
    j=0;
    for(; data[i] != '/';i++) {
        if(data[i] >= '0' && data[i] <= '9') {
            mes[j] = data[i];
            j++;
        } else {
            diasMesesAnos.retorno = 0;    
            return diasMesesAnos;
        }
    }
    if(j == 1 || j == 2) {
    mes[j] = '\0';
    } else { 
        diasMesesAnos.retorno = 0;    
        return diasMesesAnos;
    }
    
    ++i;
    j=0;
    for(;data[i] != '\0';i++) {
        if(data[i] >= '0' && data[i] <= '9') {
        ano[j] = data[i];
        j++;
        } else {
            diasMesesAnos.retorno = 0;    
            return diasMesesAnos;
        }
    }
    if(j == 2 || j == 4) {
        ano[j] = '\0';
    } else {
        diasMesesAnos.retorno = 0;    
        return diasMesesAnos;
    }
    dia1 = atoi(dia);
    mes1 = atoi(mes);
    ano1 = atoi(ano);
    if(ano1 < 100) //Caso o usuário digite '74' para o ano, o sistema automaticamente incrementa 2000 anos, fazendo assim retornar uma data inválida
    ano1+=2000;
    retorno = validaData(dia1, mes1, ano1);
    
    if(retorno < 1) {
        diasMesesAnos.retorno = 0;    
        return diasMesesAnos;
    } else {
        diasMesesAnos.dia = dia1;
        diasMesesAnos.mes = mes1;
        diasMesesAnos.ano = ano1;
        diasMesesAnos.retorno = 1;
        return diasMesesAnos;
    }
}
int validaData(int dia, int mes, int ano) {
    if(dia > 31 || dia < 1 || mes > 12 || mes < 1 || ano < 0 || ano > 2023){
        return 0;
    } else {
        if(mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12) {
        //validação dos meses que tem 31 dias
            if(dia > 31)
                return 0;
            else
                return 1;
        }
        if(mes == 4 || mes == 6 || mes == 9 || mes == 11) {
          //validação dos meses com 30 dias
            if(dia > 30) 
                return 0;
            else 
                return 1;
        }
        if(mes == 2) {
          //validação do mês de fevereiro que pode ter 28 ou 29 dias a depender do ano
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
int calculodedata(char *datainicial, char *datafinal) {
    dma diasMesesAnosinicial, diasMesesAnosfinal;
    diasMesesAnosinicial = quebraData(datainicial);
    //caso a data inicial seja inválida, retorna 2
    if(diasMesesAnosinicial.retorno < 1) {
        return 2;
    }
    diasMesesAnosfinal = quebraData(datafinal);
    //caso a data final seja inválida, retorna 3
    if (diasMesesAnosfinal.retorno < 1) {
        return 3;
    } 
    //caso datainicial > datafinal, retorna 4
    if(diasMesesAnosinicial.ano > diasMesesAnosfinal.ano){
        return 4;
    }
    if(diasMesesAnosinicial.ano == diasMesesAnosfinal.ano) {
        if(diasMesesAnosinicial.mes > diasMesesAnosfinal.mes) {
            return 4;
        }
        if(diasMesesAnosinicial.mes == diasMesesAnosfinal.mes) {
            if(diasMesesAnosinicial.dia > diasMesesAnosfinal.dia) {
                return 4;
            }
        }
    }
  //CALCULAR DIFERENÇA ENTRE AS DATAS
  return 1;
}
//Questão III
int q3(char *string, char letra, int sensitivecase) {
    if(string[249] != '\0') {
      string[249] = '\0';
    }
    int qtdocorrencias = contacaracter(string, letra, sensitivecase);
    
    return qtdocorrencias;
}
int contacaracter(char *string, char letra, int sensitivecase) {
    int i, qtdocorrencias = 0;
    if(sensitivecase != 1) {
        for(i=0; i < strlen(string); i++) {
            if(toupper(string[i]) == toupper(letra)) { 
                ++qtdocorrencias;
            }
        }
    } else {
        for(i=0; i < strlen(string); i++) {
            if(string[i] == letra) { 
                ++qtdocorrencias;
            }
        }   
    }
    return qtdocorrencias;
}
//Questão IV
int q4(char *string, char *palavra, int vet[]) {
    if(string[249] != '\0') {
      string[249] = '\0';
    }
    int i=0, j=0, cont=0, posicaostr=0, posvetor=0, ocorrencias=0;
    for(i=0;i<strlen(string);++i) {
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
//Questão V
int q5(int num) {
    int resposta=0, i, numeros[11];
    if(num < 0) {
        num*=-1;
    }
    for(i=0; num != 0;i++) {
        numeros[i] = num % 10;
        num = num / 10;
    }
    --i;
    int multiplicador=1;
    while(i>=0) {
        resposta+=numeros[i] * multiplicador;
        multiplicador*=10;
        --i;
    }
    return resposta;
}
//Questão VI
int q6(int numerobase, int numerobusca) {
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
                            i = posvetnumerobase;
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