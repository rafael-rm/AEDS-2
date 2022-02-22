#include "outros.h"
#include "monte_descarte.h"
#include "mao.h"
#include "jogo.h"
#include "logs.h"

void iniciar_logs()
{
    arquivo = fopen("logs.txt", "w+"); // Cria um arquivo vazio para escrita (apaga o anterior)
    if (arquivo == NULL)               // Erro no arquivo ou arquivo não encontrado
    {
        printf("\n [ERROR] Erro ao criar arquivo de log, processo encerrado.\n\n");
        system("pause > nul");
        exit(1);
    }

    // Biblioteca time.h (http://linguagemc.com.br/exibindo-data-e-hora-com-time-h/)
    struct tm *tempo;
    time_t segundos;
    time(&segundos);
    tempo = localtime(&segundos);

    fprintf(arquivo, "[%d/%d/%d - %d:%d:%d] - Arquivo de logs criado.\n", tempo->tm_mday, tempo->tm_mon + 1, tempo->tm_year + 1900, tempo->tm_hour, tempo->tm_min, tempo->tm_sec);
}

void logs_finalizar_jogo()
{
    struct tm *tempo;
    time_t segundos;
    time(&segundos);
    tempo = localtime(&segundos);
    fprintf(arquivo, "[%d/%d/%d - %d:%d:%d] - Jogo encerrado.\n", tempo->tm_mday, tempo->tm_mon + 1, tempo->tm_year + 1900, tempo->tm_hour, tempo->tm_min, tempo->tm_sec);
    fprintf(arquivo, "[%d/%d/%d - %d:%d:%d] - Encerrando arquivo de logs.\n", tempo->tm_mday, tempo->tm_mon + 1, tempo->tm_year + 1900, tempo->tm_hour, tempo->tm_min, tempo->tm_sec);
    fclose(arquivo);
}

void logs_registrar_jogada(int cor, int numero, int jogador)
{
    struct tm *tempo;
    time_t segundos;
    time(&segundos);
    tempo = localtime(&segundos);

    fprintf(arquivo, "[%d/%d/%d - %d:%d:%d] - Jogador %d jogou a carta %d %d no descarte.\n", tempo->tm_mday, tempo->tm_mon + 1, tempo->tm_year + 1900, tempo->tm_hour, tempo->tm_min, tempo->tm_sec, jogador + 1, cor, numero);
}

void logs_registrar_compra(int cor, int numero, int jogador)
{
    struct tm *tempo;
    time_t segundos;
    time(&segundos);
    tempo = localtime(&segundos);

    fprintf(arquivo, "[%d/%d/%d - %d:%d:%d] - Jogador %d comprou a carta %d %d do monte.\n", tempo->tm_mday, tempo->tm_mon + 1, tempo->tm_year + 1900, tempo->tm_hour, tempo->tm_min, tempo->tm_sec, jogador + 1, cor, numero);
}

void logs_criacao_monte(int cor, int numero)
{
    struct tm *tempo;
    time_t segundos;
    time(&segundos);
    tempo = localtime(&segundos);

    fprintf(arquivo, "[%d/%d/%d - %d:%d:%d] - Carta inserida %d %d no monte.\n", tempo->tm_mday, tempo->tm_mon + 1, tempo->tm_year + 1900, tempo->tm_hour, tempo->tm_min, tempo->tm_sec, cor, numero);
}

void logs_encerramento_partida(int vencedor, int perdedor, int pontos)
{
    struct tm *tempo;
    time_t segundos;
    time(&segundos);
    tempo = localtime(&segundos);

    fprintf(arquivo, "[%d/%d/%d - %d:%d:%d] - Partida finalizada.\n", tempo->tm_mday, tempo->tm_mon + 1, tempo->tm_year + 1900, tempo->tm_hour, tempo->tm_min, tempo->tm_sec);
    fprintf(arquivo, "[%d/%d/%d - %d:%d:%d] - O jogador %d foi o vencedor.\n", tempo->tm_mday, tempo->tm_mon + 1, tempo->tm_year + 1900, tempo->tm_hour, tempo->tm_min, tempo->tm_sec, vencedor);
    fprintf(arquivo, "[%d/%d/%d - %d:%d:%d] - O jogador %d foi o perdedor.\n", tempo->tm_mday, tempo->tm_mon + 1, tempo->tm_year + 1900, tempo->tm_hour, tempo->tm_min, tempo->tm_sec, perdedor);
    fprintf(arquivo, "[%d/%d/%d - %d:%d:%d] - Potuanção marcada pelo vencedor na partida: %d\n", tempo->tm_mday, tempo->tm_mon + 1, tempo->tm_year + 1900, tempo->tm_hour, tempo->tm_min, tempo->tm_sec, pontos);

    // fprintf(arquivo, "[%d/%d/%d - %d:%d:%d] - \n", tempo->tm_mday, tempo->tm_mon + 1, tempo->tm_year + 1900, tempo->tm_hour, tempo->tm_min, tempo->tm_sec);
}

void logs_partida_iniciada(int jogador_sorteado, int partidas_executadas)
{
    struct tm *tempo;
    time_t segundos;
    time(&segundos);
    tempo = localtime(&segundos);

    fprintf(arquivo, "[%d/%d/%d - %d:%d:%d] - Uma nova partida foi iniciada.\n", tempo->tm_mday, tempo->tm_mon + 1, tempo->tm_year + 1900, tempo->tm_hour, tempo->tm_min, tempo->tm_sec);
    fprintf(arquivo, "[%d/%d/%d - %d:%d:%d] - Totais de partidas executadas: %d.\n", tempo->tm_mday, tempo->tm_mon + 1, tempo->tm_year + 1900, tempo->tm_hour, tempo->tm_min, tempo->tm_sec, partidas_executadas);
    fprintf(arquivo, "[%d/%d/%d - %d:%d:%d] - O jogador %d foi sorteado para iniciar.\n", tempo->tm_mday, tempo->tm_mon + 1, tempo->tm_year + 1900, tempo->tm_hour, tempo->tm_min, tempo->tm_sec, jogador_sorteado);
}