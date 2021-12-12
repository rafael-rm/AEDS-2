#include <stdio.h>

int busca_sequencial(int valor_procurado, int vetor[], int tamanho);
int busca_binaria(int valor_procurado, int vetor[], int tamanho);
void preencher_vetor(int vetor[], int tamanho);
void ordenacao(int vetor[], int tamanho);
void imprimir_pontos(int vetor[], int tamanho);

int main()
{
    int tamanho;
    printf("Digite o tamanho do vetor a ser criado: ");
    scanf("%d", &tamanho);
    int *vetor = malloc(tamanho * sizeof(int));

    if (vetor == NULL)
    {
        printf("\n [ERROR] Memoria insuficiente, encerrando programa.\n\n");
        exit(1);
    }
    
    preencher_vetor(vetor, tamanho);

    int valor_procurado, indice_vetor_procurado;
    printf("\nInsira o valor que deseja procurar de forma sequencial no vetor: ");
    scanf("%d", &valor_procurado);
    indice_vetor_procurado = busca_sequencial(valor_procurado, vetor, tamanho);

    if (indice_vetor_procurado == -1)
    {
        printf("\nO valor nao foi encontrado no vetor.\n");
    }
    else
    {
        printf("\nO valor procurado encontra-se na posicao %d do vetor.\n", indice_vetor_procurado);
    }

    printf("\nVetores antes da ordenacao: \n");
    imprimir_pontos(vetor, tamanho);
    system("pause");
    ordenar(vetor, tamanho);
    printf("\nVetores apos a ordenacao: \n");
    imprimir_pontos(vetor, tamanho);
    system("pause");

    printf("\nInsira o valor que deseja procurar de forma binaria no vetor: ");
    scanf("%d", &valor_procurado);
    indice_vetor_procurado = busca_sequencial(valor_procurado, vetor, tamanho);

    if (indice_vetor_procurado == -1)
    {
        printf("\nO valor nao foi encontrado no vetor.\n");
    }
    else
    {
        printf("\nO valor procurado encontra-se na posicao %d do vetor.\n", indice_vetor_procurado);
    }
}

void preencher_vetor(int vetor[], int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        int valor;
        printf("Insira o valor do vetor na posicao %d: ", i);
        scanf("%d", &valor);
        vetor[i] = valor;
    }
}

int busca_sequencial(int valor_procurado, int vetor[], int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        if (vetor[i] == valor_procurado)
            return i;
    }
    return -1;
}

void ordenar(int vetor[], int tamanho)
{
    int i, j, aux;

    for (j = tamanho - 1; j > 0; j--)
    {
        for (i = 0; i < j; i++)
        {
            if (vetor[i + 1] < vetor[i])
            {
                aux = vetor[i];
                vetor[i] = vetor[i + 1];
                vetor[i + 1] = aux;
            }
        }
    }
}

void imprimir_pontos(int vetor[], int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        printf("\nVetor[%d] = %d", i, vetor[i]);
    }
    printf("\n\n");
}

int busca_binaria(int valor_procurado, int vetor[], int tamanho)
{
    int i;
    int esq = 0;
    int dir = tamanho - 1;
    do
    {
        i = (esq + dir) / 2;
        if (valor_procurado > vetor[i])
        {
            esq = i + 1;
        }
        else
        {
            dir = i - 1;
        }
    } while (valor_procurado != vetor[i] && esq <= dir);

    if (valor_procurado == vetor[i])
    {
        return i;
    }
    else
    {
        return -1;
    }
}