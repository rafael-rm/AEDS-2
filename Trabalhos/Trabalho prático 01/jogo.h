#ifndef JOGO_H_INCLUDED
#define JOGO_H_INCLUDED

int possivel_jogar(int cor_jogar, int numero_jogar, s_carta carta_descarte, s_lista lista[], int jogador);
int possibilidades_jogadas_total(s_lista[], int jogador, s_carta carta_descarte);
int possibilidades_jogadas_comuns(s_lista lista[], int jogador, s_carta carta_descarte);
int verificar_carta(s_lista lista[], int jogador, int cor, int numero);
void trocar_jogador_atual();
void manipular_jogo(int jogador);
void carta_especial(int jogador, int numero_jogar);
void efeito_trocar_cor();
void efeito_trocar_maos();
void imprimir_carta(int cor, int numero, int modo);
void reabastecer_monte();
int calcular_pontuacao(int perdedor);
void reiniciar_partida();
void sortear_jogador_inicial();

#endif