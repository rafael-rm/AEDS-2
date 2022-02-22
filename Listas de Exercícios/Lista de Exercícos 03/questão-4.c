/*
4. Faça uma função para trocar de posicão dois elementos de uma lista. A função
deve retornar se a operação foi possível ou não.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 20

typedef struct lista {
  int valores[MAX];
  int fim;
} Lista;

Lista* criar_lista();
void ver_valores(Lista *l, int quantidade);
void imprimirLista(Lista *l);
int liberar_lista(Lista *l);
int lista_cheia(Lista *l);
int lista_vazia(Lista *l);
int inserir(Lista *l, int e);
int remover(Lista *l, int **r);

int trocarPosicao(Lista *l, int pInicial, int pFinal); 

int main() {
  Lista *a = criar_lista();

  int pInicial, pFinal;

  ver_valores(a, 5);

  imprimirLista(a);

  printf("Informe as 2 posicoes que terao elementos trocados: ");
  scanf("%d %d", &pInicial, &pFinal);

  imprimirLista(a);
  int status = trocarPosicao(a, pInicial, pFinal);
  imprimirLista(a);

  return 1;
}

Lista* criar_lista() {
  Lista *p = (Lista *) malloc(sizeof(Lista));
  p->fim = -1;

  return p;
}

void ver_valores(Lista *l, int quantidade) {
  int i, valor;

  system("cls");
  for(i = 0; i < quantidade; i++) {
    printf("Informe o valor a ser inserido na lista: ");
    scanf("%d", &valor);
    inserir(l, valor);
  }
}

void imprimirLista(Lista *l) {
  int i;

  printf("\n\n");
  for(i = 0; i <= l->fim; i++) {
    printf(" %d", l->valores[i]);
  }
  printf("\n\n");
}

int liberar_lista(Lista *l) {
  free(l);
  return 1;
}

int lista_cheia(Lista *l) {
  return l->fim == MAX;
}

int lista_vazia(Lista *l) {
  return l->fim == -1;
}

int inserir(Lista *l, int e) {
  if(!lista_cheia(l)) {
    l->fim++;
    l->valores[l->fim] = e;
    return 1;
  } else {
    return 0;
  }
}

int remover(Lista *l, int **r) {
  if(!lista_vazia(l)) {
    **r = l->valores[l->fim];
    l->fim--;
    return 1;
  } else {
    return 0;
  }
}

int trocarPosicao(Lista *l, int pInicial, int pFinal) {
  int aux = l->valores[pInicial];

  
  l->valores[pInicial] = l->valores[pFinal];
  l->valores[pFinal] = aux;

  return 1;
}







