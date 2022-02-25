#include "outros.h"
#include "monte_descarte.h"
#include "mao.h"
#include "jogo.h"
#include "logs.h"

s_pilha *inicializar_pilha()
{
    s_pilha *temp;
    temp = malloc(sizeof(s_pilha));
    temp->topo = NULL;
    temp->tamanho = 0;
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

// Gera todas as cartas para o monte
void iniciar_monte()
{
    monte = inicializar_pilha();
    s_carta *monte_temp;
    monte_temp = (s_carta *)calloc(MAX_CARTAS, sizeof(s_carta)); // A memoria será liberada na sequencia;
    int indice = 0;
    // Cartas comuns;
    for (int i = 1; i <= 4; i++) // Responsável pela cor das cartas (1 = VERDE; 2 = AMARELO; 3 = AZUL; 4 = VERMELHO);
    {
        for (int j = 0; j < 2; j++) // Responsável por inserir duas vezes uma carta de mesmo modelo;
        {
            for (int k = 0; k <= 12; k++) // Responsável pelo numero das cartas;
            {
                monte_temp[indice].cor = i;
                monte_temp[indice].numero = k;
                indice++;
            }
        }
    }

    // Cartas curingas;
    for (int i = 0; i < 2; i++) // Inserir 2 cartas curinga de cada;
    {
        for (int j = 13; j <= 15; j++) // (13 = COME_4; 14 = TROCAR_COR; 15 = TROCAR MAO);
        {
            monte_temp[indice].cor = CURINGA;
            monte_temp[indice].numero = j;
            indice++;
        }
    }

    // Aleatorizar posição das cartas;
    srand(time(NULL));
    int posicao1, posicao2;
    s_carta aux;
    for (int i = 0; i < 100; i++)
    {
        do
        {
            posicao1 = rand() % 110;
            posicao2 = rand() % 110;
        } while (posicao1 == posicao2);
        aux = monte_temp[posicao1];
        monte_temp[posicao1] = monte_temp[posicao2];
        monte_temp[posicao2] = aux;
    }

    // Enviar para a pilha;
    for (int i = 0; i < MAX_CARTAS; i++)
    {
        aux = monte_temp[i];
        status = empilha(monte, aux);
        if (status == FALSE)
        {
            system("cls");
            printf("\nOcorreu um erro ao inserir as cartas iniciais no monte.\n");
            exit(1);
        }
        printf("\n%d - Carta %d, %d inserida no monte", i, aux.cor, aux.numero);
        logs_criacao_monte(aux.cor, aux.numero);
    }
    free(monte_temp); // Memoria de uso temporario liberada;
}

void iniciar_descarte()
{
    descarte = inicializar_pilha();
    s_carta temp;
    temp.cor = VAZIO;
    temp.numero = VAZIO;
    empilha(descarte, temp);
}

int empilha(s_pilha *pilha, s_carta carta_recebida)
{
    int status = pilha_cheia();
    if (status == FALSE)
    {
        s_dados *temp;
        temp = (s_dados *)malloc(sizeof(s_dados));
        temp->carta = carta_recebida;
        if (pilha_vazia(pilha))
        {
            temp->anterior = NULL;
            pilha->topo = temp;
            pilha->tamanho++;
            return TRUE;
        }
        else
        {
            temp->anterior = pilha->topo;
            pilha->topo = temp;
            pilha->tamanho++;
            return TRUE;
        }
    }
    return FALSE;
}

int desempilha(s_pilha *pilha, s_carta *carta_retirar)
{
    s_dados *temp;
    temp = pilha->topo;
    if (pilha_vazia(pilha))
    {
        return FALSE;
    }
    *carta_retirar = temp->carta;
    pilha->topo = temp->anterior;
    pilha->tamanho--;
    return TRUE;
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

s_carta topo_pilha(s_pilha *pilha) // Retorna o topo da pilha, sem fazer sua remoção;
{
    s_dados *temp;
    temp = pilha->topo;
    return temp->carta;
}