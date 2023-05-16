#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "EstruturaVetores.h"
#define TAM 10

void inicializar () {
  for(int i=0;i<TAM;i++) {
    vetorPrincipal[i].qtdElementos = 0;
    vetorPrincipal[i].tamAux = 0;
    vetorPrincipal[i].vetoraux = NULL;
  }
}

void selectionSort (int vetor[], int tamVetor) {
    int i, j, menorValor, temporario;
    for (i = 0; i < tamVetor - 1; i++) {
        menorValor = i;
        for (j = i + 1; j < tamVetor; j++) {
            if (vetor[j] < vetor[menorValor]) {
                menorValor = j;
            }
        }
        temporario = vetor[menorValor];
        vetor[menorValor] = vetor[i];
        vetor[i] = temporario;
    }
}

int criarEstruturaAux (int posicao, int tamanho) {
  --posicao;
  int retorno;
  if(posicao < 0 || posicao > 9) {
      retorno = POSICAO_INVALIDA;
  } else if(tamanho < 1) {
      retorno = TAMANHO_INVALIDO;
  } else if(vetorPrincipal[posicao].vetoraux != NULL) {
      retorno = JA_TEM_ESTRUTURA_AUXILIAR;
  } else {
      vetorPrincipal[posicao].vetoraux = (int *) malloc(tamanho * sizeof(int));
      vetorPrincipal[posicao].tamAux = tamanho;
      vetorPrincipal[posicao].qtdElementos = 0;
      return SUCESSO;
  }
  return retorno;
}

int inserirNumeroEmEstrutura (int posicao, int valor) {
  --posicao;
  int retorno;
  if(posicao < 10 && posicao >= 0) {
    if(vetorPrincipal[posicao].vetoraux != NULL && vetorPrincipal[posicao].tamAux > 0) {
      if(vetorPrincipal[posicao].qtdElementos < vetorPrincipal[posicao].tamAux) {
    vetorPrincipal[posicao].vetoraux[vetorPrincipal[posicao].qtdElementos] = valor;
        vetorPrincipal[posicao].qtdElementos++;
        return SUCESSO;
      } else 
          retorno = SEM_ESPACO;
      
    } else 
        retorno = SEM_ESTRUTURA_AUXILIAR;
    
  } else 
      retorno = POSICAO_INVALIDA;

  return retorno;
}

int excluirNumeroDoFinaldaEstrutura (int posicao) {
  --posicao;
  int retorno;
  if(posicao < 10 && posicao >= 0) {
    if(vetorPrincipal[posicao].vetoraux != NULL && vetorPrincipal[posicao].tamAux > 0) {
      if(vetorPrincipal[posicao].qtdElementos > 0) {
        vetorPrincipal[posicao].qtdElementos--;
        return SUCESSO;
      } else 
          retorno = ESTRUTURA_AUXILIAR_VAZIA;

    } else 
        retorno = SEM_ESTRUTURA_AUXILIAR;
    
  } else 
      retorno = POSICAO_INVALIDA;

  return retorno;
}

int excluirNumeroEspecificoDeEstrutura (int posicao, int numero) {
  --posicao;
  int retorno;
  if(posicaoValida(posicao) == SUCESSO) {
    if(vetorPrincipal[posicao].vetoraux != NULL && vetorPrincipal[posicao].tamAux > 0) {
      if(vetorPrincipal[posicao].qtdElementos > 0) {
        int achou=0;
        int qtdElementos = vetorPrincipal[posicao].qtdElementos;
        for(int i=0;i<qtdElementos;i++) {
          if(vetorPrincipal[posicao].vetoraux[i] == numero) {
            ++achou;
            for(int j=i-1; j<qtdElementos; j++) {
              vetorPrincipal[posicao].vetoraux[j] = vetorPrincipal[posicao].vetoraux[j+1];
            }
            vetorPrincipal[posicao].qtdElementos--;
            retorno = SUCESSO;
          }
        }
        if(achou == 0)
          retorno = NUMERO_INEXISTENTE;
      } else 
          retorno = ESTRUTURA_AUXILIAR_VAZIA;

    } else 
        retorno = SEM_ESTRUTURA_AUXILIAR;
    
  } else 
      retorno = POSICAO_INVALIDA;

  return retorno;
}

