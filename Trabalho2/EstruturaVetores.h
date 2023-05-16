#ifndef TRABALHO2_ESTRUTURAVETORES_H
#define TRABALHO2_ESTRUTURAVETORES_H

#include <stdio.h>
#include <stdlib.h>
#define TAM 10
enum { TODAS_ESTRUTURAS_AUXILIARES_VAZIAS = -110, NOVO_TAMANHO_INVALIDO, NUMERO_INEXISTENTE,
       ESTRUTURA_AUXILIAR_VAZIA, TAMANHO_INVALIDO, SEM_ESPACO_DE_MEMORIA, POSICAO_INVALIDA,
       JA_TEM_ESTRUTURA_AUXILIAR, SEM_ESTRUTURA_AUXILIAR, SEM_ESPACO, SUCESSO };

typedef struct {
    int *vetoraux;
    int qtdElementos;
    int tamAux;
} estururaPrincipal;

typedef struct {
    int number;
    struct No *next;
}No;

estururaPrincipal vetorPrincipal[TAM];
No *linkedList;

//funções-teste
void testeCriarEstrutura();
void testeInserirComEstrutura(); 
void testeInserirSemNada();
void testeExcluir();
void testeExcluirNumeroEspecifico();
void testeListar();
void testeRetornarTodosNumeros();
void testeMudarTamanhoEstrutura();
void testeListaEncadeada();

//funções-EstruturaVetores
void inicializar();
void finalizar();
void selectionSort(int vetor[], int tamVetor);
void insertionsort(int *vet);
int criarEstruturaAux(int posicao, int tamanho);
int inserirNumeroEmEstrutura(int posicao, int valor);
int excluirNumeroDoFinaldaEstrutura(int posicao);
int excluirNumeroEspecificoDeEstrutura(int posicao, int numero);
int posicaoValida(int posicao);
int getDadosEstruturaAuxiliar(int posicao, int *vetorAux);
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int *vetor);
int getDadosDeTodasEstruturasAuxiliares(int *vetor);
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int *vet);
int modificarTamanhoEstruturaAuxiliar(int posicao, int novotamanho);
int getQuantidadeElementosEstruturaAuxiliar(int posicao) ;
No *montarListaEncadeadaComCabecote();
void getDadosListaEncadeadaComCabecote(No *head, int *vet);
void destruirListaEncadeadaComCabecote(No *head);

#endif  // TRABALHO2_ESTRUTURAVETORES_H