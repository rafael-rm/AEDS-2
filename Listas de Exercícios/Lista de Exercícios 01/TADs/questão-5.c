/*
Desenvolva um TAD para um cubo. Inclua as funções de inicializações necessárias
e as operações que retornem os tamanhos de cada lado, a sua área e o seu volume.
*/

#include <stdio.h>
#include <math.h>

typedef struct cubo
{
    float aresta;
    float lado;
    float area;
    float volume;
} s_cubo;

s_cubo criaCubo()
{
    s_cubo p;
    p.aresta = 0;
    p.lado = 0;
    p.area = 0;
    p.volume = 0;
    return p;
}

s_cubo leAresta(s_cubo p)
{
    printf("Insira a medida da aresta: ");
    scanf("%f", &p.aresta);
    return p;
}

s_cubo ladoCubo(s_cubo p)
{
    p.lado = pow(p.aresta, 2.0);
    return p;
}

s_cubo areaCubo(s_cubo p)
{
    p.area = pow(p.aresta, 2.0) * 6;
    return p;
}

s_cubo volumeCubo(s_cubo p)
{
    p.volume = pow(p.aresta, 3.0);
    return p;
}

void exibe(s_cubo p)
{
    printf("\n> Medidas do cubo\n");
    printf("\nLado: %.2f", p.lado);
    printf("\nArea: %.2f", p.area);
    printf("\nVolume: %.2f\n", p.volume);
};

int main()
{
    s_cubo cubo;
    cubo = criaCubo();
    cubo = leAresta(cubo);
    cubo = ladoCubo(cubo);
    cubo = areaCubo(cubo);
    cubo = volumeCubo(cubo);
    exibe(cubo);
    return 0;
}
