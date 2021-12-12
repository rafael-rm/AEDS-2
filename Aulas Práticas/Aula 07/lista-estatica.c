#include <stdio.h>
#include <stdlib.h>

#define MAX 5
#define VAZIO 0

#define FALSE 0
#define TRUE 1

typedef struct lista
{
    int vetor[MAX];
    int fim;
} s_lista;

s_lista *cria_lista();
void liberar_lista(s_lista *lista);
int quantidade_elementos(s_lista *lista);
void imprimir_lista(s_lista *lista);
int inserir_final(s_lista *lista, int valor);
int remover_final(s_lista *lista, int *valor);
int inserir_posicao(s_lista *lista, int valor, int posicao);
int lista_cheia(s_lista *lista);
int lista_vazia(s_lista *lista);
int ponteiro_valido(s_lista *lista);
int remover_chave(s_lista *lista, int valor);
int remover_posicao(s_lista *lista, int posicao, int *valor);
int menu();

int main()
{
    s_lista *lista_01;
    lista_01 = cria_lista();
    int opcao, temp, temp2, status;
    do
    {
        opcao = menu();
        printf("%d", opcao);
        switch (opcao)
        {

        // Inserir final
        case 1:
            if (!ponteiro_valido(lista_01))
            {
                printf("\nO ponteiro nao e valido.\n");
                system("pause");
                break;
            }

            system("cls");
            printf("\nInsira o valor que deseja inserir na lista: ");
            scanf("%d", &temp);

            status = inserir_final(lista_01, temp);
            if (status == FALSE)
            {
                system("cls");
                printf("\nNao foi possivel inserir o valor na lista pois ela se encontra cheia.\n");
            }
            system("pause");
            break;

        // Remover final
        case 2:
            if (!ponteiro_valido(lista_01))
            {
                printf("\nO ponteiro nao e valido.\n");
                system("pause");
                break;
            }

            system("cls");
            status = remover_final(lista_01, &temp);
            if (status == FALSE)
            {
                system("cls");
                printf("\nNao foi possivel remover o valor da lista pois ela se encontra vazia.\n");
            }
            else
            {
                printf("\nO valor removido da lista foi: %d\n", temp);
            }
            system("pause");
            break;

        // Imprimir lista
        case 3:
            if (!ponteiro_valido(lista_01))
            {
                printf("\nO ponteiro nao e valido.\n");
                system("pause");
                break;
            }
            system("cls");
            imprimir_lista(lista_01);
            system("pause");
            break;

        // Quantidade de elementos
        case 4:
            if (!ponteiro_valido(lista_01))
            {
                printf("\nO ponteiro nao e valido.\n");
                system("pause");
                break;
            }
            system("cls");
            temp = quantidade_elementos(lista_01);
            printf("\n%d elementos.", temp);
            system("pause");
            break;

        // Inserir posicao
        case 5:
            if (!ponteiro_valido(lista_01))
            {
                printf("\nO ponteiro nao e valido.\n");
                system("pause");
                break;
            }

            system("cls");
            printf("\nInsira o valor que deseja inserir na lista: ");
            scanf("%d", &temp);
            printf("\nInsira em qual posicao deseja inserir o valor na lista: ");
            scanf("%d", &temp2);

            status = inserir_posicao(lista_01, temp, temp2);
            if (status == FALSE)
            {
                system("cls");
                printf("\nNao foi possivel inserir o valor nesta posicao por um dos motivos:\n\n * Posicao anterior encontra-se vazia\n * Posicao nao encontrada");
            }
            system("pause");
            break;

        // Remover determinado valor
        case 6:
            if (!ponteiro_valido(lista_01))
            {
                printf("\nO ponteiro nao e valido.\n");
                system("pause");
                break;
            }
            printf("Insira o valor que deseja remover da lista: ");
            scanf("%d", &temp);
            system("cls");
            status = remover_chave(lista_01, temp);
            if (status == FALSE)
            {
                system("cls");
                printf("\nNao foi possivel remover o valor da lista pois ele nao foi encontrado ou a lista se encontra vazia.\n");
            }
            else
            {
                printf("\nO valor %d foi removido com sucesso.\n", temp);
            }
            system("pause");
            break;

        // Remover elemento da posicao
        case 7:
            if (!ponteiro_valido(lista_01))
            {
                printf("\nO ponteiro nao e valido.\n");
                system("pause");
                break;
            }
            printf("Insira a posicao que deseja remover da lista: ");
            scanf("%d", &temp);
            system("cls");
            status = remover_posicao(lista_01, temp, &temp2);
            if (status == FALSE)
            {
                system("cls");
                printf("\nNao foi possivel remover o valor desta posicao por um dos motivos:\n\n * Lista vazia\n * Posicao vazia\n * Posicao nao encontrada");
            }
            else
            {
                printf("\nO valor %d foi removido com sucesso.\n", temp2);
            }
            system("pause");
            break;
        }

    } while ((opcao != 0));
    system("cls");
    liberar_lista(lista_01);
    return 0;
}

