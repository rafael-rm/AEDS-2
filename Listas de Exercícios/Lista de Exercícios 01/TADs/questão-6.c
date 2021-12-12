/*
6. Desenvolva um TAD para um cilindro. Inclua as funções de inicializações necessárias
e as operações que retornem sua altura e raio, a sua área e o seu volume.
*/

#include <stdio.h>
#include <math.h>

typedef struct cilindro
{
    float altura;
    float raio;
    float area;
    float volume;
} s_cilindro;

s_cilindro criacilindro()
{
    s_cilindro p;
    p.altura = 0;
    p.raio = 0;
    p.area = 0;
    p.volume = 0;
    return p;
}

s_cilindro alturacilindro(s_cilindro p)
{
    printf("Insira a altura do cilindro: ");
    scanf("%f", &p.altura);
    return p;
}

s_cilindro raiocilindro(s_cilindro p)
{
    printf("Insira o raio do cilindro: ");
    scanf("%f", &p.raio);
    return p;
}

s_cilindro areacilindro(s_cilindro p)
{
    p.area = 2.0 * 3.141592654 * p.raio * p.altura + 2.0 * (3.141592654 * pow(p.raio, 2.0));
    return p;
}

s_cilindro volumecilindro(s_cilindro p)
{
    p.volume = 3.141592654 * pow(p.raio, 2.0) * p.altura;
    return p;
}

void exibe(s_cilindro p)
{
    printf("\n> Medidas do cilindro\n");
    printf("\nAltura: %.2f", p.altura);
    printf("\nRaio: %.2f", p.raio);
    printf("\nArea: %.2f", p.area);
    printf("\nVolume: %.2f\n", p.volume);
}

int main()
{
    s_cilindro cilindro;
    cilindro = criacilindro();
    cilindro = alturacilindro(cilindro);
    cilindro = raiocilindro(cilindro);
    cilindro = areacilindro(cilindro);
    cilindro = volumecilindro(cilindro);
    exibe(cilindro);
    return 0;
}
