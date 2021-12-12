/*
6. Faça uma função que inverta a ordem dos elementos da fila.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct fila {
  int inicio;
  int final;
  int valor[MAX];
} Fila;

Fila *criarFila();
int estaVazia(Fila *f);
int estaCheia(Fila *f);
int inserir(Fila *f, int v);
int retirar(Fila *f, int *r);
int inverter(Fila *f);

int main() {
  Fila *f = criarFila();
  int i, valor;

  for(i = 0; i < 5; i++) {
    printf("Informe um valor: ");
    scanf("%d", &valor);
    inserir(f, valor);
  }
  system("cls");

  for(i = 0; i <= f->final; i++) {
    printf("%d ", f->valor[i]);
  }

  inverter(f);
  printf("\n\nFila invertida: \n");

  for(i = 0; i <= f->final; i++) {
    printf("%d ", f->valor[i]);
  }

 

  return 1;
}

Fila *criarFila() {
  Fila *f = (Fila *) malloc(sizeof(Fila));
  f->inicio = 0;
  f->final = -1;

  return f;
}

int estaVazia(Fila *f) {
  return f->inicio > f->final;
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

int retirar(Fila *f, int *r) {
  int i;
  if(!estaVazia(f)) {
    *r = f->valor[f->inicio];
    for(i = 0; i < f->final; i++) {
      f->valor[i] = f->valor[i+1];
    }
    f->final--;
    return 1;
  } else {
    return 0;
  }
}

int inverter(Fila *f) {
  int i, tam = (f->final / 2);
  int aux;

  for(i = 0; i <= tam; i++) {
    aux = f->valor[i];
    f->valor[i] = f->valor[f->final - i];
    f->valor[f->final - i] = aux;
  } 
  
  return 1;
}