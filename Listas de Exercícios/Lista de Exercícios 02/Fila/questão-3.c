/*
3. Desenvolva uma função para testar se uma fila F1 tem mais elementos do que
uma fila F2.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct fila {
  int inicio;
  int final;
  int valor[MAX];
  int maior;
  int menor;
  float media;
} Fila;

Fila* criarFila();
void liberaFila(Fila *f);
int estaVazia(Fila *f);
int estaCheia(Fila *f);
int inserir(Fila *f, int v);
int remover(Fila *f, int *r);
int maiorFila(Fila *f1, Fila *f2);


int main() {
  Fila *p, *p2;
  int i, valor, maior;
  p = criarFila();
  p2 = criarFila();

  for(i = 0; i < 5; i++) {
    printf("Informe um valor para inserir: ");
    scanf("%d", &valor);
    inserir(p, valor);
  }
  system("cls");

  for(i = 0; i < 6; i++) {
    printf("Informe um valor para inserir: ");
    scanf("%d", &valor);
    inserir(p2, valor);
  }
  system("cls");

  maior = maiorFila(p, p2);
  if(maior == 1) {
    printf("A primeira fila e a maior!\n");
  } else {
    printf("A segunda fila e a maior!\n");
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

int maiorFila(Fila *f1, Fila *f2) {
  return f1->final > f2->final;  
}



