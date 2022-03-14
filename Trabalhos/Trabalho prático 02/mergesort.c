#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <windows.h>

#define ALEATORIO 1
#define ORDENADO 2
#define INV_ORDENADO 3

#define TAMANHO_1 1000
#define TAMANHO_2 10000
#define TAMANHO_3 100000
#define TAMANHO_4 200000

void alocar_vetor(int tamanho);
void preencher_vetor(int modo, int tamanho);
void intercala(int vetor[], int n);
void mergesort(int vetor[], int n);
void imprimir_vetor(int vetor[], int n);
void criar_logs();

int *vetor;
FILE *arquivo;
long long movimentacoes, comparacoes;

int main()
{
    int tamanho;
    long long mov_med = 0;
    long long comp_med = 0;
    float tempo_med = 0;
    criar_logs();
    clock_t process_start, process_start_total;
    clock_t process_end, process_end_total;

    process_start_total = clock();

    //
    // METODO ALEATORIO
    //
    for (int j = 1; j <= 4; j++)
    {
        mov_med = 0;
        tempo_med = 0;

        // Definir o tamanho do vetor (1k 10k 100k 200k)
        if (j == 1)
            tamanho = TAMANHO_1;
        if (j == 2)
            tamanho = TAMANHO_2;
        if (j == 3)
            tamanho = TAMANHO_3;
        if (j == 4)
            tamanho = TAMANHO_4;

        for (int i = 1; i <= 10; i++)
        {
            movimentacoes = 0;
            comparacoes = 0;
            alocar_vetor(tamanho);
            preencher_vetor(ALEATORIO, tamanho);
            process_start = clock(); // Inicia a contagem de tempo
            mergesort(vetor, tamanho);
            process_end = clock() - process_start; // Finaliza a contagem de tempo

            fprintf(arquivo, "[MERGESORT] - ALEATORIO #%d (%d) - Tempo de processamento gasto: %.4fs\n", i, tamanho, process_end / (double)CLOCKS_PER_SEC);
            fprintf(arquivo, "[MERGESORT] - ALEATORIO #%d (%d) - Movimentações de registros: %lld\n", i, tamanho, movimentacoes);
            fprintf(arquivo, "[MERGESORT] - ALEATORIO #%d (%d) - Comparações de chaves: %lld\n", i, tamanho, comparacoes);

            printf("[MERGESORT] - ALEATORIO #%d (%d) - Tempo de processamento gasto: %.4fs\n", i, tamanho, process_end / (double)CLOCKS_PER_SEC);
            printf("[MERGESORT] - ALEATORIO #%d (%d) - Movimentacoes de registros: %lld\n", i, tamanho, movimentacoes);
            printf("[MERGESORT] - ALEATORIO #%d (%d) - Comparacoes de chaves: %lld\n", i, tamanho, comparacoes);

            tempo_med += process_end / (double)CLOCKS_PER_SEC;
            mov_med += movimentacoes;
            comp_med += comparacoes;
        }
        tempo_med = tempo_med / 10;
        mov_med = mov_med / 10;
        comp_med = comp_med / 10;

        fprintf(arquivo, "\n[MERGESORT] - ALEATORIO (%d) - Tempo médio de processamento gasto: %.4fs\n", tamanho, tempo_med);
        fprintf(arquivo, "[MERGESORT] - ALEATORIO (%d) - Média de movimentações de registros: %lld\n", tamanho, mov_med);
        fprintf(arquivo, "[MERGESORT] - ALEATORIO (%d) - Média de comparações de chaves: %lld\n\n", tamanho, comp_med);

        printf("\n[MERGESORT] - ALEATORIO (%d) - Tempo medio de processamento gasto: %.4f\n", tamanho, tempo_med);
        printf("[MERGESORT] - ALEATORIO (%d) - Media de movimentacoes de registros: %lld\n", tamanho, mov_med);
        printf("[MERGESORT] - ALEATORIO (%d) - Media de comparacoes de chaves: %lld\n\n", tamanho, comp_med);
    }

    //
    // METODO ORDENADO
    //
    fprintf(arquivo, "\n\n");
    printf("\n\n");
    for (int j = 1; j <= 4; j++)
    {

        if (j == 1)
            tamanho = TAMANHO_1;
        if (j == 2)
            tamanho = TAMANHO_2;
        if (j == 3)
            tamanho = TAMANHO_3;
        if (j == 4)
            tamanho = TAMANHO_4;

        movimentacoes = 0;
        comparacoes = 0;
        alocar_vetor(tamanho);
        preencher_vetor(ORDENADO, tamanho);
        process_start = clock();
        mergesort(vetor, tamanho);
        process_end = clock() - process_start;

        fprintf(arquivo, "[MERGESORT] - ORDENADO (%d) - Tempo de processamento gasto: %.4fs\n", tamanho, process_end / (double)CLOCKS_PER_SEC);
        fprintf(arquivo, "[MERGESORT] - ORDENADO (%d) - Movimentações de registros: %lld\n", tamanho, movimentacoes);
        fprintf(arquivo, "[MERGESORT] - ORDENADO (%d) - Comparações de chaves: %lld\n", tamanho, comparacoes);

        printf("[MERGESORT] - ORDENADO (%d) - Tempo de processamento gasto: %.4fs\n", tamanho, process_end / (double)CLOCKS_PER_SEC);
        printf("[MERGESORT] - ORDENADO (%d) - Movimentacoes de registros: %lld\n", tamanho, movimentacoes);
        printf("[MERGESORT] - ORDENADO (%d) - Comparacoes de chaves: %lld\n", tamanho, comparacoes);
    }

    //
    // METODO INVERSAMENTE ORDENADO
    //
    fprintf(arquivo, "\n\n\n");
    printf("\n\n\n");
    for (int j = 0; j < 4; j++)
    {

        if (j == 0)
            tamanho = TAMANHO_1;
        else if (j == 1)
            tamanho = TAMANHO_2;
        else if (j == 2)
            tamanho = TAMANHO_3;
        else if (j == 3)
            tamanho = TAMANHO_4;

        movimentacoes = 0;
        comparacoes = 0;
        alocar_vetor(tamanho);
        preencher_vetor(INV_ORDENADO, tamanho);
        process_start = clock();
        mergesort(vetor, tamanho);
        process_end = clock() - process_start;

        fprintf(arquivo, "[MERGESORT] - INV ORDENADO (%d) - Tempo de processamento gasto: %.4fs\n", tamanho, process_end / (double)CLOCKS_PER_SEC);
        fprintf(arquivo, "[MERGESORT] - INV ORDENADO (%d) - Movimentações de registros: %lld\n", tamanho, movimentacoes);
        fprintf(arquivo, "[MERGESORT] - INV ORDENADO (%d) - Comparações de chaves: %lld\n", tamanho, comparacoes);

        printf("[MERGESORT] - INV ORDENADO (%d) - Tempo de processamento gasto: %.4fs\n", tamanho, process_end / (double)CLOCKS_PER_SEC);
        printf("[MERGESORT] - INV ORDENADO (%d) - Movimentacoes de registros: %lld\n", tamanho, movimentacoes);
        printf("[MERGESORT] - INV ORDENADO (%d) - Comparacoes de chaves: %lld\n", tamanho, comparacoes);
    }

    process_end_total = clock() - process_start_total;
    fprintf(arquivo, "\n\n[MERGESORT] - TOTAL - Tempo de processamento gasto: %.4fs\n", process_end_total / (double)CLOCKS_PER_SEC);
    printf("\n\n[MERGESORT] - TOTAL - Tempo de processamento gasto: %.4fs\n", process_end_total / (double)CLOCKS_PER_SEC);
    fclose(arquivo);
}

