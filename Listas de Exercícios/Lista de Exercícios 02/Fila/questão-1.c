/*
1. Implemente a função reverso, que reposiciona os elementos na fila de tal
forma que o início da fila se torna o fim, e vice-versa.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct fila {
  int inicio;
  int final;
  int valor[MAX];
} Fila;

Fila* criarFila();
void liberaFila(Fila *f);
int estaVazia(Fila *f);
int estaCheia(Fila *f);
int inserir(Fila *f, int v);
int remover(Fila *f, int *r);
int reverter(Fila *f);

int main() {
  Fila *p;
  int valor, i;
  p = criarFila();

  for(i = 0; i < 5; i++) {
    printf("Informe um valor para inserir: ");
    scanf("%d", &valor);
    inserir(p, valor);
  }

  for(i = 0; i < 5; i++) {
    printf("%d ", p->valor[i]);
  }

  reverter(p);

  printf("\n\n");
  for(i = 0; i < 5; i++) {
    printf("%d ", p->valor[i]);
  }
  
  return 1;
}

Fila* criarFila() {
  Fila *f = (Fila *) malloc(sizeof(Fila));

  f->inicio = 0;
  f->final = -1;

  return f;
}

void liberaFila(Fila *f) {
  free(f);
}

int estaVazia(Fila *f) {
  return  f->final < 0;
}

int estaCheia(Fila *f) {
  return f->final == MAX-1;
}

int inserir(Fila *f, int v) {
  if(!estaCheia(f)) {
    f->final++;
    f->valor[f->final] = v;
    return 1;
  } else {
    return 0;
  }
}

int remover(Fila *f, int *r) {
  if(!estaVazia(f)) {
    *r = f->valor[f->final];
    f->final--;
    return 1;
  } else {
    return 0;
  }
}

int reverter(Fila *f) {
  int i;
  int test;

  for(i = 0; i <= (f->final/2); i++) {
    test = f->valor[f->inicio+i];

    f->valor[f->inicio+i] = f->valor[f->final-i];
    f->valor[f->final-i] = test;
  }
  
  return 1;
}






