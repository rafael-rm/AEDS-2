#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "outros.c"
#include "monte_descarte.c"
#include "mao.c"
#include "jogo.c"
#include "logs.c"

int main()
{
  s_carta carta_descarte, carta_temporaria;
  int cor_jogar, numero_jogar;
  int jogada_valida;
  int status;
  int partidas_executadas = 1;

  iniciar_logs();
  //menu_principal();
  //cadastrar();
  iniciar_monte();
  iniciar_maos();
  iniciar_descarte();
  sortear_jogador_inicial();
  logs_partida_iniciada(jogador_atual, partidas_executadas);

  manipular_jogo(jogador_atual);

  do
  {
    do
    {
      do
      {

        carta_descarte = topo_pilha(descarte);
        int possibilidades = possibilidades_jogadas_total(mao, jogador_atual, carta_descarte);
        system("cls");

        // REMOVER ABAIXO NA VERSÃO FINAL
        s_carta temp_compra = topo_pilha(monte);
        printf("\n    DEBUG IGNORE");
        printf("\nPartidas executadas: %d", partidas_executadas);
        printf("\nPontos jogador 1: %d", player[JOGADOR_1].pontuacao);
        printf("\nPontos jogador 2: %d", player[JOGADOR_2].pontuacao);
        printf("\nMao 1 tamanho: %d", mao[0].tamanho);
        printf("\nMao 2 tamanho: %d", mao[1].tamanho);
        printf("\nMonte tamanho: %d", monte->tamanho);
        printf("\nMonte carta: %d %d", carta_descarte.cor, carta_descarte.numero);
        printf("\nDescarte tamanho: %d", descarte->tamanho);
        printf("\nProxima compra: %d %d", temp_compra.cor, temp_compra.numero);
        printf("\n    DEBUG IGNORE\n");
        // REMOVER ACIMA NA VERSÃO FINAL

        printf("\nJogador atual: %d", jogador_atual + 1);
        printf("\nPossiveis jogadas: %d\n", possibilidades);
        printf("\n         Suas cartas");
        imprimir_lista(mao, jogador_atual);
        printf("\n");
        printf("Carta no descarte: ");
        imprimir_carta(carta_descarte.cor, carta_descarte.numero, 2);

        if (possibilidades == 0) // Caso não tenha nenhuma possibilidade de jogar, o jogo inicia a compra automaticamente;
        {
          if (monte->tamanho == 0)
          {
            reabastecer_monte(); // Necessário polimentos;
            Sleep(3000);
          }
          printf("\nVoce nao tem nenhuma carta para jogar, por isso tera que comprar do monte.\n\n");
          desempilha(monte, &carta_temporaria);
          Sleep(2000);
          printf("Voce comprou a carta: ");
          imprimir_carta(carta_temporaria.cor, carta_temporaria.numero, 2);
          printf("\n");
          lista_inserir_final(mao, jogador_atual, carta_temporaria);
          logs_registrar_compra(carta_temporaria.cor, carta_temporaria.numero, jogador_atual);
          Sleep(3000);
        }
        else
        {

          printf("Insira a carta que deseja jogar: ");
          scanf("%d %d", &cor_jogar, &numero_jogar);

          status = verificar_carta(mao, jogador_atual, cor_jogar, numero_jogar); // Verifica se a pessoa tem a carta que deseja jogar;
          if (status == TRUE)
          {
            status = possivel_jogar(cor_jogar, numero_jogar, carta_descarte, mao, jogador_atual); // Verifica se a carta e compativel com o descarte;
            if (status == TRUE)
            {
              remover_chave(mao, jogador_atual, cor_jogar, numero_jogar); // Remove carta da mao;
              s_carta carta_empilhar;
              carta_empilhar.cor = cor_jogar;
              carta_empilhar.numero = numero_jogar;
              empilha(descarte, carta_empilhar); // Insere carta no descarte;
              logs_registrar_jogada(cor_jogar, numero_jogar, jogador_atual);
              carta_especial(jogador_atual, numero_jogar);
              jogada_valida = TRUE;
              Sleep(2000);
            }
            else
            {
              printf("\nEssa jogada nao e possivel, tente novamente\n\n");
              Sleep(2000);
            }
          }
          else
          {
            printf("\nVoce nao possui a carta que deseja jogar, tente novamente.\n\n");
            Sleep(2000);
          }
        }

      } while (!(jogada_valida == TRUE));
      jogada_valida = FALSE;
      trocar_jogador_atual();
    } while (!(mao[0].tamanho == 0 || mao[1].tamanho == 0));

    /*
    CALCULAR A PONTUAÇÃO DO GANHADOR
    VERIFICAR SE ALGUM JOGADOR CHEGOU A PONTUAÇÃO DE 500
    CASO SIM, ENCERRAR O JOGO
    CASO NÃO, INICIAR OUTRA PARTIDA
    */

    int vencedor, perdedor;
    if (mao[0].tamanho == 0)
    {
      vencedor = JOGADOR_1;
      perdedor = JOGADOR_2;
    }
    else if (mao[1].tamanho == 0)
    {
      vencedor = JOGADOR_2;
      perdedor = JOGADOR_1;
    }

    player[vencedor].partidas_vencidas++;
    int pontos_marcados = calcular_pontuacao(perdedor);
    player[vencedor].pontuacao = player[vencedor].pontuacao + pontos_marcados;

    logs_encerramento_partida(vencedor, perdedor, pontos_marcados);

    system("cls");
    printf("\nPartida encerrada!");
    printf("\n\nO jogador %d foi o vencedor desta partida.", vencedor + 1);
    printf("\nPontos marcados nesta partida: %d", pontos_marcados);
    printf("\nPontos totais: %d/500", player[vencedor].pontuacao);
    printf("\n\nAperte qualquer tecla para continuar");
    system("pause > nul");

    if (player[0].pontuacao < 500 && player[1].pontuacao < 500)
    {
      reiniciar_partida();
      partidas_executadas++;
      logs_partida_iniciada(jogador_atual, partidas_executadas);

      system("cls");
      printf("\nUma nova partida foi iniciada!");
      printf("\nO jogador %d foi sorteado para iniciar as jogadas.", jogador_atual + 1);
      printf("\n\nAperte qualquer tecla para continuar");
      system("pause > nul");
      system("cls");
    }

  } while (!(player[0].pontuacao >= 500 || player[1].pontuacao >= 500));

  int vencedor_jogo, perdedor_jogo;

  if (player[0].pontuacao >= 500)
  {
    vencedor_jogo = JOGADOR_1;
    perdedor_jogo = JOGADOR_2;
  }
  else if (player[1].pontuacao >= 500)
  {
    vencedor_jogo = JOGADOR_2;
    perdedor_jogo = JOGADOR_1;

  }

  system("cls");
  printf("\nO jogador %d foi o primeiro a atingir 500 pontos e venceu o jogo!", vencedor_jogo);
  printf("\nObrigado por jogar =)\n");
  logs_finalizar_jogo(vencedor_jogo, perdedor_jogo, partidas_executadas);
  return 0;
}
