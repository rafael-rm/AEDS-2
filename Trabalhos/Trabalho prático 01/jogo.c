#include "outros.h"
#include "monte_descarte.h"
#include "mao.h"
#include "jogo.h"
#include "logs.h"

void manipular_jogo(int jogador) // Função usada para testes;
{
    mao[0].carta[0].cor = 0;
    mao[0].carta[0].numero = TROCAR_COR;
    mao[1].carta[0].cor = 0;
    mao[1].carta[0].numero = TROCAR_COR;
    mao[0].carta[0].cor = 0;
    mao[0].carta[0].numero = COME_4;
    mao[1].carta[0].cor = 0;
    mao[1].carta[0].numero = COME_4;
    mao[0].tamanho = 7;
    mao[0].fim = mao[jogador].tamanho - 1;
    mao[1].tamanho = 7;
    mao[1].fim = mao[jogador].tamanho - 1;
    player[jogador].pontuacao = 450;

    /*
    s_carta temp;
    temp.cor = 1;
    temp.numero = 1;
    empilha(descarte, temp);
    */
}

void sortear_jogador_inicial()
{
    srand(time(NULL));
    jogador_atual = rand() % 2;
    if (jogador_atual == 0)
        proximo_jogador = 1;
    if (jogador_atual == 1)
        proximo_jogador = 0;
}

void trocar_jogador_atual()
{
    int aux;
    aux = jogador_atual;
    jogador_atual = proximo_jogador;
    proximo_jogador = aux;
}

int possivel_jogar(int cor_jogar, int numero_jogar, s_carta carta_descarte, s_lista lista[], int jogador)
{
    int cor_descarte = carta_descarte.cor;
    int numero_descarte = carta_descarte.numero;
    int possibilidades_comuns = possibilidades_jogadas_comuns(lista, jogador, carta_descarte);

    // Verifica se é a primeira jogada
    if (primeira_jogada == TRUE)
    {
        if (cor_jogar == CURINGA || numero_jogar == COME_2 || numero_jogar == BLOQUEAR || numero_jogar == INVERTER)
        {
            return FALSE;
        }
        else
        {
            primeira_jogada = FALSE;
            return TRUE;
        }
    }

    // Carta combina com a do descarte;
    if ((cor_jogar == cor_descarte || numero_jogar == numero_descarte || carta_descarte.numero == TROCAR_MAO) && cor_jogar != CURINGA)
    {
        return TRUE;
    }

    // Jogar o COME 4;
    // Só é possivel jogar caso não tenha nenhuma carta comum que combine com o monte;
    if (cor_jogar == CURINGA && numero_jogar == COME_4)
    {
        if (possibilidades_comuns == 0)
            return TRUE;
    }

    // Trocar cor;
    // Sem restrição;
    if (cor_jogar == CURINGA && numero_jogar == TROCAR_COR)
    {
        return TRUE;
    }

    // Trocar mao;
    // Nao pode ser a ultima carta do jogador;
    if (cor_jogar == CURINGA && numero_jogar == TROCAR_MAO)
    {
        if (lista[jogador].tamanho > 1)
            return TRUE;
    }
    return FALSE;
}

int possibilidades_jogadas_total(s_lista lista[], int jogador, s_carta carta_descarte)
{
    int possibilidades = 0;
    int possibilidades_curinga = 0;

    if (primeira_jogada == TRUE)
    {
        for (int i = 0; i < lista[jogador].tamanho; i++)
        {
            if (!(lista[jogador].carta[i].cor == CURINGA || lista[jogador].carta[i].numero == INVERTER || lista[jogador].carta[i].numero == BLOQUEAR || lista[jogador].carta[i].numero == COME_2))
            {
                possibilidades++;
            }
        }
        return possibilidades;
    }
    else
    {
        // Cartas comuns;
        for (int i = 0; i < lista[jogador].tamanho; i++)
        {
            if (lista[jogador].carta[i].cor != CURINGA)
            {
                if (lista[jogador].carta[i].cor == carta_descarte.cor && lista[jogador].carta[i].numero == carta_descarte.numero)
                {
                    possibilidades++;
                }
                else if (lista[jogador].carta[i].cor == carta_descarte.cor)
                {
                    possibilidades++;
                }
                else if (lista[jogador].carta[i].numero == carta_descarte.numero)
                {
                    possibilidades++;
                }
                else if (carta_descarte.numero == TROCAR_MAO)
                {
                    possibilidades++;
                }
            }
        }

        // Cartas curingas;
        for (int i = 0; i < lista[jogador].tamanho; i++)
        {

            // COME 4 (NAO PODE SER JOGADA CASO TENHA UMA CARTA QUE COMBINE NO BARALHO)
            if (possibilidades == 0)
            {
                if (lista[jogador].carta[i].cor == CURINGA && lista[jogador].carta[i].numero == COME_4)
                    possibilidades_curinga++; // Usada outra variavel para nao atrapalhar a condição do primeiro if;
            }

            // TROCAR COR;
            if (lista[jogador].carta[i].cor == CURINGA && lista[jogador].carta[i].numero == TROCAR_COR)
            {
                possibilidades_curinga++;
            }

            // TROCAR MAO;
            if (lista[jogador].tamanho != 1)
            {
                if (lista[jogador].carta[i].cor == CURINGA && lista[jogador].carta[i].numero == TROCAR_MAO)
                    possibilidades_curinga++;
            }
        }

        // Isso ocorre para não haver uma falsa verificação na jogada do +4;
        possibilidades = possibilidades + possibilidades_curinga;

        return possibilidades;
    }
}

