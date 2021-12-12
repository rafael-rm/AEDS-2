#include <stdio.h>
#include <stdlib.h>

#define MAX 2 // O vetor se inicia em 0

#define FALSE 0
#define TRUE 1

typedef struct fila
{
    int comeco;
    int final;
    int vetor[MAX];
} s_fila;

s_fila *cria_fila();
void liberar_fila(s_fila *fila);
void imprimir_fila(s_fila *fila);
int inserir(s_fila *fila, int valor);
int remover(s_fila *fila, int *valor);
int fila_cheia(s_fila *fila);
int fila_vazia(s_fila *fila);
int ponteiro_valido(s_fila *fila);
int menu();

int main()
{
    s_fila *fila_01;
    fila_01 = cria_fila();
    int opcao, temp, status;
    do
    {
        opcao = menu();
        printf("%d", opcao);
        switch (opcao)
        {

        // Inserir
        case 1:
            if (!ponteiro_valido(fila_01))
            {
                printf("\nO ponteiro nao e valido.\n");
                system("pause");
                break;
            }

            system("cls");
            printf("\nInsira o valor que deseja inserir na fila: ");
            scanf("%d", &temp);

            status = inserir(fila_01, temp);
            if (status == FALSE)
            {
                system("cls");
                printf("\nNao foi possivel inserir o valor na fila pois ela se encontra cheia.\n");
            }
            system("pause");
            break;

        // Remover
        case 2:
            if (!ponteiro_valido(fila_01))
            {
                printf("\nO ponteiro nao e valido.\n");
                system("pause");
                break;
            }

            system("cls");
            status = remover(fila_01, &temp);
            if (status == FALSE)
            {
                system("cls");
                printf("\nNao foi possivel remover o valor da fila pois ela se encontra vazia.\n");
            }
            else
            {
                printf("\nO valor removido da fila foi: %d\n", temp);
            }
            system("pause");
            break;

        // Imprimir fila
        case 3:
            if (!ponteiro_valido(fila_01))
            {
                printf("\nO ponteiro nao e valido.\n");
                system("pause");
                break;
            }
            system("cls");
            imprimir_fila(fila_01);
            system("pause");
            break;
        }

    } while ((opcao != 0));
    system("cls");
    liberar_fila(fila_01);
    return 0;
}

s_fila *cria_fila()
{
    s_fila *temp;
    temp = (s_fila *)calloc(1, sizeof(s_fila));
    temp->comeco = 0;
    temp->final = 0;
    return temp;
}

void liberar_fila(s_fila *fila)
{
    free(fila);
}

int inserir(s_fila *fila, int valor)
{
    int status = fila_cheia(fila);
    if (status == TRUE)
    {
        return FALSE;
    }
    else
    {
        fila->vetor[fila->final] = valor;
        fila->final++;
        return TRUE;
    }
}

int fila_cheia(s_fila *fila)
{
    if (fila->final <= MAX)
    {
        return FALSE;
    }
    else
    {
        return TRUE;
    }
}

int fila_vazia(s_fila *fila)
{
    if (fila->comeco >= fila->final)
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
        printf("\n[1] Inserir elemento na fila");
        printf("\n[2] Remover elemento da fila");
        printf("\n[3] Imprimir elementos da fila");
        printf("\n[0] Liberar memoria");
        printf("\n");
        printf("\nOpcao: ");
        scanf("%d", &opcao_selecionada);
        system("cls");
    } while (!(opcao_selecionada >= 0 && opcao_selecionada <= 3));

    return opcao_selecionada;
}

void imprimir_fila(s_fila *fila)
{
    printf("\n");
    for (int i = 0; i < MAX; i++)
    {
        if(i < fila->comeco)
        printf("[%d] - %d [ATENDIDO]\n", i, fila->vetor[i]);
        else
        printf("[%d] - %d\n", i, fila->vetor[i]);

    }
    printf("\n");
}

int remover(s_fila *fila, int *valor)
{
    int status = fila_vazia(fila);
    if (status == TRUE)
    {
        return FALSE;
    }
    else
    {
        *valor = fila->vetor[fila->comeco];
        fila->comeco++;
        return TRUE;
    }
}

int ponteiro_valido(s_fila *fila)
{
    if (fila == NULL)
    {
        return FALSE;
    }
    else 
    {
        return TRUE;
    }
}