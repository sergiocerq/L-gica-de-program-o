// Basicamente esse programa possui uma estrutura principal de 10 posições
// e conforme a necessicade, cria um vetor auxiliar dinâmico para armazenar valores.
// Além disso, é possível excluir e montar uma lista encadeada!

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
int criarEstruturaAuxiliar(int posicao, int tamanho);
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

int main() {
  inicializar();
  //funções-testes
  testeInserirSemNada();
  testeCriarEstrutura();
  testeInserirComEstrutura();  
  testeExcluir();
  testeExcluirNumeroEspecifico();
  testeListar();
  testeRetornarTodosNumeros();
  testeMudarTamanhoEstrutura();
  //finalizar(vetorPrincipal);
  return 0;
}

void testeInserirSemNada() {
    puts("Teste inserir sem nada");
    printf("%d\n", inserirNumeroEmEstrutura(2, 2) == SEM_ESTRUTURA_AUXILIAR);
    printf("%d\n", inserirNumeroEmEstrutura(-2, 2) == POSICAO_INVALIDA);
    printf("%d\n", inserirNumeroEmEstrutura(0, 2) == POSICAO_INVALIDA);
    printf("%d\n", inserirNumeroEmEstrutura(11, 2) == POSICAO_INVALIDA);
}

void testeCriarEstrutura() {
  puts("Teste criar estrutura");
  printf("%d\n", criarEstruturaAuxiliar(-2, 5) == POSICAO_INVALIDA);
  printf("%d\n", criarEstruturaAuxiliar(0, 5) == POSICAO_INVALIDA);
  printf("%d\n", criarEstruturaAuxiliar(11, 5) == POSICAO_INVALIDA);
  printf("%d\n", criarEstruturaAuxiliar(2, -5) == TAMANHO_INVALIDO);
  printf("%d\n", criarEstruturaAuxiliar(2, 0) == TAMANHO_INVALIDO);
  printf("%d\n", criarEstruturaAuxiliar(2, 3) == SUCESSO);
  printf("%d\n", criarEstruturaAuxiliar(2, 6) == JA_TEM_ESTRUTURA_AUXILIAR);
}

void testeInserirComEstrutura() {
    puts("Teste inserir com estrutura");
    printf("%d\n", inserirNumeroEmEstrutura(2, 4) == SUCESSO);
    printf("%d\n", inserirNumeroEmEstrutura(2, -2) == SUCESSO);
    printf("%d\n", inserirNumeroEmEstrutura(2, 6) == SUCESSO);
    printf("%d\n", inserirNumeroEmEstrutura(2, 5) == SEM_ESPACO);
}

void testeExcluir() {
    puts("Teste excluir");
    printf("%d\n", excluirNumeroDoFinaldaEstrutura(2) == SUCESSO);
    printf("%d\n", excluirNumeroDoFinaldaEstrutura(2) == SUCESSO);
    printf("%d\n", excluirNumeroDoFinaldaEstrutura(0) == POSICAO_INVALIDA);
    printf("%d\n", excluirNumeroDoFinaldaEstrutura(1) == SEM_ESTRUTURA_AUXILIAR);
    printf("%d\n", excluirNumeroDoFinaldaEstrutura(2) == SUCESSO);
    printf("%d\n", excluirNumeroDoFinaldaEstrutura(2) == ESTRUTURA_AUXILIAR_VAZIA);
}

void testeExcluirNumeroEspecifico() {
    puts("Teste excluir numero especifico");
    printf("%d\n", criarEstruturaAuxiliar(9, 3) == SUCESSO);
    printf("%d\n", inserirNumeroEmEstrutura(9, 7) == SUCESSO);
    printf("%d\n", inserirNumeroEmEstrutura(9, 4) == SUCESSO);
    printf("%d\n", excluirNumeroEspecificoDeEstrutura(9, 12) == NUMERO_INEXISTENTE);
    printf("%d\n", excluirNumeroEspecificoDeEstrutura(9, 7) == SUCESSO);
    printf("%d\n", excluirNumeroEspecificoDeEstrutura(9, 4) == SUCESSO);
    printf("%d\n", excluirNumeroEspecificoDeEstrutura(1, 2) == SEM_ESTRUTURA_AUXILIAR);
}

void testeListar() {
  puts("Teste listar");
  printf("%d\n", inserirNumeroEmEstrutura(2, 7) == SUCESSO);
  printf("%d\n", inserirNumeroEmEstrutura(2, -9) == SUCESSO);

  int vet[2];

  printf("%d\n", getDadosEstruturaAuxiliar(1, vet) == SEM_ESTRUTURA_AUXILIAR);
  printf("%d\n", getDadosEstruturaAuxiliar(11, vet) == POSICAO_INVALIDA);
  printf("%d\n", getDadosEstruturaAuxiliar(2, vet) == SUCESSO);

  printf("%d\n", vet[0] == 7);
  printf("%d\n", vet[1] == -9);

  printf("%d\n", getDadosOrdenadosEstruturaAuxiliar(1, vet) == SEM_ESTRUTURA_AUXILIAR);
  printf("%d\n", getDadosOrdenadosEstruturaAuxiliar(11, vet) == POSICAO_INVALIDA);
  printf("%d\n", getDadosOrdenadosEstruturaAuxiliar(2, vet) == SUCESSO);

  printf("%d\n", vet[0] == -9);
  printf("%d\n", vet[1] == 7);

  printf("%d\n", getDadosEstruturaAuxiliar(2, vet) == SUCESSO);

  printf("%d\n", vet[0] == 7);
  printf("%d\n", vet[1] == -9);

  printf("%d\n", excluirNumeroDoFinaldaEstrutura(2) == SUCESSO);
  printf("%d\n", excluirNumeroDoFinaldaEstrutura(2) == SUCESSO);
}