int posicaoValida(int posicao) {
    if(posicao < 10 && posicao >= 0)
      return SUCESSO;
    else 
      return POSICAO_INVALIDA;
}

int getDadosEstruturaAuxiliar (int posicao, int *vetor) {
  --posicao;
  int retorno;
  int posVet=0;
  if(vetor == NULL)
    return POSICAO_INVALIDA;
  if(posicaoValida(posicao) == SUCESSO) {
    if(vetorPrincipal[posicao].vetoraux != NULL && vetorPrincipal[posicao].tamAux > 0) {
      if(vetorPrincipal[posicao].qtdElementos > 0) {
        for(int i = 0; i< vetorPrincipal[posicao].qtdElementos; i++) {
          vetor[posVet] = vetorPrincipal[posicao].vetoraux[i];
          posVet++;
        }
        return SUCESSO;
      } else
          retorno = ESTRUTURA_AUXILIAR_VAZIA;

    } else 
        retorno = SEM_ESTRUTURA_AUXILIAR;

  } else
      retorno = POSICAO_INVALIDA;

  return retorno;
}
    
int getDadosOrdenadosEstruturaAuxiliar (int posicao, int *vetor) {
  if(vetor == NULL)
    return SEM_ESPACO_DE_MEMORIA;
  --posicao;
  int retorno;
  if(posicaoValida(posicao) == SUCESSO) {
    if(vetorPrincipal[posicao].vetoraux != NULL && vetorPrincipal[posicao].tamAux > 0) {
      if(vetorPrincipal[posicao].qtdElementos > 0) {
        int i;
        int posVet=0;
        for(i = 0; i< vetorPrincipal[posicao].qtdElementos; i++) {
          vetor[posVet] = vetorPrincipal[posicao].vetoraux[i];
          ++posVet;
        }
        selectionSort(vetor, posVet);
        retorno = SUCESSO;
      } else
          retorno = ESTRUTURA_AUXILIAR_VAZIA;

    } else 
        retorno = SEM_ESTRUTURA_AUXILIAR;

  } else
      retorno = POSICAO_INVALIDA;

  return retorno;
}

int getDadosDeTodasEstruturasAuxiliares(int *vetor) {
  if (vetor == NULL)
    return SEM_ESPACO_DE_MEMORIA;

  int retorno = TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
  int posVet = 0;
  int sucesso = 0;
  for (int i=0;i<TAM;i++) {
    if (vetorPrincipal[i].vetoraux != NULL && vetorPrincipal[i].qtdElementos > 0 && vetorPrincipal[i].tamAux > 0) {
      for (int j = 0; j < vetorPrincipal[i].qtdElementos; j++) {
        vetor[posVet] = vetorPrincipal[i].vetoraux[j];
        posVet++;
      }
      sucesso++;
      retorno = SUCESSO;
    }
  }
  if (sucesso == 0)
    retorno = TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;

  return retorno;
}

int getDadosOrdenadosDeTodasEstruturasAuxiliares (int vetor[]) {
  if(vetor == NULL)
    return SEM_ESPACO_DE_MEMORIA;

  int retorno = TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
  int posVet=0;
  for(int i=0;i<TAM;++i) {
    if(vetorPrincipal[i].vetoraux != NULL && vetorPrincipal[i].qtdElementos > 0) {
      int tamanhoVet = vetorPrincipal[i].qtdElementos;
      for(int j=0;j<tamanhoVet;j++) {
        vetor[posVet] = vetorPrincipal[i].vetoraux[j];   
        ++posVet;
      }
      retorno = SUCESSO;
    }
  } 
  if(posVet > 0)
    insertionsort(vetor);
  
  return retorno;
}

