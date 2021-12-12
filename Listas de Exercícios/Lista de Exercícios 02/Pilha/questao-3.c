/*
3. Dado uma pilha que armazene números, escreva uma função que forneça o
maior, o menor e a média aritmética dos elementos da pilha.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct elemento {
  int valor;
  struct elemento *anterior;
} Elemento;

typedef struct pilha {
  Elemento *topo;
} Pilha;

Pilha *criarPilha();
void liberaPilha(Pilha *p);
int estaVazia(Pilha *p);
int empilhar(Pilha *p, int v);
int desempilhar(Pilha *p, int *v);
int calcular(Pilha *p);

int main() {
  Pilha *p = criarPilha();

  Elemento *t;
  int i, valor;

  for(i = 0; i < 5; i++) {
    printf("Informe um valor: ");
    scanf("%d", &valor);

    empilhar(p, valor);
  }

  t = p->topo;
  while(t != NULL) {
    printf("%d ", t->valor);
    t = t->anterior;
  }
  printf("\n\n");
    
  calcular(p);


  return 1;
}


Pilha *criarPilha() {
  Pilha *p = (Pilha *) malloc(sizeof(Pilha));
  p->topo = NULL;
}

void liberaPilha(Pilha *p) {
  if(!estaVazia(p)) {
    do {
      Elemento *aux;
      aux = p->topo;
      p->topo = aux->anterior;
      free(aux);
    } while(p->topo != NULL);
    free(p);
  }
}

int estaVazia(Pilha *p) {
  return p->topo == NULL;
}

int empilhar(Pilha *p, int v) {
  Elemento *e = (Elemento *) malloc(sizeof(Elemento));
  e->valor = v;

  if(estaVazia(p)) {
    e->anterior = NULL;
    p->topo = e;
  } else {
    e->anterior = p->topo;
    p->topo = e;
  }
  return 1;
}

int desempilhar(Pilha *p, int *v) {
  if(!estaVazia(p)) {
    Elemento *aux;
    aux = p->topo;
    *v = aux->valor;
    p->topo = aux->anterior;

    free(aux);
    return 1;
  } else {
    return 0;
  }
}

int calcular(Pilha *p) {
  int maior = p->topo->valor, menor = p->topo->valor;
  int soma, quantidade;
  float media;
  Elemento *t;

  printf("TESTE\n");
  t = p->topo;
  while(t != NULL) {
    if(t->valor > maior) {
      maior = t->valor;
    }

    if(t->valor < menor) {
      menor = t->valor;
    }

    soma += t->valor;
    quantidade++;
    t = t->anterior;
  }

  media = (soma / quantidade);

  printf("Maior valor: %d\n", maior);
  printf("Menor valor: %d\n", menor);
  printf("Media: %f\n", media);

  return 1;
}