s_lista *cria_lista()
{
    s_lista *temp;
    temp = (s_lista *)calloc(1, sizeof(s_lista));
    temp->fim = -1;
    return temp;
}

void liberar_lista(s_lista *lista)
{
    free(lista);
}

int lista_cheia(s_lista *lista)
{
    int tamanho = quantidade_elementos(lista);
    if (tamanho == MAX)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

int lista_vazia(s_lista *lista)
{
    int tamanho = quantidade_elementos(lista);
    if (tamanho == 0)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

int inserir_final(s_lista *lista, int valor)
{
    int status = lista_cheia(lista);
    if (status == TRUE)
    {
        return FALSE;
    }
    else
    {
        lista->fim++;
        lista->vetor[lista->fim] = valor;
        return TRUE;
    }
}

int remover_final(s_lista *lista, int *valor)
{
    int status = lista_vazia(lista);
    if (status == TRUE)
    {
        return FALSE;
    }
    else
    {
        *valor = lista->vetor[lista->fim];
        lista->vetor[lista->fim] = VAZIO;
        lista->fim--;
        return TRUE;
    }
}

int inserir_posicao(s_lista *lista, int valor, int posicao)
{
    if (posicao > MAX-1)
        return FALSE;

    if (lista->vetor[posicao-1] == VAZIO)
        return FALSE;

    else
    {

        for (int i = lista->fim; i >= posicao; i--)
        {
            lista->vetor[i + 1] = lista->vetor[i];
        }
        lista->vetor[posicao] = valor;
        lista->fim++;
        return TRUE;
    }
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

void imprimir_lista(s_lista *lista)
{
    printf("\n");
    for (int i = 0; i < MAX; i++)
    {
        printf("[%d] - %d\n", i, lista->vetor[i]);
    }
    printf("\nFim = %d", lista->fim);
    printf("\n");
}

int ponteiro_valido(s_lista *lista)
{
    if (lista == NULL)
    {
        return FALSE;
    }
    else
    {
        return TRUE;
    }
}

int quantidade_elementos(s_lista *lista)
{
    int elementos = 0;
    for (int i = 0; i <= MAX - 1; i++)
    {
        if (!(lista->vetor[i] == VAZIO))
        {
            elementos++;
        }
    }
    return elementos;
}

int remover_chave(s_lista *lista, int valor)
{
    int status = lista_vazia(lista);
    if (status == TRUE)
        return FALSE;

    else
    {
        for (int i = 0; i <= MAX - 1; i++)
        {
            if (lista->vetor[i] == valor)
            {
                for (int j = i; j <= lista->fim; j++)
                {
                    lista->vetor[j] = lista->vetor[j + 1];
                }
                lista->vetor[lista->fim] = VAZIO;
                lista->fim--;
                return TRUE;
            }
        }
        return FALSE;
    }
}

int remover_posicao(s_lista *lista, int posicao, int *valor)
{
    int status = lista_vazia(lista);
    if (status == TRUE)
        return FALSE;

    if (posicao > MAX-1)
        return FALSE;

    if (lista->vetor[posicao] == VAZIO)
        return FALSE;

    else
    {
        *valor = lista->vetor[posicao];
        for (int i = posicao; i <= lista->fim; i++)
        {
            lista->vetor[i] = lista->vetor[i + 1];
        }
        lista->vetor[lista->fim] = VAZIO;
        lista->fim--;
        return TRUE;
    }
}