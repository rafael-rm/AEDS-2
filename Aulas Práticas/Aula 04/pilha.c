#include <stdio.h>
#include <stdlib.h>

#define MAX 2 // O vetor se inicia em 0

#define FALSE 0
#define TRUE 1

typedef struct pilha
{
    int topo;
    int vetor[MAX];
} s_pilha;

s_pilha *cria_pilha();
void liberar_pilha(s_pilha *pilha);
void imprimir_pilha(s_pilha *pilha);
int empilha(s_pilha *pilha, int valor);
int desempilha(s_pilha *pilha, int *valor);
int pilha_cheia(s_pilha *pilha);
int pilha_vazia(s_pilha *pilha);
int ponteiro_valido(s_pilha *pilha);
int menu();

int main()
{
    s_pilha *pilha_01 = cria_pilha();
    int opcao, temp, status;
    do
    {
        opcao = menu();
        printf("%d", opcao);
        switch (opcao)
        {

        // Inserir
        case 1:
            if (!ponteiro_valido(pilha_01))
            {
                printf("\nO ponteiro nao e valido.\n");
                system("pause");
                break;
            }

            system("cls");
            printf("\nInsira o valor que deseja inserir na pilha: ");
            scanf("%d", &temp);

            status = empilha(pilha_01, temp);
            if (status == FALSE)
            {
                system("cls");
                printf("\nNao foi possivel inserir o valor na pilha pois ela se encontra cheia.\n");
            }
            system("pause");
            break;

        // Remover
        case 2:
            if (!ponteiro_valido(pilha_01))
            {
                printf("\nO ponteiro nao e valido.\n");
                system("pause");
                break;
            }

            system("cls");
            status = desempilha(pilha_01, &temp);
            if (status == FALSE)
            {
                system("cls");
                printf("\nNao foi possivel remover o valor da pilha pois ela se encontra vazia.\n");
            }
            else
            {
                printf("\nO valor removido da pilha foi: %d\n", temp);
            }
            system("pause");
            break;

        // Imprimir pilha
        case 3:
            if (!ponteiro_valido(pilha_01))
            {
                printf("\nO ponteiro nao e valido.\n");
                system("pause");
                break;
            }
            system("cls");
            imprimir_pilha(pilha_01);
            system("pause");
            break;
        }

    } while ((opcao != 0));
    system("cls");
    liberar_pilha(pilha_01);
    return 0;
}

s_pilha *cria_pilha()
{
    s_pilha *temp;
    temp = (s_pilha *)calloc(1, sizeof(s_pilha));
    temp->topo = -1;
    return temp;
}

void liberar_pilha(s_pilha *pilha)
{
    free(pilha);
}

int empilha(s_pilha *pilha, int valor)
{
    int status = pilha_cheia(pilha);
    if (status == TRUE)
    {
        return FALSE;
    }
    else
    {
        pilha->topo++;
        pilha->vetor[pilha->topo] = valor;
        return TRUE;
    }
}

int pilha_cheia(s_pilha *pilha)
{
    if (pilha->topo < MAX)
    {
        return FALSE;
    }
    else
    {
        return TRUE;
    }
}

int pilha_vazia(s_pilha *pilha)
{
    if (pilha->topo < 0)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

int menu()
{
    int opcao_selecionada;
    do
    {
        system("cls");
        printf("\n[1] Inserir elemento na pilha");
        printf("\n[2] Remover elemento da pilha");
        printf("\n[3] Imprimir elementos da pilha");
        printf("\n[0] Liberar memoria");
        printf("\n");
        printf("\nOpcao: ");
        scanf("%d", &opcao_selecionada);
        system("cls");
    } while (!(opcao_selecionada >= 0 && opcao_selecionada <= 3));

    return opcao_selecionada;
}

void imprimir_pilha(s_pilha *pilha)
{
    printf("\n");
    for (int i = 0; i < MAX + 1; i++)
    {
        printf("[%d] - %d\n", i, pilha->vetor[i]);
    }
    printf("\n");
}

int desempilha(s_pilha *pilha, int *valor)
{
    int status = pilha_vazia(pilha);
    if (status == TRUE)
    {
        return FALSE;
    }
    else
    {
        *valor = pilha->vetor[pilha->topo];
        pilha->topo--;
        return TRUE;
    }
}

int ponteiro_valido(s_pilha *pilha)
{
    if (pilha == NULL)
    {
        return FALSE;
    }
    else 
    {
        return TRUE;
    }
}