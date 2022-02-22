/*
1. Faça uma função para concatenar duas listas em uma terceira lista que deverá
ser retornada pela função. Não use funções já implementadas.
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
void imprimir_lista(Lista *l);
int liberar_lista(Lista *l);
int lista_cheia(Lista *l);
int lista_vazia(Lista *l);
int inserir(Lista *l, int e);
int remover(Lista *l, int **r);
Lista* concatenar_listas(Lista *a, Lista *b);


int main() {
  Lista *a = criar_lista();
  Lista *b = criar_lista();
  Lista *c;

  ver_valores(a, 5);
  ver_valores(b, 5);

  imprimir_lista(a);
  imprimir_lista(b);

  c = concatenar_listas(a, b);
  imprimir_lista(c);

  return 0;
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

void imprimir_lista(Lista *l) {
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

Lista* concatenar_listas(Lista *a, Lista *b) {
  Lista *c = criar_lista();
  int i;

  for(i = 0; i <= a->fim; i++) {
    inserir(c, a->valores[i]);
  }

  for(i = 0; i <= b->fim; i++) {
    inserir(c, b->valores[i]);
  }

  return c;
}







