/*
• Construa um TAD para trabalhar com pontos cartesianos:

• Crie o TAD (struct, além das operações que vão trabalhar com o TAD);

• Operações a serem criadas:

• Inicialização passando parâmetros;
• Inicialização fazendo a leitura dentro da função;
• Analisar qual o quadrante um ponto se encontra;
• Uma função que verifique se um determinado ponto passado por parâmetro está em
um determinado quadrante, também passado por parâmetro;
• Alterar os valores de um determinado ponto;
• Retornar qual a distância entre dois pontos;
• Retornar o maior valor de coordenada de um ponto;
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TRUE 1
#define FALSE 0

typedef struct s_ponto
{
    float x;
    float y;
} s_ponto;

int menu();
s_ponto inicializacao_parametros(float x, float y);
s_ponto leitura(int ponto_indice);
void imprimir_pontos(int total_pontos, s_ponto pontos[]);
int quadrante(float x, float y);
float maior_coordenada(float x, float y);
int quadrante_certo(float x, float y, int quadrante_proposto);
float distancia(float x1, float y1, float x2, float y2);
s_ponto alterar_valores(float x, float y);

int main()
{
    float x = 0, y = 0;
    int total_pontos;
    printf("\nQuantos pontos deseja criar: ");
    scanf("%d", &total_pontos);
    system("cls");

    s_ponto *pontos;
    pontos = (s_ponto *)calloc(total_pontos, sizeof(s_ponto));

    srand(time(NULL));

    for (int i = 0; i < total_pontos; i++) // Geração de números aleatorios com intuito de testes
    {
        x = rand() % 100;
        y = rand() % 100;
        pontos[i] = inicializacao_parametros(x, y);
    }

    for (int i = 0; i < total_pontos; i++)
    {
        pontos[i] = leitura(i);
    }

    int opcao, ponto_escolhido1, ponto_escolhido2;
    do
    {
        opcao = menu();
        printf("%d", opcao);
        switch (opcao)
        {

        // Verificar quadrante de um dos pontos;
        case 1:
            system("cls");
            imprimir_pontos(total_pontos, pontos);
            printf("\nQual dos pontos acima deseja verificar o quadrante?: ");
            scanf("%d", &ponto_escolhido1);

            x = pontos[ponto_escolhido1].x;
            y = pontos[ponto_escolhido1].y;

            int quadrante_do_ponto = quadrante(x, y);

            if (quadrante_do_ponto == -1)
                printf("\nO ponto se encontra no eixo das abscissas.");
            else if (quadrante_do_ponto == -2)
                printf("\nO ponto se encontra no eixo das ordenadas.");
            else if (quadrante_do_ponto == -3)
                printf("\nO ponto encontra-se no centro do plano cartesiano.");
            else
                printf("\nO ponto se encotra no %d quadrante.", quadrante_do_ponto);

            printf("\n\n");
            system("pause");
            break;

        // Verificar se o ponto inserido encontra-se no quadrante inserido
        case 2:
            system("cls");
            imprimir_pontos(total_pontos, pontos);
            printf("\nQual dos pontos acima deseja falar o quadrante: ");
            scanf("%d", &ponto_escolhido1);

            x = pontos[ponto_escolhido1].x;
            y = pontos[ponto_escolhido1].y;

            if (x == 0 || y == 0)
            {
                printf("O ponto se encontra em um dos eixos e por isso nao pertece a nenhum quadrante.\n\n");
                system("pause");
                break;
            }

            printf("Qual o quadrante do ponto %d (%.2f, %.2f): ", ponto_escolhido1, x, y);
            int quadrante_proposto;
            scanf("%d", &quadrante_proposto);

            int resposta = quadrante_certo(x, y, quadrante_proposto);
            printf("\n");
            if (resposta == TRUE)
            {
                printf("O ponto nas coordenadas (%.2f, %.2f) realmente se encontra no quadrante %d.", x, y, quadrante_proposto);
            }
            if (resposta == FALSE)
            {
                printf("O ponto nas coordenadas (%.2f, %.2f) nao se encontra no quadrante %d.", x, y, quadrante_proposto);
            }
            printf("\n\n");
            system("pause");
            break;

        // Alterar valor
        case 3:
            system("cls");
            imprimir_pontos(total_pontos, pontos);
            printf("\nQual dos pontos acima deseja alterar as coordenadas: ");
            scanf("%d", &ponto_escolhido1);
            printf("\nInsira as novas coordenadas do ponto (x, y): ");
            scanf("%f%f", &x, &y);
            pontos[ponto_escolhido1] = alterar_valores(x, y);
            printf("\nO ponto %d agora possui as seguintes coordenadas: (%.2f, %.2f)\n\n", ponto_escolhido1, pontos[ponto_escolhido1].x, pontos[ponto_escolhido1].y);
            system("pause");
            break;

        // Distancia entre 2 pontos
        case 4:
            system("cls");
            imprimir_pontos(total_pontos, pontos);
            printf("\nEscolha o primeiro ponto: ");
            scanf("%d", &ponto_escolhido1);
            printf("\nEscolha o segundo ponto: ");
            scanf("%d", &ponto_escolhido2);
            float x1 = pontos[ponto_escolhido1].x;
            float y1 = pontos[ponto_escolhido1].y;
            float x2 = pontos[ponto_escolhido2].x;
            float y2 = pontos[ponto_escolhido2].y;
            float dist = distancia(x1, y1, x2, y2);
            printf("\nA distancia entre os dois pontos e de %.2f unidades.\n\n", dist);
            system("pause");
            break;

        // Maior coordenada
        case 5:
            system("cls");
            imprimir_pontos(total_pontos, pontos);
            printf("\nQual dos pontos acima deseja saber a maior coordenada: ");
            scanf("%d", &ponto_escolhido1);
            x = pontos[ponto_escolhido1].x;
            y = pontos[ponto_escolhido1].y;
            float maior = maior_coordenada(x, y);
            printf("\nA maior coordenada do ponto %d e: %.2f\n\n", ponto_escolhido1, maior);
            system("pause");
            break;
        }
    } while ((opcao != 0));

    return 0;
}

int menu()
{
    int opcao_selecionada;
    do
    {
        system("cls");
        printf("\n");
        printf(" (1) - Verificar quandrante de um dos pontos\n");
        printf(" (2) - Inserir ponto e quadrante\n");
        printf(" (3) - Alterar coordenadas de um ponto\n");
        printf(" (4) - Distancia entre dois pontos\n");
        printf(" (5) - Maior coodernada de um ponto\n");
        printf(" (0) - Encerrar programa\n");

        printf("\nOpcao: ");
        scanf("%d", &opcao_selecionada);
        system("cls");
    } while (!(opcao_selecionada >= 0 && opcao_selecionada < 6));

    return opcao_selecionada;
}

s_ponto inicializacao_parametros(float x, float y)
{
    s_ponto temp;
    temp.x = x;
    temp.y = y;
    return temp;
}

s_ponto leitura(int ponto_indice)
{
    s_ponto temp;
    float x, y;
    printf("\nInsira as coordenadas do ponto %d (x, y): ", ponto_indice);
    scanf("%f%f", &x, &y);
    temp.x = x;
    temp.y = y;
    return temp;
}

void imprimir_pontos(int total_pontos, s_ponto pontos[])
{
    for (int i = 0; i < total_pontos; i++)
    {
        printf("Ponto [%d] - (%.2f, %.2f)\n", i, pontos[i].x, pontos[i].y);
    }
}

int quadrante(float x, float y)
{
    if (x == 0 && y == 0)
        return -3; // Centro do plano
    if (x == 0)
        return -1; // Eixo abscissa
    if (y == 0)
        return -2; // Eixo ordenada

    if (x > 0 && y > 0)
        return 1;
    if (x < 0 && y > 0)
        return 2;
    if (x < 0 && y < 0)
        return 3;
    if (x > 0 && y < 0)
        return 4;

    return 0;
}

int quadrante_certo(float x, float y, int quadrante_proposto)
{
    int quadrante_correto = quadrante(x, y);
    if (quadrante_proposto == quadrante_correto)
    {
        return TRUE;
    }
    else
        return FALSE;
}

float maior_coordenada(float x, float y)
{
    if (x > y)
        return x;
    if (y > x)
        return y;

    return 0;
}

float distancia(float x1, float y1, float x2, float y2)
{
    return fabs(sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)));
}

s_ponto alterar_valores(float x, float y)
{
    s_ponto temp;
    temp.x = x;
    temp.y = y;
    return temp;
}