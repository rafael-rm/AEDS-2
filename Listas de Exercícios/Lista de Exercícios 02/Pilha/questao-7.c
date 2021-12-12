/*
7. Faça uma função para retornar o número de elementos da pilha que possuem
valor ímpar.
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
int valoresImpares(Pilha *p);

int main() {
  Pilha *p = criarPilha();
  int i, valor, quantidade_impar;

  for(i = 0; i < 5; i++) {
    printf("Informe um valor: ");
    scanf("%d", &valor);
    empilhar(p, valor);
  }
  system("cls");

  quantidade_impar = valoresImpares(p);
  printf("Quantidade de impares: %d\n\n", quantidade_impar);

  return 1;
}


Pilha *criarPilha() {
  Pilha *p = (Pilha *) malloc(sizeof(Pilha));
  p->topo = NULL;

  return p;
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
  printf("Pilha liberada!\n\n");
}

int estaVazia(Pilha *p) {
  if(p->topo == NULL) {
    return 1;
  } else {
    return 0;
  }
}

int empilhar(Pilha *p, int v) {
  
  Elemento *novo_elemento;

  novo_elemento = (Elemento *) malloc(sizeof(Elemento));
  novo_elemento->valor = v;
  
  if(estaVazia(p)) {
    novo_elemento->anterior = NULL;
    p->topo = novo_elemento;
  } else {
    novo_elemento->anterior = p->topo;
    p->topo = novo_elemento;
  }

  return p->topo->valor;  
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
    printf("ERRO: Pilha vazia!\n\n");
    return 0;
  }
}

int valoresImpares(Pilha *p) {
  Pilha *t = criarPilha();
  int impares = 0;

  t->topo = p->topo;
  while(t->topo != NULL) {
    if(t->topo->valor % 2 != 0) {
      impares++;
    }
    t->topo = t->topo->anterior;
  }

  return impares;
}