int possibilidades_jogadas_comuns(s_lista lista[], int jogador, s_carta carta_descarte) // Nao inclui as cartas curingas nas possibilidades;
{
    int possibilidades = 0;

    // Cartas comuns;
    for (int i = 0; i < lista[jogador].tamanho; i++)
    {
        if (lista[jogador].carta[i].cor != CURINGA)
        {
            if (lista[jogador].carta[i].cor == carta_descarte.cor && lista[jogador].carta[i].numero == carta_descarte.numero)
            {
                possibilidades++;
            }
            else if (lista[jogador].carta[i].cor == carta_descarte.cor)
            {
                possibilidades++;
            }
            else if (lista[jogador].carta[i].numero == carta_descarte.numero)
            {
                possibilidades++;
            }
        }
    }
    return possibilidades;
}

int verificar_carta(s_lista lista[], int jogador, int cor, int numero)
{
    int status = lista_vazia(lista, jogador);
    if (status == TRUE)
    {
        return FALSE;
    }
    else
    {
        for (int i = 0; i < lista[jogador].tamanho; i++)
        {
            if (lista[jogador].carta[i].cor == cor && lista[jogador].carta[i].numero == numero) // Verifica se o jogador possue a carta que esta tentando jogar;
            {
                return TRUE;
            }
        }
        return FALSE;
    }
}

void carta_especial(int jogador, int numero_jogar) // Responsável por executar/chamar os efeitos das cartas especiais;
{
    if (numero_jogar == INVERTER)
    {
        trocar_jogador_atual();
        printf("\nO jogador %d utilizou a carta INVERTER e por isso jogara novamente.\n", jogador + 1);
    }

    if (numero_jogar == BLOQUEAR)
    {
        trocar_jogador_atual();
        printf("\nO jogador %d utilizou a carta BLOQUEAR e por isso jogara novamente.\n", jogador + 1);
    }

    if (numero_jogar == COME_2)
    {
        printf("\n");
        efeito_come_dois();
        trocar_jogador_atual();
    }

    if (numero_jogar == COME_4)
    {
        printf("\n");
        efeito_come_quatro();
        efeito_trocar_cor();
    }

    if (numero_jogar == TROCAR_COR)
    {
        efeito_trocar_cor();
        printf("\nO jogador %d utilizou a carta TROCAR COR e trocou a cor da mesa.\n", jogador + 1);
    }

    if (numero_jogar == TROCAR_MAO)
    {
        efeito_trocar_maos();
        printf("\nO jogador %d utilizou a carta TROCAR MAOS e por isso os baralhos foram trocados.\n", jogador + 1);
    }
}

void efeito_come_dois()
{
    s_carta temp;
    for (int i = 0; i < 2; i++)
    {
        desempilha(monte, &temp);
        lista_inserir_final(mao, proximo_jogador, temp);
        printf("O jogador %d comeu a carta: ", proximo_jogador + 1);
        imprimir_carta(temp.cor, temp.numero, 2);
        logs_registrar_compra(temp.cor, temp.numero, proximo_jogador);
    }
}

