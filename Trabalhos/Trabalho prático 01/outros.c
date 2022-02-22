#include "outros.h"
#include "monte_descarte.h"
#include "mao.h"
#include "jogo.h"
#include "logs.h"

void inicializar_jogadores(s_jogador *player)
{
    for (int i = 0; i < 2; i++)
    {
        player[i].pontuacao = 0;
        player[i].partidas_vencidas = 0;
    }
}

void cadastrar()
{
    inicializar_jogadores(player);
    for (int i = 0; i < 2; i++)
    {
        setbuf(stdin, NULL);
        printf("\n * Dados do jogador %d ", i + 1);
        printf("\n\nNome: ");
        fgets(player[i].nome, sizeof(player[i].nome), stdin);
        printf("Idade: ");
        scanf("%d", &player[i].idade);
        system("cls");
    }
}

void imprimir_jogador(int jogador)
{

    printf("\n * Dados do jogador %d\n\n", jogador + 1);
    printf("Nome: %s", player[jogador].nome);
    printf("Idade: %d\n", player[jogador].idade);
}

void gotoxy(int x, int y)
{
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), (COORD){x - 1, y - 1});
}

void menu_principal()
{
    // Coloca o CMD em tela cheia (windows.h)
    keybd_event(VK_MENU, 0x36, 0, 0);
    keybd_event(VK_RETURN, 0x1C, 0, 0);
    keybd_event(VK_RETURN, 0x1C, KEYEVENTF_KEYUP, 0);
    keybd_event(VK_MENU, 0x38, KEYEVENTF_KEYUP, 0);

    gotoxy(118, 28);
    printf("UNO");
    gotoxy(100, 30);
    printf("Aperte qualquer tecla para iniciar jogo...");
    system("pause >nul"); // Pause sem mensagem
    system("cls");
}