void insertionsort (int *vet) {
    int i, j, key;
    int tamanho = (sizeof(*vet)/sizeof(int));
    for(i=0;i<tamanho;i++) {
        j=i+1;
        key = vet[j];
        while(j > 0 && vet[j-1] > key) {
            vet[j] = vet[j-1];
            j--;
        }
        vet[j] = key;
    }
}

int modificarTamanhoEstruturaAuxiliar (int posicao, int novotamanho) {
  --posicao;
  int retorno;
  if(posicaoValida(posicao) == SUCESSO) {
    if(vetorPrincipal[posicao].vetoraux != NULL && vetorPrincipal[posicao].tamAux > 0) {
      novotamanho += vetorPrincipal[posicao].tamAux;
      if(novotamanho > 0) {
      vetorPrincipal[posicao].vetoraux = (int *) malloc(novotamanho * sizeof(int));
      if(!vetorPrincipal[posicao].tamAux)
        return SEM_ESPACO_DE_MEMORIA;
      vetorPrincipal[posicao].tamAux = novotamanho;
      if(novotamanho < vetorPrincipal[posicao].qtdElementos) {
        vetorPrincipal[posicao].qtdElementos = novotamanho;
      }
        retorno = SUCESSO;
    
      } else
          retorno = NOVO_TAMANHO_INVALIDO;
      
    } else
        retorno = SEM_ESTRUTURA_AUXILIAR;

  } else
      retorno = POSICAO_INVALIDA;

  return retorno;
}

int getQuantidadeElementosEstruturaAuxiliar (int posicao) {
  --posicao;
  int retorno;
  if(posicaoValida(posicao) == SUCESSO) {
      if(vetorPrincipal[posicao].vetoraux != NULL && vetorPrincipal[posicao].tamAux > 0) {
        if(vetorPrincipal[posicao].tamAux < vetorPrincipal[posicao].qtdElementos) {
            vetorPrincipal[posicao].tamAux = vetorPrincipal[posicao].qtdElementos;
        }
        return vetorPrincipal[posicao].qtdElementos;
      } else {
          retorno = ESTRUTURA_AUXILIAR_VAZIA;
      }
  } else {
      retorno = POSICAO_INVALIDA;
  }
  return retorno;
}

No *montarListaEncadeadaComCabecote() {
  int qtdElementos = 0;
  No *head = NULL; // meu head inicia como NULL
  for(int i = 0; i<TAM ;i++) {
      qtdElementos+=vetorPrincipal[i].qtdElementos;
  } 
  if(qtdElementos != 0){ // caso qtdElementos != 0 mudar o valor de head, se não ele retorna head como NULL
    int *vetor2 = (int *) malloc(qtdElementos * sizeof(int));
    if(vetor2 == NULL){
      return NULL;
    }
    getDadosDeTodasEstruturasAuxiliares(vetor2);
    No *last = NULL; 
    for(int s = 0; s < qtdElementos; s++) {
      No *new = (No *) malloc(sizeof(No));
      new->next = NULL; 
      new->number = vetor2[s]; 
      if(head == NULL) {  
        head = new;
      } else {
        last->next = new;
      }
      last = new;
    } 
  }
  return head;
}

void getDadosListaEncadeadaComCabecote(No *head, int *vet) {
  No *currentNumber = head;
  int i = 0;
  while(currentNumber != NULL) {
    vet[i] = currentNumber->number;
    i++;
    currentNumber = currentNumber->next;
  }
}

void destruirListaEncadeadaComCabecote(No *head) {
  No *nextToRelease = head;
  No *getFree = NULL;   
  while(nextToRelease->next != NULL) {
    getFree = nextToRelease;
    free(getFree);
    nextToRelease = nextToRelease->next;    
  }
}

void finalizar () {
  for(int i=0;i<TAM;i++)
    free(vetorPrincipal[i].vetoraux);
}