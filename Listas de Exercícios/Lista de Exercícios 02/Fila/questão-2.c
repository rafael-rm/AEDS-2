/*
2. Considere uma fila contendo números inteiros. Escreva uma função que
calcule o maior, o menor e a média aritmética dos seus elementos.
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
int calculos(Fila *f);

int main() {
  Fila *p;
  int i, valor, maior;
  p = criarFila();

  for(i = 0; i < 5; i++) {
    printf("Informe um valor para inserir: ");
    scanf("%d", &valor);
    inserir(p, valor);
  }
  system("cls");

  calculos(p);
  printf("Maior valor: %d\n", p->maior);
  printf("Menor valor: %d\n", p->menor);
  printf("Media valor: %.2f\n", p->media);

  
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

int calculos(Fila *f) {
  int i, soma = 0;
  f->maior = f->valor[0];
  f->menor = f->valor[0];

  for(i = 0; i <= f->final; i++) {
    if(f->valor[i] > f->maior) {
      f->maior = f->valor[i];
    }

    if(f->valor[i] < f->menor) {
      f->menor = f->valor[i];
    }

    soma += f->valor[i];
  }

  f->media = soma / f->final;

  return 1;
}





