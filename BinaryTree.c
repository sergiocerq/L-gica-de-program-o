#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// O algoritmo pega os dados do arquivo.in e cria uma árvore binária
// No fim, ele escreve os nós da árvore binária e seus respectivos níveis

typedef struct node {
    int value;
    struct node *left, *right;
} Tree;

Tree *InsertNode(Tree *root, int data);
int TreeSearch(Tree *root, int key);
void WriteSortedTree(Tree *root, int nodeHeight, FILE *fp_out);
Tree *DeleteTree(Tree *root, int key);

int main() {
  FILE *fp_in = fopen("archive.in", "r");
  FILE *fp_out = fopen("archive.out", "w");
    
  if(fp_in == NULL || fp_out == NULL){
    puts("Erro na leitura dos arquivos");
    return EXIT_FAILURE;
  }
  Tree *root = NULL;
  char file[255];
  while(fgets(file, 255, fp_in) != NULL){  
    char *space = " ";
    char *slice = strtok(file, space);
    while(slice){
      if(strcmp(slice, "a") == 0) {
        slice = strtok(NULL, space);
        int num = atoi(slice);
        root = InsertNode(root, num);
      }
      if(strcmp(slice, "r") == 0) {
        slice = strtok(NULL, space);
        int num = atoi(slice);
        if(TreeSearch(root, num) == 1) {
          root = DeleteTree(root, num);
        } else {
          root = InsertNode(root, num);
        }
      }
      slice = strtok(NULL, space);
    }
  }
  WriteSortedTree(root, 0, fp_out);
  fclose(fp_in);
  fclose(fp_out);
  return EXIT_SUCCESS;
}

Tree *InsertNode(Tree *root, int data) {
  if(!root) {
    Tree *newNode = (Tree*) malloc(sizeof(Tree));
    newNode->value = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
  } else {
      if(data <= root->value)
        root->left = InsertNode(root->left, data);
      if(data > root->value)
        root->right = InsertNode(root->right, data);
      return root;
    }
}

int TreeSearch(Tree *root, int key) {
  //função retorna 1 se encontrar e 0 caso não encontre
  if(root == NULL) {
    return 0;
  } else {
      if(root->value == key)
        return 1;
        //ao inves de retornar 1, retorna o endereço que eu achei
      else {
        if(key < root->value)
          return TreeSearch(root->left, key);
      else
          return TreeSearch(root->right, key);
      }
   }
}

void WriteSortedTree(Tree *root, int nodeHeight, FILE *fp_out) {
  if(!root) return;
  WriteSortedTree(root->left, nodeHeight + 1, fp_out);
  fprintf(fp_out,"%d (%d) ", root->value, nodeHeight);
  WriteSortedTree(root->right, nodeHeight + 1, fp_out);
}

Tree *DeleteTree(Tree *root, int key) {
  if(root == NULL){
    return NULL;
  } else {
      if(root->value == key) {
        if(root->left == NULL && root->right == NULL) {
          free(root);
          return NULL;
        } else {
            if(root->left != NULL && root->right != NULL){
              Tree *aux = root->left;
              while(aux->right != NULL)
                aux = aux->right;
              root->value = aux->value;
              aux->value = key;
              root->left = DeleteTree(root->left, key);
              return root;
            } else {
                Tree *aux;
                if(root->left != NULL)
                  aux = root->left;
                else
                  aux = root->right;
                free(root);
                return aux;
              }
          }
        } else {
            if(key < root->value)
              root->left = DeleteTree(root->left, key);
            else
              root->right = DeleteTree(root->right, key);
            return root;
          }
    }
}