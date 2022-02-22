#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10

void preencher_vetor(int vetor[], int n);
void bubble_sort(int vetor[], int n);
void imprimir_vetor(int vetor[], int n, int repeticoes);
void selecao(int vetor[], int n);
void insercao(int vetor[], int n);

int main()
{
    int vetor[TAM];
    preencher_vetor(vetor, TAM);
    system("pause>nul");
    printf("\n\nMetodo Bubble Sort\n");
    bubble_sort(vetor, TAM);
    system("pause>nul");
    system("cls");

    preencher_vetor(vetor, TAM);
    system("pause>nul");
    printf("\n\nMetodo Selecao\n");
    selecao(vetor, TAM);
    system("pause>nul");
    system("cls");

    preencher_vetor(vetor, TAM);
    system("pause>nul");
    printf("\n\nMetodo Insercao\n");
    insercao(vetor, TAM);
    system("pause>nul");
}

void preencher_vetor(int vetor[], int n)
{
    srand(time(NULL));
    printf("Vetor preenchido com: ");
    for (int i = 0; i < n; i++)
    {
        int temp = rand() % 50;
        // Gerando valores aleatórios na faixa de 0 a 50
        printf("%d ", temp);
        vetor[i] = temp;
    }
}

void imprimir_vetor(int vetor[], int n, int repeticoes)
{
    printf("\n[%d] - ", repeticoes - 1);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", vetor[i]);
    }
}

void bubble_sort(int vetor[], int n)
{
    int k, j, aux;
    for (k = 1; k < n; k++)
    {
        imprimir_vetor(vetor, n, k);
        for (j = 0; j < n - 1; j++)
        {

            if (vetor[j] > vetor[j + 1])
            {
                aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }
}

void selecao(int vetor[], int n)
{
    int i, j, minimo, temp;
    for (i = 0; i < n - 1; i++)
    {
        minimo = i;
        for (j = i + 1; j < n; j++)
        {
            if (vetor[minimo] > vetor[j])
            {
                minimo = j;
            }
        }
        temp = vetor[i];
        vetor[i] = vetor[minimo];
        vetor[minimo] = temp;
        imprimir_vetor(vetor, n, i + 1);
    }
}

void insercao(int vetor[], int n)
{
    int i, j, temp;
    for (i = 1; i < n; i++)
    {
        temp = vetor[i];
        j = i - 1;
        while (temp < vetor[j] && j >= 0)
        {
            vetor[j + 1] = vetor[j];
            j--;
        }
        vetor[j + 1] = temp;
        imprimir_vetor(vetor, n, i+1);
    }
}