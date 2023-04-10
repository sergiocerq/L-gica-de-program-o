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
//  Semestre: 2°

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 03/04/2023

// #################################################
#ifndef TRABALHO1_SERGIOSANTOS20222160016_H
#define TRABALHO1_SERGIOSANTOS20222160016_H
//Declaração das funções
typedef struct {
  int dia;
  int mes;
  int ano;
  int retorno;
} dma;
//Declaração das funções
int q1(char *data);
int q2(char *datainicial, char *datafinal);
void testeQ1(char *str);
void testeQ2();
dma quebraData(char *data);
int validaData(int dia1,int mes1,int ano1);
int calculodedata(char *datainicial, char *datafinal);
void testeQ3();
int q3(char *string, char letra, int sensitivecase);
int contacaracter(char *string, char letra, int sensitivecase);
void testeQ4();
int q4(char *string, char *palavra, int vet[]);
void testeQ5();
int q5(int num);
void testeQ6();
int q6(int numerobase, int numerobusca);

#endif TRABALHO1_SERGIOSANTOS20222160016_H
