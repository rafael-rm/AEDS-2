/*
1. Escreva um algoritmo, usando uma Pilha, que inverte as letras de cada palavra
de um texto terminado por ponto (.) preservando a ordem das palavras. Por
exemplo, dado o texto:
ESTE EXERCICIO E MUITO FACIL.
A saída deve ser:
ETSE OICICREXE E OTIUM LICAF
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50


typedef struct pilha {
  int tam;
  char txt[MAX];
} Pilha;

Pilha *criarPilha();
int liberaPilha(Pilha *p);
int estaVazia(Pilha *p);
int estaCheia(Pilha *p);
int empilhar(Pilha *p, char c);
int desempilhar(Pilha *p, char *removido);
int inverterTexto(Pilha *p, char text[]);

int main() {
  Pilha *p;
  p = criarPilha();
  char c[MAX];
  int i;

  /*for(i = 0; i < 5; i++) {
    printf("Informe uma frase: ");
    scanf("%c", &c);
    getchar();

    empilhar(p, c);
  }*/

  c[MAX] = "ESTE EXERCICIO E MUITO FACIL.";
  inverterTexto(p, c);

  for(i = 0; i < 5; i++) {
    printf("%s", p->txt);
  }  

  return 1;
}

Pilha *criarPilha() {
  Pilha *p = (Pilha *) malloc(sizeof(Pilha));
  p->tam = -1;
  
  return p;
}

int liberaPilha(Pilha *p) {
  free(p);
  return 1;
}

int estaVazia(Pilha *p) {
  return p->tam == -1;
}

int estaCheia(Pilha *p) {
  return p->tam == MAX-1;
}

int empilhar(Pilha *p, char c) {
  if(!estaCheia(p)) {
    p->tam++;
    p->txt[p->tam] = c;

    return 1;
  } else {
    return 0;
  }
}

int desempilhar(Pilha *p, char *removido) {
  if(!estaVazia(p)) {
    *removido = p->txt[p->tam];
    p->txt[p->tam] = '\0';
    p->tam--; 
    
    return 1;
  } else { 
    return 0;
  }
}

int inverterTexto(Pilha *p, char text[]) {
  int tamanho = strlen(text);
  int i, j;
  char removido;

  Pilha *newP = criarPilha();

  if(text[tamanho] == '.') {
    while(text[i] != '.') {
      while(text[i] != ' ') {
        empilhar(newP, text[i]);
        i++;
      }

      while(p->tam >= 0) {
        desempilhar(newP, &removido);
        empilhar(p, removido);
      }
    }
    empilhar(p, text[i]);
    return 1;
  } else {
    return 0;
  }
}






