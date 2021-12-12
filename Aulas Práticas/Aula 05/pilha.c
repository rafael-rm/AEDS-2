#include <stdio.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE 1

typedef struct dados
{
    int valor;
    struct dados *anterior;
} s_dados;

typedef struct pilha
{
    s_dados *topo;
} s_pilha;

s_pilha *cria_pilha();
void liberar_pilha(s_pilha *pilha);
int empilha(s_pilha *pilha, int valor);
int desempilha(s_pilha *pilha, int *valor);
int pilha_cheia();
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
    temp = malloc(sizeof(s_pilha));
    temp->topo = NULL;

    return temp;
}

void liberar_pilha(s_pilha *pilha)
{
    if (pilha_vazia(pilha))
    {
        do
        {
            s_dados *temp;
            temp = pilha->topo;
            pilha->topo = temp->anterior;
            free(temp);
        } while (pilha->topo != NULL);
    }
    free(pilha);
}

int empilha(s_pilha *pilha, int valor)
{
    int status = pilha_cheia(pilha);
    if (status == FALSE)
    {
        s_dados *temp;
        temp = (s_dados *)malloc(sizeof(s_dados));
        temp->valor = valor;

        if (pilha_vazia(pilha))
        {
            temp->anterior = NULL;
            pilha->topo = temp;
            return TRUE;
        }
        else
        {
            temp->anterior = pilha->topo;
            pilha->topo = temp;
            return TRUE;
        }
    }
    return FALSE;
}

int pilha_cheia()
{
    s_dados *temp;
    temp = (s_dados *)malloc(sizeof(s_dados));

    if (temp == NULL)
    {
        free(temp);
        return TRUE;
    }
    else
    {
        free(temp);
        return FALSE;
    }
}

int pilha_vazia(s_pilha *pilha)
{
    if (pilha->topo == NULL)
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

int desempilha(s_pilha *pilha, int *valor)
{
    s_dados *temp;
    temp = pilha->topo;
    if (pilha_vazia(pilha))
    {
        return FALSE;
    }
    *valor = temp->valor;
    pilha->topo = temp->anterior;
    return TRUE;
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