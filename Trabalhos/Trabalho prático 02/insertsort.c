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
void insercao(int vetor[], int n);
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
            insercao(vetor, tamanho);
            process_end = clock() - process_start; // Finaliza a contagem de tempo

            fprintf(arquivo, "[INSERÇÃO] - ALEATORIO #%d (%d) - Tempo de processamento gasto: %.4fs\n", i, tamanho, process_end / (double)CLOCKS_PER_SEC);
            fprintf(arquivo, "[INSERÇÃO] - ALEATORIO #%d (%d) - Movimentações de registros: %lld\n", i, tamanho, movimentacoes);
            fprintf(arquivo, "[INSERÇÃO] - ALEATORIO #%d (%d) - Comparações de chaves: %lld\n", i, tamanho, comparacoes);

            printf("[INSERCAO] - ALEATORIO #%d (%d) - Tempo de processamento gasto: %.4fs\n", i, tamanho, process_end / (double)CLOCKS_PER_SEC);
            printf("[INSERCAO] - ALEATORIO #%d (%d) - Movimentacoes de registros: %lld\n", i, tamanho, movimentacoes);
            printf("[INSERCAO] - ALEATORIO #%d (%d) - Comparacoes de chaves: %lld\n", i, tamanho, comparacoes);

            tempo_med += process_end / (double)CLOCKS_PER_SEC;
            mov_med += movimentacoes;
            comp_med += comparacoes;
        }
        tempo_med = tempo_med / 10;
        mov_med = mov_med / 10;
        comp_med = comp_med / 10;

        fprintf(arquivo, "\n[INSERÇÃO] - ALEATORIO (%d) - Tempo médio de processamento gasto: %.4fs\n", tamanho, tempo_med);
        fprintf(arquivo, "[INSERÇÃO] - ALEATORIO (%d) - Média de movimentações de registros: %lld\n", tamanho, mov_med);
        fprintf(arquivo, "[INSERÇÃO] - ALEATORIO (%d) - Média de comparações de chaves: %lld\n\n", tamanho, comp_med);

        printf("\n[INSERCAO] - ALEATORIO (%d) - Tempo medio de processamento gasto: %.4f\n", tamanho, tempo_med);
        printf("[INSERCAO] - ALEATORIO (%d) - Media de movimentacoes de registros: %lld\n", tamanho, mov_med);
        printf("[INSERCAO] - ALEATORIO (%d) - Media de comparacoes de chaves: %lld\n\n", tamanho, comp_med);
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
        insercao(vetor, tamanho);
        process_end = clock() - process_start;

        fprintf(arquivo, "[INSERÇÃO] - ORDENADO (%d) - Tempo de processamento gasto: %.4fs\n", tamanho, process_end / (double)CLOCKS_PER_SEC);
        fprintf(arquivo, "[INSERÇÃO] - ORDENADO (%d) - Movimentações de registros: %lld\n", tamanho, movimentacoes);
        fprintf(arquivo, "[INSERÇÃO] - ORDENADO (%d) - Comparações de chaves: %lld\n", tamanho, comparacoes);

        printf("[INSERCAO] - ORDENADO (%d) - Tempo de processamento gasto: %.4fs\n", tamanho, process_end / (double)CLOCKS_PER_SEC);
        printf("[INSERCAO] - ORDENADO (%d) - Movimentacoes de registros: %lld\n", tamanho, movimentacoes);
        printf("[INSERCAO] - ORDENADO (%d) - Comparacoes de chaves: %lld\n", tamanho, comparacoes);
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
        insercao(vetor, tamanho);
        process_end = clock() - process_start;

        fprintf(arquivo, "[INSERÇÃO] - INV ORDENADO (%d) - Tempo de processamento gasto: %.4fs\n", tamanho, process_end / (double)CLOCKS_PER_SEC);
        fprintf(arquivo, "[INSERÇÃO] - INV ORDENADO (%d) - Movimentações de registros: %lld\n", tamanho, movimentacoes);
        fprintf(arquivo, "[INSERÇÃO] - INV ORDENADO (%d) - Comparações de chaves: %lld\n", tamanho, comparacoes);

        printf("[INSERCAO] - INV ORDENADO (%d) - Tempo de processamento gasto: %.4fs\n", tamanho, process_end / (double)CLOCKS_PER_SEC);
        printf("[INSERCAO] - INV ORDENADO (%d) - Movimentacoes de registros: %lld\n", tamanho, movimentacoes);
        printf("[INSERCAO] - INV ORDENADO (%d) - Comparacoes de chaves: %lld\n", tamanho, comparacoes);
    }

    process_end_total = clock() - process_start_total;
    fprintf(arquivo, "\n\n[INSERÇÃO] - TOTAL - Tempo de processamento gasto: %.4fs\n", process_end_total / (double)CLOCKS_PER_SEC);
    printf("\n\n[INSERCAO] - TOTAL - Tempo de processamento gasto: %.4fs\n", process_end_total / (double)CLOCKS_PER_SEC);
    fclose(arquivo);
}

void alocar_vetor(int tamanho)
{
    free(vetor); // Libera a memoria anterior do vetor
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

void insercao(int vetor[], int n)
{
    int i, j, temp;
    for (i = 1; i < n; i++)
    {
        temp = vetor[i];
        j = i - 1;
        comparacoes++;
        while (temp < vetor[j] && j >= 0)
        {
            movimentacoes++;
            comparacoes++;
            vetor[j + 1] = vetor[j];
            j--;
        }
        vetor[j + 1] = temp;
    }
}

void criar_logs()
{
    arquivo = fopen("./logs/insert.log", "w+"); // Cria um arquivo vazio para escrita (apaga o anterior)
    if (arquivo == NULL)                 // Erro no arquivo ou arquivo não encontrado
    {
        printf("\n [ERROR] Erro ao criar arquivo de log, processo encerrado.\n\n");
        system("pause > nul");
        exit(1);
    }
    fprintf(arquivo, "[INSERÇÃO] - Arquivo de logs criado.\n");
}

void imprimir_vetor(int vetor[], int n)
{
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", vetor[i]);
    }
}