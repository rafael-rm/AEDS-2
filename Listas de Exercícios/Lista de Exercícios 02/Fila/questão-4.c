/*
4. Faça uma função que receba três filas, duas já preenchidas em ordem
crescente e preencha a última com os valores das duas primeiras em ordem
crescente.
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
int unirFilas(Fila *f1, Fila *f2, Fila *f3);
int ordenarFila(Fila *f);


int main() {
  Fila *p, *p2, *p3;
  int i, valor, maior;
  p = criarFila();
  p2 = criarFila();
  p3 = criarFila();

  for(i = 0; i < 3; i++) {
    printf("Informe um valor para inserir: ");
    scanf("%d", &valor);
    inserir(p, valor);
  }
  system("cls");

  for(i = 0; i < 3; i++) {
    printf("Informe um valor para inserir: ");
    scanf("%d", &valor);
    inserir(p2, valor);
  }
  system("cls");

  unirFilas(p, p2, p3);

  for(i = 0; i <= p3->final; i++) {
    printf("%d ", p3->valor[i]);
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

int unirFilas(Fila *f1, Fila *f2, Fila *f3) {
  int i;

  for(i = 0; i <= f1->final; i++) {
    inserir(f3, f1->valor[i]);
  }

  for(i = 0; i <= f2->final; i++) {
    inserir(f3, f2->valor[i]);
  }
  ordenarFila(f3);

  return 1;
}

int ordenarFila(Fila *f) {
  int i, aux, continua = 0;
  int tamanho = f->final;

  do {
    for(i = 0; i <= tamanho; i++) {
      if(f->valor[i] > f->valor[i+1]) {
        aux = f->valor[i];
        f->valor[i] = f->valor[i+1];
        f->valor[i+1] = aux;
        continua++;
      }
    }
    tamanho--;
  } while(continua != 0);
}