#include "outros.h"
#include "monte_descarte.h"
#include "mao.h"
#include "jogo.h"
#include "logs.h"

s_lista *criar_lista()
{
    s_lista *lista_temp;
    lista_temp = (s_lista *)calloc(2, sizeof(s_lista));
    lista_temp[0].fim = -1;
    lista_temp[0].tamanho = 0;
    lista_temp[1].fim = -1;
    lista_temp[1].tamanho = 0;
    return lista_temp;
}

void iniciar_maos()
{
    mao = criar_lista();

    // Distribuir as 7 cartas iniciais (mao 1);
    for (int i = 0; i < 2; i++)
    {

        for (int j = 0; j < 7; j++)
        {
            s_carta temp;
            status = desempilha(monte, &temp);
            if (status == FALSE)
            {
                printf("\n\nUm erro ocorreu desempilhar para a (mao 1).\n\n");
                exit(1);
            }
            else
            {
                lista_inserir_final(mao, i, temp);
                printf("\nCarta %d %d adicionada a mao %d", temp.cor, temp.numero, i);
            }
        }
    }
}

int lista_inserir_final(s_lista lista[], int jogador, s_carta carta)
{
    int status = lista_cheia(lista, jogador);
    if (status == TRUE)
    {
        return FALSE;
    }
    else
    {
        lista[jogador].fim++;
        lista[jogador].tamanho++;
        lista[jogador].carta[lista[jogador].fim] = carta;
        return TRUE;
    }
}

int remover_chave(s_lista lista[], int jogador, int cor, int numero)
{
    int status = lista_vazia(lista, jogador);
    if (status == TRUE)
        return FALSE;
    else
    {
        for (int i = 0; i <= MAX_CARTAS - 1; i++)
        {
            if (lista[jogador].carta[i].cor == cor && lista[jogador].carta[i].numero == numero)
            {
                for (int j = i; j <= lista[jogador].fim; j++)
                {
                    lista[jogador].carta[j] = lista[jogador].carta[j + 1];
                }
                lista[jogador].fim--;
                lista[jogador].tamanho--;
                return TRUE;
            }
        }
        return FALSE;
    }
}

/*void imprimir_lista(s_lista lista[], int jogador)
{
    printf("\n");
    for (int i = 0; i < lista[jogador].tamanho; i++)
    {
        printf("[%d] - %d, %d\n", i, lista[jogador].carta[i].cor, lista[jogador].carta[i].numero);
    }
    printf("\n");
}*/

void imprimir_lista(s_lista lista[], int jogador)
{
    printf("\n");
    for (int i = 0; i < lista[jogador].tamanho; i++)
    {
        imprimir_carta(lista[jogador].carta[i].cor, lista[jogador].carta[i].numero, 1);
    }
}

int lista_cheia(s_lista lista[], int jogador)
{
    int tamanho = lista[jogador].tamanho;
    if (tamanho == MAX_CARTAS)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

int lista_vazia(s_lista lista[], int jogador)
{
    int tamanho = lista[jogador].tamanho;
    if (tamanho == 0)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}
