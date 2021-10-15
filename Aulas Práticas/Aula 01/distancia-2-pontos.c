/*
 Faça um programa que leia dois pontos do plano 
cartesiano, calcule a distancia entre eles e imprima o 
resultado na tela
*/

#include <stdio.h>
#include <math.h>

typedef struct sponto
{
    float x;
    float y;
} sponto;

float distancia(sponto pontoA, sponto pontoB);

int main()
{
    sponto pontoA, pontoB;
    printf("\nInsira as coordenadas do ponto A (x y): ");
    scanf("%f%f", &pontoA.x, &pontoA.y);
    printf("\nInsira as coordenadas do ponto B (x y): ");
    scanf("%f%f", &pontoB.x, &pontoB.y);

    float dist = distancia(pontoA, pontoB);
    printf("\n\nA distancia e de: %.2f", dist);

    return 0;

}

float distancia(sponto pontoA, sponto pontoB)
{
    return fabs(sqrt(pow(pontoB.x - pontoA.x, 2) + pow(pontoB.y - pontoA.y, 2)));
}