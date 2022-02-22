/*
5. Considere que a struct abaixo está armazenada na sua lista. Faça uma função
para buscar o produto de menor preço. A função deve retornar se a operação foi
possível ou não.
typedef struct produto{
int codProd; //código do produto
char nomeProd[10]; //nome do produto
float valor; //valor do produto
int qtdeEstoque; //quantidade disponível em estoque
}Produto;
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct produto {
  int codProd;
  char nomeProd[10];
  float valor;
  int qtdeEstoque;
  struct produto *proximo;
} Produto;

typedef struct lista {
  Produto *inicio;
  int tamanho;
} Lista;

Lista *criarLista();
int estaVazia(Lista *l);
int inserir(Lista *l, int key, char name[], float price, int qtd);
int remover(Lista *l, int key, Produto *r);
Produto *buscarMenorProduto(Lista *l);
void imprimir(Lista *l);

int main() {
  Lista *l = criarLista();
  Produto *p = (Produto *) malloc(sizeof(Produto));
  int key, quantidade, i;
  char name[10];
  float valor;

  for(i = 0; i < 3; i++) {
    printf("----------CADASTRO DE PRODUTO----------\n\n");
    printf("Informe o codigo, valor, quantidade e o nome do produto: ");
    scanf("%d %f %d", &key, &valor, &quantidade);
    gets(name);

    inserir(l, key, name, valor, quantidade);
  }
  system("cls");
  imprimir(l);

  printf("Produto de menor preço: \n");
  p = buscarMenorProduto(l);
  printf(
    "Codigo: %d, Nome: %s, Valor: %.2f, Quantidade: %d\n\n",
    p->codProd, p->nomeProd, p->valor, p->qtdeEstoque
  );

  return 1;
}

Lista *criarLista() {
  Lista *l = (Lista *) malloc(sizeof(Lista));
  l->inicio = NULL;
  l->tamanho = 0;

  return l;
}

int estaVazia(Lista *l) {
  return l->inicio == NULL;
}

int inserir(Lista *l, int key, char name[], float price, int qtd) {
  Produto *novo_produto = (Produto *) malloc(sizeof(Produto));
  Produto *aux = (Produto *) malloc(sizeof(Produto));

  aux = l->inicio;
  novo_produto->codProd = key;
  novo_produto->valor = price;
  novo_produto->qtdeEstoque = qtd;
  strcpy(novo_produto->nomeProd, name);
  novo_produto->proximo = NULL;
  l->tamanho++;

  if(estaVazia(l)) {
    l->inicio = novo_produto;
  } else {
    while(aux->proximo != NULL) {
      aux = aux->proximo;
    }
    aux->proximo = novo_produto;
  }

  return 1;
}

int remover(Lista *l, int key, Produto *r) {
  Produto *aux = (Produto *) malloc(sizeof(Produto));
  Produto *remover = (Produto *) malloc(sizeof(Produto));

  int i = 1;

  aux = l->inicio;
  remover = l->inicio->proximo;

  while(remover->codProd != key) {
    aux = aux->proximo;
    remover = remover->proximo;
  }

  aux->proximo = remover->proximo;

  r = remover;
  free(remover);
  l->tamanho--;

  return 1;
}

Produto *buscarMenorProduto(Lista *l) {
  int menor;
  Produto *aux = (Produto *) malloc(sizeof(Produto));
  Produto *p = (Produto *) malloc(sizeof(Produto));

  aux = l->inicio;
  p = l->inicio;
  menor = l->inicio->valor;

  while(aux->proximo != NULL) {
    if(aux->valor < menor) {
      menor = aux->valor;
      p = aux;
    }
    aux = aux->proximo;
  }

  return p;
}

void imprimir(Lista *l) {
  if(l == NULL) {
    printf("Lista Vazia!\n\n");
  } else {
    Produto *aux = (Produto *) malloc(sizeof(Produto));
    aux = l->inicio;

    while(aux != NULL) {
      printf(
        "Cod: %d, Nome: %s, Valor: %.2f, Quantidade: %d\n",
        aux->codProd, aux->nomeProd, aux->valor, aux->qtdeEstoque
      );

      aux = aux->proximo;
    }
    printf("\n\n");
  }
}
