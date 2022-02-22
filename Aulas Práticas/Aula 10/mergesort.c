#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10

void preencher_vetor(int vetor[], int n);
void imprimir_vetor(int vetor[], int n);
void intercala(int vetor[], int n);
void mergesort(int vetor[], int n);

int main()
{
    int vetor[TAM];
    preencher_vetor(vetor, TAM);
    system("pause>nul");
    printf("\n> Metodo Merge Sort <");
    mergesort(vetor, TAM);
    printf("\n\nOrdenacao final: ");
    imprimir_vetor(vetor, TAM);
    system("pause>nul");
    system("cls");
}

void preencher_vetor(int vetor[], int n)
{
    srand(time(NULL));
    printf("Ordenacao inicial: ");
    for (int i = 0; i < n; i++)
    {
        int temp = rand() % 50;
        // Gerando valores aleatórios na faixa de 0 a 50
        printf("%d ", temp);
        vetor[i] = temp;
    }
    printf("\n");
}

void imprimir_vetor(int vetor[], int n)
{
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", vetor[i]);
    }
}

void intercala(int vetor[], int n)
{
    int *temp = malloc(sizeof(int) * n);
    int meio = n / 2;
    int i = 0, j = meio, k = 0;

    while (i < meio && j < n)
    {
        if (vetor[i] < vetor[j])
        {
            temp[k] = vetor[i];
            i++;
        }
        else
        {
            temp[k] = vetor[j];
            j++;
        }
        k++;
    }
    if (i == meio)
    {
        while (j < n)
        {
            temp[k] = vetor[j];
            j++;
            k++;
        }
    }
    else
    {
        while (i < meio)
        {
            temp[k] = vetor[i];
            i++;
            k++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        vetor[i] = temp[i];
    }
    free(temp);
}

void mergesort(int vetor[], int n)
{
    imprimir_vetor(vetor, n);
    int meio;
    if (n > 1)
    {
        meio = n / 2;
        mergesort(vetor, meio);
        mergesort(vetor + meio, n - meio);
        intercala(vetor, n);
    }
}