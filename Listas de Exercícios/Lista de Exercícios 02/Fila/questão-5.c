/*
5. Escreva uma funçãoo que, dado duas filas, concatene as duas filas. Retorne
a fila concatenada em F1. F2 deve ficar vazia.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct elemento {
  int valor;
  struct elemento *proximo;
} Elemento;

typedef struct fila {
  Elemento *inicio;
  Elemento *final;
} Fila;

Fila *criarFila();
void liberaFila(Fila *f);
int estaVazia(Fila *f);
int inserir(Fila *f, int v);
int retirar(Fila *f, int *r);
int concatenar(Fila *f1, Fila *f2);

int main() {
  Fila *f1 = criarFila();
  Fila *f2 = criarFila();
  Elemento *t = (Elemento *) malloc(sizeof(Elemento));
  int i, valor;

  for(i = 0; i < 5; i++) {
    printf("Informe um valor: ");
    scanf("%d", &valor);
    inserir(f1, valor);
  }
  system("cls");

  for(i = 0; i < 3; i++) {
    printf("Informe um valor para F2: ");
    scanf("%d", &valor);
    inserir(f2, valor);
  }
  system("cls");

  concatenar(f1, f2);
  t->proximo = f1->inicio;
  while(t->proximo != NULL) {
    printf("%d ", t->proximo->valor);
    t->proximo = t->proximo->proximo;
  }
  free(t);

  return 1;
}

Fila *criarFila() {
  Fila *p =(Fila *) malloc(sizeof(Fila));
  p->inicio = NULL;
  p->final = NULL;
  return p;
}

void liberaFila(Fila *f) {
  if(!estaVazia(f)) {
    do {
      Elemento *aux;
      aux = f->inicio;
      f->inicio = aux->proximo;
      free(aux);
    } while(f->inicio != NULL);
    free(f);
  }
}

int estaVazia(Fila *f) {
  return f->inicio == NULL;
}

int inserir(Fila *f, int v) {
  Elemento *e = (Elemento *) malloc(sizeof(Elemento));

  e->valor = v;
  e->proximo = NULL;

  if(estaVazia(f)) {
    f->inicio = e;
    f->final = e;
  } else {
    f->final->proximo = e;
    f->final = e;
  }

  return 1;
}

int retirar(Fila *f, int *v) {
  if(!estaVazia(f)) {
    Elemento *aux;
    aux = f->inicio;
    *v = aux->valor;

    if(f->inicio == f->final) {
      f->final = NULL;
    }

    f->inicio = aux->proximo;
    free(aux);

    return 1;
  } else {
    return 0;
  }
}

int concatenar(Fila *f1, Fila *f2) {
  Elemento *t = (Elemento *) malloc(sizeof(Elemento));
  int r;

  t->proximo = f2->inicio;
  while(t->proximo != NULL) {
    retirar(f2, &r);
    inserir(f1, r);
    t->proximo = f2->inicio;
  }

  free(t);
  return 1;
}