/*
6. Considere uma pilha P vazia e uma fila F não vazia. Utilizando apenas as
funções da fila e da pilha, escreva uma função que inverta a ordem dos
elementos da fila.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Pilha {
  int valor[MAX];
  int topo;
} Pilha;

typedef struct fila {
  int inicio;
  int fim;
  int valor[MAX];
} Fila;

Pilha *criarPilha();
int estaVazia(Pilha *p);
int estaCheia(Pilha *p);
void liberaPilha(Pilha *p);
int empilhar(Pilha *p, int valor);
int desempilha(Pilha *p, int *r);

Fila *criarFila();
int filaVazia(Fila *p);
int filaCheia(Fila *p);
int inserir(Fila *p, int v);
int retirar(Fila *p, int *r);

int inverterFila(Fila *f);

int main() {
  Fila *f = criarFila();

  int i, valor;

  for(i = 0; i < 5; i++) {
    printf("Informe um valor para a fila: ");
    scanf("%d", &valor);

    inserir(f, valor);
  }

  system("cls");
  for(i = 0; i <= f->fim; i++) {
    printf("%d ", f->valor[i]);
  }

  printf("\n\nFila invertida: \n");
  inverterFila(f);
  for(i = 0; i <= f->fim; i++) {
    printf("%d ", f->valor[i]);
  }

  return 1;
}

Pilha *criarPilha() {
  Pilha *p = (Pilha *) malloc(sizeof(Pilha));
  p->topo = -1;

  return p;
}

int estaVazia(Pilha *p) { 
  if(p->topo == -1) {
    return 1;
  } else {
    return 0;
  }
}

int estaCheia(Pilha *p) {
  if(p->topo == MAX-1) {
    return 1;
  } else {
    return 0;
  }
}

int empilhar(Pilha *p, int valor) {
  if(!estaCheia(p)) {
    p->topo++;
    p->valor[p->topo] = valor; 
    return 1;
  } else {
    return 0;
  }
}

int desempilha(Pilha *p, int *r) {
  if(!estaVazia(p)) {
    *r = p->valor[p->topo];
    p->topo--;
    return 1;
  } else {
    return 0;
  }
}


Fila *criarFila() {
  Fila *f = (Fila *) malloc(sizeof(Fila));
  f->inicio = 0;
  f->fim = -1;

  return f;
}

int filaVazia(Fila *p) {
  return p->inicio > p->fim;
}

int filaCheia(Fila *p) {
  return p->fim == MAX-1;
}

int inserir(Fila *p, int v) {
  if(!filaCheia(p)) {
    p->fim++;
    p->valor[p->fim] = v;
    return 1;
  } else {
    return 0;
  }
}

int retirar(Fila *p, int *r) {
  int i;
  if(!filaVazia(p)) {
    *r = p->valor[p->inicio];
    
    for(i = 0; i <= p->fim; i++) {
      p->valor[i] = p->valor[i+1];
    }
    p->fim--;
    return 1;
  } else {
    return 0;
  }
}


int inverterFila(Fila *f) {
  Pilha *p = criarPilha();
  int i, removido, tam = (f->fim / 2);

  for(i = 0; i <= f->fim; i++) {
    retirar(f, &removido);
    empilhar(p, removido);
  }

  for(i = 0; i <= p->topo; i++) {
    desempilha(p, &removido);
    inserir(f, removido);
  }

  return 1;
}



