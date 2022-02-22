#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10

void preencher_vetor(int vetor[], int n);
void imprimir_vetor(int vetor[], int n);
void particionar(int esq, int dir, int *i, int *j, int vetor[]);
void ordenar(int esq, int dir, int vetor[]);
void quicksort(int vetor[], int n);

int main()
{
    int vetor[TAM];
    preencher_vetor(vetor, TAM);
    system("pause>nul");
    printf("\n> Metodo Quick Sort<");
    quicksort(vetor, TAM);
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

void particionar(int esq, int dir, int *i, int *j, int vetor[])
{
    int x, temp;
    i = esq;
    j = dir;
    x = vetor[(*i + *j) / 2];
    do
    {
        while (x > vetor[*i])
        {
            i++;
        }
        while (x < vetor[*j])
        {
            j--;
        }

        if (i <= j)
        {
            temp = vetor[*i];
            vetor[*i] = vetor[*j];
            vetor[*j] = temp;
            i++;
            j--;
        }
    } while (i <= j);
}

void ordenar(int esq, int dir, int vetor[]){
    int i, j;
    particionar(esq, dir, &i, &j, vetor);
    if(esq < j) 
    ordenar(esq, j, vetor);
    if(i < dir) 
    ordenar(i, dir, vetor);
}

void quicksort(int vetor[], int n){
    ordenar(0, n=1, vetor);
}