void testeRetornarTodosNumeros() {
    puts("Teste retornar todos os numeros");
    int vet1[2];
    printf("%d\n", getDadosDeTodasEstruturasAuxiliares(vet1) == TODAS_ESTRUTURAS_AUXILIARES_VAZIAS);
    printf("%d\n", getDadosOrdenadosDeTodasEstruturasAuxiliares(vet1) == TODAS_ESTRUTURAS_AUXILIARES_VAZIAS);
    
    printf("%d\n", inserirNumeroEmEstrutura(2, 3) == SUCESSO);
    printf("%d\n", inserirNumeroEmEstrutura(2, 8) == SUCESSO);
    printf("%d\n", inserirNumeroEmEstrutura(2, 0) == SUCESSO);

    printf("%d\n", criarEstruturaAuxiliar(5, 10) == SUCESSO);
    printf("%d\n", inserirNumeroEmEstrutura(5, 1) == SUCESSO);
    printf("%d\n", inserirNumeroEmEstrutura(5, 34) == SUCESSO);
    printf("%d\n", inserirNumeroEmEstrutura(5, 12) == SUCESSO);
    printf("%d\n", inserirNumeroEmEstrutura(5, 6) == SUCESSO);
    printf("%d\n", inserirNumeroEmEstrutura(5, 27) == SUCESSO);
    printf("%d\n", inserirNumeroEmEstrutura(5, -6) == SUCESSO);
    
    int vet[9];

    printf("%d\n", getDadosDeTodasEstruturasAuxiliares(vet) == SUCESSO);
    printf("%d\n", vet[0] == 3);
    printf("%d\n", vet[1] == 8);
    printf("%d\n", vet[2] == 0);
    printf("%d\n", vet[3] == 1);
    printf("%d\n", vet[4] == 34);
    printf("%d\n", vet[5] == 12);
    printf("%d\n", vet[6] == 6);
    printf("%d\n", vet[7] == 27);
    printf("%d\n", vet[8] == -6);
}

void testeMudarTamanhoEstrutura() {
    puts("Teste mudar tamanho estrutura");
    int vet[1];
    printf("%d\n",modificarTamanhoEstruturaAuxiliar(2, -3) == NOVO_TAMANHO_INVALIDO);
    printf("%d\n",modificarTamanhoEstruturaAuxiliar(2, -4) == NOVO_TAMANHO_INVALIDO);
    printf("%d\n",modificarTamanhoEstruturaAuxiliar(11, 7) == POSICAO_INVALIDA);
    printf("%d\n",modificarTamanhoEstruturaAuxiliar(0, 7) == POSICAO_INVALIDA);
    printf("%d\n",modificarTamanhoEstruturaAuxiliar(1, 7) == SEM_ESTRUTURA_AUXILIAR);
    
    printf("%d\n",modificarTamanhoEstruturaAuxiliar(2, -2) == SUCESSO);

    printf("%d\n",getQuantidadeElementosEstruturaAuxiliar(2) == 1);
    printf("%d\n",getDadosEstruturaAuxiliar(2, vet) == SUCESSO);
  
    //modificar para tamanho de 1 para 4
    printf("%d\n",modificarTamanhoEstruturaAuxiliar(2, 3) == SUCESSO);
    printf("%d\n",getQuantidadeElementosEstruturaAuxiliar(2) == 1);
    printf("%d\n",getDadosEstruturaAuxiliar(2, vet) == SUCESSO);

    printf("%d\n",inserirNumeroEmEstrutura(2, 4) == SUCESSO);
    printf("%d\n",inserirNumeroEmEstrutura(2, -2) == SUCESSO);
    printf("%d\n",inserirNumeroEmEstrutura(2, 6) == SUCESSO);
    printf("%d\n",inserirNumeroEmEstrutura(2, 5) == SEM_ESPACO);
}

void testeListaEncadeada(){
  puts("Teste lista encadeada");
  int vet[10];
  linkedList = NULL;
  No* inicio = montarListaEncadeadaComCabecote();
  getDadosListaEncadeadaComCabecote(inicio, vet);
  
  printf("%d\n", vet[0] == 3);
  printf("%d\n", vet[1] == 4);
  printf("%d\n", vet[2] == -2);
  printf("%d\n", vet[3] == 6);
  printf("%d\n", vet[4] == 1);
  printf("%d\n", vet[5] == 34);
  printf("%d\n", vet[6] == 12);
  printf("%d\n", vet[7] == 6);
  printf("%d\n", vet[8] == 27);
  printf("%d\n", vet[9] == -6);

  destruirListaEncadeadaComCabecote(inicio);
  printf("%d\n",inicio == NULL);
}

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

int criarEstruturaAuxiliar (int posicao, int tamanho) {
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
  No *head = NULL; 
  for(int i = 0; i<TAM ;i++) {
      qtdElementos+=vetorPrincipal[i].qtdElementos;
  } 
  if(qtdElementos != 0){
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
  No *nextToRelease = head, *getFree;   
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