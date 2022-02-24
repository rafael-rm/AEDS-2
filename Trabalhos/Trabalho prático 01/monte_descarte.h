#include <stdio.h>
#include <time.h>
#ifndef MONTE_DESCARTE_H_INCLUDED
#define MONTE_DESCARTE_H_INCLUDED

// Cores
#define CURINGA 0
#define VERDE 1
#define AMARELO 2
#define AZUL 3
#define VERMELHO 4

// Numeros (0 a 9 sem #define)
#define INVERTER 10
#define BLOQUEAR 11
#define COME_2 12
#define COME_4 13
#define TROCAR_COR 14
#define TROCAR_MAO 15

#define MAX_CARTAS 110
#define VAZIO -100

typedef struct carta
{
  int cor;
  int numero;
} s_carta;

typedef struct dados
{
  s_carta carta;
  struct dados *anterior;
} s_dados;

typedef struct pilha
{
  s_dados *topo;
  int tamanho;
} s_pilha;

s_pilha *monte;
s_pilha *descarte;
int status;

s_pilha *inicializar_pilha();
void iniciar_monte();
int empilha(s_pilha *pilha, s_carta carta_recebida);
int desempilha(s_pilha *pilha, s_carta *carta_retirar);
int pilha_cheia();
int pilha_vazia(s_pilha *pilha);
void iniciar_descarte();
void liberar_pilha(s_pilha *pilha);

#endif