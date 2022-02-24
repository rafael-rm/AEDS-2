#ifndef LOGS_H_INCLUDED
#define LOGS_H_INCLUDED

FILE *arquivo;

void criar_log();
void logs_finalizar_jogo(int vencedor, int perdedor, int partidas_executadas);
void logs_registrar_jogada(int cor, int numero, int jogador);
void logs_criacao_monte(int cor, int numero);
void logs_encerramento_partida(int vencedor, int perdedor, int pontos);
void logs_partida_iniciada(int jogador_sorteado, int partidas_executadas);
void logs_registrar_compra(int cor, int numero, int jogador);

#endif