void efeito_come_quatro()
{

    s_carta temp;
    s_carta come4_rival;
    come4_rival.cor = CURINGA;
    come4_rival.numero = COME_4;
    int rival_tem_come4 = FALSE;

    for (int i = 0; i < mao[proximo_jogador].tamanho; i++) // Verifica se o proximo jogador possui a carta COME 4;
    {

        if (mao[proximo_jogador].carta[i].numero == COME_4) // Caso o proximo jogador possua, o jogador atual deve comer 8 cartas;
        {
            rival_tem_come4 = TRUE;
            printf("\nO jogador %d possui uma carta CURINGA - COME 4 e por isso voce tera que comer 8 cartas.\n\n", proximo_jogador + 1);
            remover_chave(mao, proximo_jogador, CURINGA, COME_4); // Remove o +4 carta do proximo jogador;
            empilha(descarte, come4_rival);                       // Coloca o +4 do rival no monte;
            logs_registrar_jogada(come4_rival.cor, come4_rival.numero, proximo_jogador);
            for (int j = 0; j < 8; j++)                           // Faz com que o jogador inicial coma 8 cartas do monte;
            {
                desempilha(monte, &temp);
                lista_inserir_final(mao, jogador_atual, temp);
                printf("O jogador %d comeu a carta: ", jogador_atual + 1);
                imprimir_carta(temp.cor, temp.numero, 2);
                logs_registrar_compra(temp.cor, temp.numero, jogador_atual);
            }
        }
    }

    if (rival_tem_come4 == FALSE) // Caso o proximo jogador não tenha o COME 4 ele devera comer 4 cartas além de perder a vez;
    {
        for (int j = 0; j < 4; j++)
        {
            desempilha(monte, &temp);
            lista_inserir_final(mao, proximo_jogador, temp);
            printf("O jogador %d comeu a carta: ", proximo_jogador + 1);
            imprimir_carta(temp.cor, temp.numero, 2);
            logs_registrar_compra(temp.cor, temp.numero, proximo_jogador);
        }
        trocar_jogador_atual(); // Faz com que quem jogou o +4 consiga jogar novamente na sequencia;
    }
}

void efeito_trocar_cor()
{
    s_carta temp;
    int cor_nova;

    do
    {
        printf("\nInsira a nova cor da mesa: ");
        scanf("%d", &cor_nova);
        if (cor_nova < 1 || cor_nova > 4)
        {
            printf("(VERDE-1 AMARELO-2 AZUL-3 VERMELHO-4)\n");
            printf("Insira uma cor valida de 1 a 4: \n");
        }
    } while (cor_nova < 1 || cor_nova > 4);

    desempilha(descarte, &temp);
    temp.cor = cor_nova; // Ao inves da carta jogada ter a cor "CURINGA", ela passa a ter a cor desejada pelo jogador;
    empilha(descarte, temp);
}

void efeito_trocar_maos()
{
    s_carta temp[MAX_CARTAS]; // Memoria alocada temporariamente;
    int tamanho_mao_0 = mao[0].tamanho;
    int tamanho_mao_1 = mao[1].tamanho;
    for (int i = 0; i < MAX_CARTAS; i++)
    {
        temp[i] = mao[0].carta[i]; // Todas as cartas do vetor 0 são passadas para o vetor auxiliar
    }

    for (int i = 0; i < MAX_CARTAS; i++)
    {
        mao[0].carta[i] = mao[1].carta[i]; // As cartas do vetor 1 são passadas para o vetor 0;
    }

    mao[0].tamanho = tamanho_mao_1;
    mao[0].fim = tamanho_mao_1 - 1;

    for (int i = 0; i < MAX_CARTAS; i++)
    {
        mao[1].carta[i] = temp[i]; // As cartas do vetor auxiliar (vetor 0) são passadas para o vetor 1;
    }
    mao[1].tamanho = tamanho_mao_0;
    mao[1].fim = tamanho_mao_0 - 1;

    free(temp); // Memoria temporaria liberada;
}