void alocar_vetor(int tamanho)
{
    free(vetor);                           // Libera a memoria anterior do vetor
    vetor = malloc(tamanho * sizeof(int)); // Aloca a memoria seguindo o tamanho da chamada da função

    if (vetor == NULL)
    {
        printf("\n [ERROR] Memoria insuficiente, encerrando programa.\n");
        system("pause");
        exit(1);
    }
}

void preencher_vetor(int modo, int tamanho)
{
    // Preenche o vetor com o modo determinado na chamada da função (aleatorio, ordenado e inv ordenado)

    if (modo == ALEATORIO)
    {
        srand(time(NULL));
        for (int i = 0; i < tamanho; i++)
        {
            vetor[i] = rand() % 32767;
        }
    }

    if (modo == ORDENADO)
    {
        for (int i = 0; i < tamanho; i++)
        {
            vetor[i] = i;
        }
    }

    if (modo == INV_ORDENADO)
    {
        int cont = -1;
        for (int i = tamanho; i > 0; i--)
        {
            cont++;
            vetor[cont] = i;
        }
    }
}

void intercala(int vetor[], int n)
{
    int *temp = malloc(sizeof(int) * n);
    int meio = n / 2;
    int i = 0, j = meio, k = 0;

    while (i < meio && j < n)
    {
        comparacoes++;
        comparacoes++;
        if (vetor[i] < vetor[j])
        {
            temp[k] = vetor[i];
            i++;
            movimentacoes++;
        }
        else
        {
            temp[k] = vetor[j];
            j++;
            movimentacoes++;
        }
        k++;
    }
    comparacoes++;
    if (i == meio)
    {
        while (j < n)
        {
            temp[k] = vetor[j];
            j++;
            k++;
            movimentacoes++;
        }
    }
    else
    {
        while (i < meio)
        {
            temp[k] = vetor[i];
            i++;
            k++;
            movimentacoes++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        vetor[i] = temp[i];
        movimentacoes++;
    }
    free(temp);
}

void mergesort(int vetor[], int n)
{
    int meio;
    comparacoes++;
    if (n > 1)
    {
        meio = n / 2;
        mergesort(vetor, meio);
        mergesort(vetor + meio, n - meio);
        intercala(vetor, n);
    }
}

void criar_logs()
{
    arquivo = fopen("./logs/merge.log", "w+"); // Cria um arquivo vazio para escrita (apaga o anterior)
    if (arquivo == NULL)                           // Erro no arquivo ou arquivo não encontrado
    {
        printf("\n [ERROR] Erro ao criar arquivo de log, processo encerrado.\n\n");
        system("pause > nul");
        exit(1);
    }
    fprintf(arquivo, "[MERGESORT] - Arquivo de logs criado.\n");
}

void imprimir_vetor(int vetor[], int n)
{
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", vetor[i]);
    }
}