#include <stdlib.h>
#include <stdio.h>

typedef struct s_dados
{
    char nome[50];
    int matricula;
    float nota[3];
    float media;
} dados;

void cadastrar_dados(dados alunos[], int tamanho);
int busca_sequencial(int valor_procurado, dados alunos[], int tamanho);
void imprimir_informacoes(int indice, dados alunos[]);
void ordenar(dados alunos[], int tamanho);
int busca_binaria(int valor_procurado, dados alunos[], int tamanho);

int main()
{
    int tamanho;
    printf("Quantos alunos deseja cadastrar no sistema? ");
    scanf("%d", &tamanho);

    dados *alunos;
    alunos = (dados *)calloc(tamanho, sizeof(dados));

    if (alunos == NULL)
    {
        printf("\n [ERROR] Memoria insuficiente, encerrando programa.\n\n");
        exit(1);
    }

    cadastrar_dados(alunos, tamanho);

    printf("\nDigite a matricula que deseja pesquisar de forma sequencial: ");
    int valor_procurado, indice_vetor_procurado;
    scanf("%d", &valor_procurado);
    indice_vetor_procurado = busca_sequencial(valor_procurado, alunos, tamanho);

    if (indice_vetor_procurado == -1)
    {
        printf("\nO valor nao foi encontrado no vetor, o aluno nao esta matriculado.\n");
    }
    else
    {
        printf("\nO valor procurado encontra-se na posicao %d do vetor.\n", indice_vetor_procurado);
        imprimir_informacoes(indice_vetor_procurado, alunos);
    }

    system("pause");
    system("cls");
    printf("\nStruct antes da ordenacao:\n");
    for (int i = 0; i < tamanho; i++)
    {
        imprimir_informacoes(i, alunos);
    }

    system("pause");
    system("cls");
    ordenar(alunos, tamanho);

    printf("\nStruct apos a ordenacao:\n");
    for (int i = 0; i < tamanho; i++)
    {
        imprimir_informacoes(i, alunos);
    }

    printf("\nDigite a matricula que deseja pesquisar de forma binaria: ");
    scanf("%d", &valor_procurado);
    indice_vetor_procurado = busca_binaria(valor_procurado, alunos, tamanho);

    if (indice_vetor_procurado == -1)
    {
        printf("\nO valor nao foi encontrado no vetor, o aluno nao esta matriculado.\n");
    }
    else
    {
        printf("\nO valor procurado encontra-se na posicao %d do vetor.\n", indice_vetor_procurado);
        imprimir_informacoes(indice_vetor_procurado, alunos);
    }
}

void cadastrar_dados(dados alunos[], int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        printf("\nCadastro [%02d]\n", i);
        printf("Insira o nome do aluno: ");
        setbuf(stdin, NULL);
        fgets(alunos[i].nome, 30, stdin);
        printf("Insira a matricula do aluno: ");
        scanf("%d", &alunos[i].matricula);
        alunos[i].media = 0;
        for (int j = 0; j < 3; j++)
        {
            printf("Insira a %do nota do aluno: ", j + 1);
            scanf("%f", &alunos[i].nota[j]);
            alunos[i].media += alunos[i].nota[j];
        }
        alunos[i].media = alunos[i].media / 3.0;
        printf("A media do aluno e de: %.2f\n", alunos[i].media);
    }
}

int busca_sequencial(int valor_procurado, dados alunos[], int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        if (alunos[i].matricula == valor_procurado)
            return i;
    }
    return -1;
}

void imprimir_informacoes(int indice, dados alunos[])
{
    printf("\nNome: %s", alunos[indice].nome);
    printf("Matricula: %d", alunos[indice].matricula);
    for (int i = 0; i < 3; i++)
    {
        printf("\nNota %02d: %.2f", i + 1, alunos[indice].nota[i]);
    }
    printf("\nMedia: %.2f\n\n", alunos[indice].media);
}

void ordenar(dados alunos[], int tamanho)
{
    int i, j;
    dados aux;

    for (j = tamanho - 1; j > 0; j--)
    {
        for (i = 0; i < j; i++)
        {
            if (alunos[i + 1].matricula < alunos[i].matricula)
            {
                aux = alunos[i];
                alunos[i] = alunos[i + 1];
                alunos[i + 1] = aux;
            }
        }
    }
}

int busca_binaria(int valor_procurado, dados alunos[], int tamanho)
{
    int i;
    int esq = 0;
    int dir = tamanho - 1;
    do
    {
        i = (esq + dir) / 2;
        if (valor_procurado > alunos[i].matricula)
        {
            esq = i + 1;
        }
        else
        {
            dir = i - 1;
        }
    } while (valor_procurado != alunos[i].matricula && esq <= dir);

    if (valor_procurado == alunos[i].matricula)
    {
        return i;
    }
    else
    {
        return -1;
    }
}