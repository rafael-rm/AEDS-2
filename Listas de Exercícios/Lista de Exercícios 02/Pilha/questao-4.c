/*
4. Desenvolva uma função para inverter a posição dos elementos de uma pilha
P.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Pilha {
  int valor[MAX];
  int topo;
} Pilha;

Pilha *criarPilha();
int estaVazia(Pilha *p);
int estaCheia(Pilha *p);
void liberaPilha(Pilha *p);
int empilhar(Pilha *p, int valor);
int desempilha(Pilha *p, int *r);
int inverter(Pilha *p);

int main() {
  Pilha *p = criarPilha();
  int i, valor;

  for(i = 0; i < 5; i++) {
    printf("Informe um valor: ");
    scanf("%d", &valor);

    empilhar(p, valor);
  }

  system("cls");

  for(i = 0; i <= p->topo; i++) {
    printf ("%d ", p->valor[i]);
  }

  printf("\n\nInvertido:\n");
  inverter(p);

  for(i = 0; i <= p->topo; i++) {
    printf ("%d ", p->valor[i]);
  }

  return 1;
}

Pilha *criarPilha() {
  Pilha *p =(Pilha *) malloc(sizeof(Pilha));
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
  if(!estaCheia(p) == 1) {
    p->topo++;
    p->valor[p->topo] = valor; 
    return 1;
  } else {
    return 0;
  }
}

int desempilha(Pilha *p, int *r) {
  if(estaVazia(p) == 1) {
    printf("ERRO: Pilha vazia!\n\n");
  } else {
    *r = p->valor[p->topo];
    p->topo--;
    return 1;
  }
}

int inverter(Pilha *p) {
  int i, aux, tam = p->topo;

  for(i = 0; i <= (tam/2); i++) {
    aux = p->valor[i];
    p->valor[i] = p->valor[tam-i];
    p->valor[tam-i] = aux;
  }

  return 1;
}