//----------------------------------------------------------------
// Lista 6 - Problema 2
// Al Richard
//----------------------------------------------------------------

#include <stdio.h>
#define MAX 1000

//----------------------------------------------------------------

void imprimir_vetor(int *ptr, int tamanho);
void ordenar_crescente(int *ptr, int tamanho);
void ordenar_decrescente(int *ptr, int tamanho);

//----------------------------------------------------------------

int main()
{
    // Declaracoes
    int tamanho;
    int inteiros[MAX];
    
    // Entrada do tamanho
    printf("Digite o tamanho do vetor de inteiros: ");
    scanf(" %d", &tamanho);
    
    // Entrada do vetor
    for (int i = 0; i < tamanho; i++)
    {
        printf("Digite o elemento %d do vetor: ", i+1);
        scanf(" %d", &inteiros[i]);
    }
    printf("\n");
    
    // Mostra os numeros em ordem crescente
    printf("ORDEM CRESCENTE:\n");
    ordenar_crescente(inteiros, tamanho);
    printf("\n");
    
    // Mostra os numeros em ordem decrescente
    printf("ORDEM DECRESCENTE:\n");
    ordenar_decrescente(inteiros, tamanho);
    
    return 0;
}

//----------------------------------------------------------------

void imprimir_vetor(int *ptr, int tamanho)
{
    /*
    ptr: ponteiro pra primeira posicao do vetor
    tamanho: quantidade de numeros no vetor
    */
    
    // Mostra o vetor
    for (int i = 0; i < tamanho; i++)
        printf("%d ", *(ptr + i));
    printf("\n");
}

//----------------------------------------------------------------

void ordenar_crescente(int *ptr, int tamanho)
{
    /*
    ptr: ponteiro pra primeira posicao do vetor
    tamanho: quantidade de numeros no vetor
    */
    
    // Ordena pelo Bubble Sort
    for (int i = 0; i < tamanho-1; i++)
    {
        for (int j = 0; j < tamanho-i-1; j++)
        {
            // Ordem crescente
            if (*(ptr + j) > *(ptr + j + 1))
            {
                int temp = *(ptr + j);
                *(ptr + j) = *(ptr + j + 1);
                *(ptr + j + 1) = temp;
            }
        }
    }
    
    // E mostra
    imprimir_vetor(ptr, tamanho);
}

//----------------------------------------------------------------

void ordenar_decrescente(int *ptr, int tamanho)
{
    /*
    ptr: ponteiro pra primeira posicao do vetor
    tamanho: quantidade de numeros no vetor
    */
    
    // Ordena pelo Bubble Sort
    for (int i = 0; i < tamanho-1; i++)
    {
        for (int j = 0; j < tamanho-i-1; j++)
        {
            // Ordem decrescente
            if (*(ptr + j) < *(ptr + j + 1))
            {
                int temp = *(ptr + j);
                *(ptr + j) = *(ptr + j + 1);
                *(ptr + j + 1) = temp;
            }
        }
    }
    
    // E mostra
    imprimir_vetor(ptr, tamanho);
}

//----------------------------------------------------------------
