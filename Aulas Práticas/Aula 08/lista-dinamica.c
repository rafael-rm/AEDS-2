#include <stdio.h>
#include <stdlib.h>

typedef struct dados
{
  int valor;
  struct dados *proximo;
} s_dados;

typedef struct lista
{
  s_dados *inicio;
  int tamanho;
} s_lista;

s_lista *criar_lista();
int menu();
void apagar_lista(s_lista *lista);
int lista_vazia(s_lista *lista);
int inserir(s_lista *lista, int valor);
int inserir_posicao(s_lista *lista, int valor, int posicao);
int remover(s_lista *lista, int *valor);
int remover_posicao(s_lista *lista, int posicao, int *valor);
int descobrir_posicao(s_lista *lista, int valor, int *key);
int recuperar_posicao(s_lista *lista, int posicao, int *key);
int quantidade_elementos(s_lista *lista);
void imprimir(s_lista *lista);

int main()
{
  s_lista *lista = criar_lista();
  int valor, posicao, i, *removido, *key, recuperar;

  /* MENU
do
    {
        opcao = menu();
        printf("%d", opcao);
        switch (opcao)
        {
        case 1:
        case 2:
        case 3:
        }

    } while ((opcao != 0));
    system("cls");
    liberar_lista(lista_01);
    return 0;
}
  */

  for (i = 0; i < 5; i++)
  {
    printf("Informe um valor para adicionar lista: ");
    scanf("%d", &valor);

    inserir(lista, valor);
  }
  system("cls");
  imprimir(lista);

  do
  {
    printf("Informe a posicao para inserir de 1 a %d: ", lista->tamanho + 1);
    scanf("%d", &posicao);
  } while (posicao > lista->tamanho + 1);
  printf("Informe o valor a ser inserido: ");
  scanf("%d", &valor);
  inserir_posicao(lista, valor, posicao);

  system("cls");
  imprimir(lista);

  remover(lista, &removido);
  printf("Valor removido: %d\n", removido);
  imprimir(lista);
  system("pause");
  system("cls");

  do
  {
    printf("Informe a posicao a ser removida de 1 a %d: ", lista->tamanho);
    scanf("%d", &posicao);
  } while (posicao > lista->tamanho);
  system("cls");
  imprimir(lista);
  remover_posicao(lista, posicao, &removido);
  printf("Valor removido da posicao %d: %d\n", posicao, removido);

  imprimir(lista);
  system("pause");
  system("cls");

  printf("Informe o valor a ser encontrado: ");
  scanf("%d", &valor);

  recuperar = descobrir_posicao(lista, valor, &key);
  if (recuperar == 1)
  {
    printf("Valor %d encontrado na posicao: %d\n", valor, key);
  }
  else
  {
    printf("Valor %d não encontrado na lista!\n", valor);
  }

  imprimir(lista);
  system("pause");
  system("cls");

  printf("Informe a posicao: ");
  scanf("%d", &posicao);
  recuperar = recuperar_posicao(lista, posicao, &key);

  if (recuperar == 1)
  {
    printf("Valor da posicao %d: %d\n", posicao, key);
  }
  else
  {
    printf("Posicao %d nao encontrada!\n", posicao);
  }
  system("pause");
  system("cls");

  apagar_lista(lista);

  return 1;
}

int menu()
{
  int opcao_selecionada;
  do
  {
    system("cls");
    printf("\n[1] Inserir elemento no final da lista");
    printf("\n[2] Remover elemento do final da lista");
    printf("\n[3] Imprimir elementos da lista");
    printf("\n[4] Quantidade de elementos");
    printf("\n[5] Insira elemento em determinada posicao");
    printf("\n[6] Remover determinado elemento");
    printf("\n[7] Remover elemento de uma posicao");
    printf("\n[0] Liberar memoria");
    printf("\n");
    printf("\nOpcao: ");
    scanf("%d", &opcao_selecionada);
    system("cls");
  } while (!(opcao_selecionada >= 0 && opcao_selecionada <= 7));

  return opcao_selecionada;
}

s_lista *criar_lista()
{
  s_lista *lista = (s_lista *)malloc(sizeof(s_lista));
  lista->inicio = NULL;
  lista->tamanho = 0;
  return lista;
}