void imprimir_carta(int cor, int numero, int modo)
{
    if (modo == 1)
    {
        // CORES
        if (cor == CURINGA)
            printf("CURINGA (0)   -  ");
        else if (cor == VERDE)
            printf("VERDE (1)     -  ");
        else if (cor == AMARELO)
            printf("AMARELO (2)   -  ");
        else if (cor == AZUL)
            printf("AZUL (3)      -  ");
        else if (cor == VERMELHO)
            printf("VERMELHO (4)  -  ");

        // ESTAMPAS
        if (numero < 10)
            printf("NUMERO %d (%d)", numero, numero);
        else if (numero == INVERTER)
            printf("INVERTER (10)");
        else if (numero == BLOQUEAR)
            printf("BLOQUEAR (11)");
        else if (numero == COME_2)
            printf("COME DOIS (12)");
        else if (numero == COME_4)
            printf("COME QUATRO (13)");
        else if (numero == TROCAR_COR)
            printf("TROCA COR (14)");
        else if (numero == TROCAR_MAO)
            printf("TROCA MAO (15)");
        printf("\n");
    }

    if (modo == 2)
    {
        // CORES
        if (cor == CURINGA)
            printf("CURINGA - ");
        else if (cor == VERDE)
            printf("VERDE - ");
        else if (cor == AMARELO)
            printf("AMARELO - ");
        else if (cor == AZUL)
            printf("AZUL - ");
        else if (cor == VERMELHO)
            printf("VERMELHO - ");
        else if (cor == VAZIO)
            printf("VAZIO - ");

        // ESTAMPAS
        if (numero <= 9 && numero >= 0)
            printf("NUMERO %d", numero);
        else if (numero == INVERTER)
            printf("INVERTER");
        else if (numero == BLOQUEAR)
            printf("BLOQUEAR");
        else if (numero == COME_2)
            printf("COME DOIS");
        else if (numero == COME_4)
            printf("COME QUATRO");
        else if (numero == TROCAR_COR)
            printf("TROCA COR");
        else if (numero == TROCAR_MAO)
            printf("TROCA MAO");
        else if (numero == VAZIO)
            printf("VAZIO");
        printf("\n");
    }
}

int calcular_pontuacao(int perdedor)
{
    int pontos = 0;
    for (int i = 0; i < mao[perdedor].tamanho; i++)
    {
        if (mao[perdedor].carta[i].numero <= 9) // CARTAS 0 A 9;
            pontos = pontos + 5;

        if (mao[perdedor].carta[i].numero == INVERTER || mao[perdedor].carta[i].numero == BLOQUEAR || mao[perdedor].carta[i].numero == COME_2) // BLOQUEAR E COME 2;
            pontos = pontos + 20;

        if (mao[perdedor].carta[i].numero == TROCAR_MAO || mao[perdedor].carta[i].numero == TROCAR_COR || mao[perdedor].carta[i].numero == COME_4) // TROCAR MAO E COME 4;
            pontos = pontos + 50;
    }
    return pontos;
}

void reabastecer_monte()
{

    s_carta temp;
    s_carta carta_topo = topo_pilha(descarte); // Salva a carta atual que se encontra no topo do descarte;
    s_carta cartas_embaralhar[MAX_CARTAS];
    int tamanho_descarte = descarte->tamanho;

    for (int i = 0; i < tamanho_descarte; i++)
    {
        desempilha(descarte, &temp);

        if(temp.cor != CURINGA && (temp.numero == COME_4 || temp.numero == TROCAR_COR))
            temp.cor = CURINGA; // Faz com que as cartas que tem a função de trocar cor voltem ao seu estado normal;

        cartas_embaralhar[i].cor = temp.cor;
        cartas_embaralhar[i].numero = temp.numero;
    }

    // Embaralhar cartas no vetor temporario antes de enviar para o monte
    srand(time(NULL));
    int posicao1, posicao2;
    s_carta aux;
    for (int i = 0; i < tamanho_descarte; i++)
    {
        do
        {
            posicao1 = rand() % tamanho_descarte;
            posicao2 = rand() % tamanho_descarte;
        } while (posicao1 == posicao2); // Não permite que a carta na mesma posição seja "movimentada"
        aux = cartas_embaralhar[posicao1];
        cartas_embaralhar[posicao1] = cartas_embaralhar[posicao2];
        cartas_embaralhar[posicao2] = aux;
    }

    // Enviar para a o monte;
    for (int i = 0; i < tamanho_descarte; i++)
    {
        aux = cartas_embaralhar[i];
        status = empilha(monte, cartas_embaralhar[i]);
        if (status == FALSE)
        {
            system("cls");
            printf("\nOcorreu um erro ao reabastecer as cartas no monte.\n");
            exit(1);
        }
    }
    free(cartas_embaralhar); // Memoria de uso temporario liberada;
    empilha(descarte, carta_topo); // Retorna a carta que anteriormente estava no topo do descarte;
    printf("\nO monte foi reabastecido com %d cartas.\n", tamanho_descarte);
}

void reiniciar_partida()
{
    // Liberando memoria do monte e descarte;
    liberar_pilha(descarte);
    liberar_pilha(monte);

    // Voltando para o inicio o fim e tamanho da mao dos jogadores;
    mao[0].tamanho = 0;
    mao[0].fim = -1;
    mao[1].tamanho = 0;
    mao[1].fim = -1;

    // Iniciando monte, descarte, e maos;
    iniciar_monte();
    iniciar_maos();
    iniciar_descarte();
    primeira_jogada = TRUE;

    // Sorteando o jogador que ira iniciar;
    sortear_jogador_inicial();
}