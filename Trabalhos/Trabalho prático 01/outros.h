#ifndef OUTROS_H_INCLUDED
#define OUTROS_H_INCLUDED

#define JOGADOR_1 0
#define JOGADOR_2 1

#define TRUE 1
#define FALSE 0

typedef struct jogador
{
  char nome[30];
  int idade;
  int pontuacao;
  int partidas_vencidas;
} s_jogador;

s_jogador player[2];
int jogador_atual;
int proximo_jogador;

void cadastrar();
void imprimir_jogador(int jogador);
void menu_principal();

#endif