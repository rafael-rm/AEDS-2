/*
3. Faça uma função para buscar a posição e o valor do maior elemento da lista,
os quais deverão ser retornados por referência. A função deve retornar se a
operação foi possível ou não.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 20

typedef struct lista
{
  int valores[MAX];
  int fim;
} Lista;

Lista *criar_lista();
void ver_valores(Lista *l, int quantidade);
void imprimir_lista(Lista *l);
int liberar_lista(Lista *l);
int lista_cheia(Lista *l);
int lista_vazia(Lista *l);
int inserir(Lista *l, int e);
int remover(Lista *l, int **r);

int indexMaiorValor(Lista *l, int **p, int **v);

int main()
{
  Lista *a = criar_lista();

  int *maior, *index;

  ver_valores(a, 5);

  imprimir_lista(a);

  int status = indexMaiorValor(a, &index, &maior);
  printf("Maior valor %d, na posicao %d\n\n", *maior, *index);

  return 1;
}

Lista *criar_lista()
{
  Lista *p = (Lista *)malloc(sizeof(Lista));
  p->fim = -1;

  return p;
}

void ver_valores(Lista *l, int quantidade)
{
  int i, valor;

  system("cls");
  for (i = 0; i < quantidade; i++)
  {
    printf("Informe o valor a ser inserido na lista: ");
    scanf("%d", &valor);
    inserir(l, valor);
  }
}

void imprimir_lista(Lista *l)
{
  int i;

  printf("\n\n");
  for (i = 0; i <= l->fim; i++)
  {
    printf(" %d", l->valores[i]);
  }
  printf("\n\n");
}

int liberar_lista(Lista *l)
{
  free(l);
  return 1;
}

int lista_cheia(Lista *l)
{
  return l->fim == MAX;
}

int lista_vazia(Lista *l)
{
  return l->fim == -1;
}

int inserir(Lista *l, int e)
{
  if (!lista_cheia(l))
  {
    l->fim++;
    l->valores[l->fim] = e;
    return 1;
  }
  else
  {
    return 0;
  }
}

int remover(Lista *l, int **r)
{
  if (!lista_vazia(l))
  {
    **r = l->valores[l->fim];
    l->fim--;
    return 1;
  }
  else
  {
    return 0;
  }
}

int indexMaiorValor(Lista *l, int **p, int **v)
{
  int i, indexMaior = 0;
  int maior = l->valores[0];

  for (i = 0; i <= l->fim; i++)
  {
    if (l->valores[i] > maior)
    {
      maior = l->valores[i];
      indexMaior = i;
    }
  }

  **p = indexMaior;
  **v = maior;

  return 1;
}
