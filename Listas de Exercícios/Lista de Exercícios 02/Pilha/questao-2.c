/*
2. Considere uma pilha que armazene caracteres. Escreva uma função que
verifique se uma palavra é um palíndromo.
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
int palindromo(Pilha *p);


int main() {
  Pilha *p = criarPilha();
  int opcao, i, palavra_palindromo;
  char caractere, removido;

  do {
    printf("Escolha uma opcao: \n");
    printf("1 - Empilhar: \n2 - Desempilhar: \n");
    printf("3 - Imprimir Pilha: \n4 - Palindromo");
    printf("0 - Encerrar o programa!\n\n");

    scanf("%d", &opcao);
    getchar();

    switch(opcao) {
      case 1:
        printf("Informe um valor a ser empilhado: ");
        scanf("%c", &caractere);
        empilhar(p, caractere);
        break;
      case 2:
        desempilhar(p, &removido);
        printf("O valor removido foi: %c\n", removido);
        getchar();
        break;
      case 3:
        for(i = 0; i <= p->tam; i++) {
          printf("%c ", p->txt[i]);
        }
        getchar();
        break;
      case 4:
        printf("%s\n", p->txt);
        palavra_palindromo = palindromo(p);

        if(palavra_palindromo == 0) {
          printf("E um palindromo!\n\n");
        } else {
          printf("Nao e um palindromo!\n\n");
        }
        printf("TESTE\n");

        getchar();
        break;
      default:
        printf("Escolha uma opcao válida!\n");
        getchar();
        break;
    }


    system("cls");
  } while(opcao != 0);
 

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
    p->tam--; 
    
    return 1;
  } else { 
    return 0;
  }
}

int palindromo(Pilha *p) {
  Pilha *a;
  int i, txt_palindromo, tamanho;
  char texto, texto2[p->tam+1];

  tamanho = p->tam;

  for(i = 0; i <= tamanho; i++) {
    desempilhar(p, &texto);
    texto2[i] = texto;
  }

  for(i = tamanho; i >= 0; i--) {
    empilhar(p, texto2[i]);
  }

  txt_palindromo = strcmp(p->txt, texto2);

  return txt_palindromo;
}