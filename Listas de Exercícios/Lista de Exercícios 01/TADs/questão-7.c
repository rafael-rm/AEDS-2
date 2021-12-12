/*
Desenvolva um TAD para uma esfera. Inclua as funções de inicializações necessárias
e as operações que retornem seu raio, a sua área e o seu volume.
*/

#include <stdio.h>
#include <math.h>

typedef struct esfera
{
    float raio;
    float area;
    float volume;
} s_esfera;

s_esfera criaEsfera()
{
    s_esfera p;
    p.raio = 0;
    p.area = 0;
    p.volume = 0;
    return p;
}

s_esfera raioEsfera(s_esfera p)
{
    printf("Insira o raio da esfera: ");
    scanf("%f", &p.raio);
    return p;
}

s_esfera areaEsfera(s_esfera p)
{
    p.area = 4.0 * 3.141592654 * pow(p.raio, 2.0);
    return p;
}

s_esfera volumeEsfera(s_esfera p)
{
    p.volume = (4.0 / 3.0) * 3.141592654 * pow(p.raio, 3.0);
    return p;
}

void exibe(s_esfera p)
{
    printf("\nMedidas da esfera\n");
    printf("\nRaio: %.2f", p.raio);
    printf("\nArea: %.2f", p.area);
    printf("\nVolume: %.2f\n", p.volume);
}

int main()
{

    s_esfera esfera;
    esfera = criaEsfera();
    esfera = raioEsfera(esfera);
    esfera = areaEsfera(esfera);
    esfera = volumeEsfera(esfera);
    exibe(esfera);

    return 0;
}