void apagar_lista(s_lista *lista)
{
  if (!lista_vazia(lista))
  {
    do
    {
      s_dados *aux;
      aux = lista->inicio;
      lista->inicio = aux->proximo;
      free(aux);
    } while (lista->inicio != NULL);
    free(lista);
  }
}

int lista_vazia(s_lista *lista)
{
  return lista->inicio == NULL;
}

int inserir(s_lista *lista, int valor)
{
  s_dados *novo_elemento = (s_dados *)malloc(sizeof(s_dados));
  s_dados *aux = (s_dados *)malloc(sizeof(s_dados));

  aux = lista->inicio;
  novo_elemento->valor = valor;
  novo_elemento->proximo = NULL;
  lista->tamanho++;

  if (lista_vazia(lista))
  {
    lista->inicio = novo_elemento;
  }
  else
  {
    while (aux->proximo != NULL)
    {
      aux = aux->proximo;
    }
    aux->proximo = novo_elemento;
  }

  return 1;
}

int inserir_posicao(s_lista *lista, int valor, int posicao)
{
  s_dados *novo_elemento = (s_dados *)malloc(sizeof(s_dados));
  s_dados *aux = (s_dados *)malloc(sizeof(s_dados));
  int i = 1;

  novo_elemento->valor = valor;
  aux = lista->inicio;

  while (i < posicao - 1)
  {
    i++;
    aux = aux->proximo;
  }

  novo_elemento->proximo = aux->proximo;
  aux->proximo = novo_elemento;
  lista->tamanho++;

  return 1;
}

int remover(s_lista *lista, int *valor)
{
  s_dados *aux = (s_dados *)malloc(sizeof(s_dados));
  s_dados *remover = (s_dados *)malloc(sizeof(s_dados));
  aux = lista->inicio;
  remover = lista->inicio->proximo;

  if (lista->tamanho != 1)
  {
    while (remover->proximo != NULL)
    {
      aux = aux->proximo;
      remover = remover->proximo;
    }

    *valor = remover->valor;
    aux->proximo = NULL;
    free(remover);
  }
  else
  {
    *valor = aux->valor;
    free(aux);
    lista->inicio = NULL;
  }

  lista->tamanho--;

  return 1;
}

int remover_posicao(s_lista *lista, int posicao, int *valor)
{
  s_dados *aux = (s_dados *)malloc(sizeof(s_dados));
  s_dados *remover = (s_dados *)malloc(sizeof(s_dados));
  int i = 1;
  if (posicao != 1)
  {
    aux = lista->inicio;
    remover = lista->inicio->proximo;

    while (i < posicao - 1)
    {
      aux = aux->proximo;
      remover = remover->proximo;
      i++;
    }

    aux->proximo = remover->proximo;
  }
  else
  {
    remover = lista->inicio;
    lista->inicio = remover->proximo;
  }

  *valor = remover->valor;
  free(remover);
  lista->tamanho--;

  return 1;
}

int descobrir_posicao(s_lista *lista, int valor, int *key)
{
  s_dados *aux = (s_dados *)malloc(sizeof(s_dados));
  aux = lista->inicio;
  int i = 1;

  while (aux != NULL)
  {
    if (aux->valor == key)
    {
      *key = i;
      return 1;
    }
    aux = aux->proximo;
    i++;
  }

  return 0;
}

int recuperar_posicao(s_lista *lista, int posicao, int *key)
{
  s_dados *aux = (s_dados *)malloc(sizeof(s_dados));
  aux = lista->inicio;
  int i = 1;

  while (i <= lista->tamanho)
  {
    if (i == posicao)
    {
      *key = aux->valor;
      return 1;
    }
    aux = aux->proximo;
    i++;
  }

  return 0;
}

int quantidade_elementos(s_lista *lista)
{
  return lista->tamanho;
}

void imprimir(s_lista *lista)
{
  if (lista == NULL)
  {
    printf("Lista vazia!\n\n");
  }
  else
  {
    s_dados *aux;
    aux = (s_dados *)malloc(sizeof(s_dados));
    aux = lista->inicio;

    while (aux != NULL)
    {
      printf("%d ", aux->valor);
      aux = aux->proximo;
    }
    printf("\n");
  }
}
