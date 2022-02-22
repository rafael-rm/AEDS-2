#ifndef MAO_H_INCLUDED
#define MAO_H_INCLUDED

typedef struct lista{
    s_carta carta[MAX_CARTAS];
    int tamanho;
    int fim;
} s_lista;

s_lista *mao;

void iniciar_maos();
s_lista *criar_lista();
//void liberar_lista(s_lista lista[]);
int quantidade_elementos(s_lista lista[]);
void imprimir_lista(s_lista lista[], int jogador);
int lista_inserir_final(s_lista lista[], int jogador, s_carta carta);
//int remover_final(s_lista lista[], int *valor);
//int inserir_posicao(s_lista lista[], int valor, int posicao);
int lista_cheia(s_lista lista[], int jogador);
int lista_vazia(s_lista lista[], int jogador);
//int ponteiro_valido(s_lista lista[]);
int remover_chave(s_lista lista[], int jogador, int cor, int numero);
//int remover_posicao(s_lista lista[], int posicao, int *valor);
int menu();

#endif