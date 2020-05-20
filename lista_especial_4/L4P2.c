//----------------------------------------------------------------
// Lista 4 - Problema 2
// Al Richard
//----------------------------------------------------------------
// Bibliotecas e Macros
//----------------------------------------------------------------

#include <stdio.h>
#define MAX 100

//----------------------------------------------------------------
// Prototipos
//----------------------------------------------------------------

void ler_matriz(int A[][MAX], int n);
void exibir_matriz(int A[][MAX], int n);
void somar(int A[][MAX], int B[][MAX], int n);
void multiplicar(int A[][MAX], int B[][MAX], int n);
void transposta(int A[][MAX], int n);

//----------------------------------------------------------------
// Funcao principal
//----------------------------------------------------------------

int main()
{
    // Declaracoes
    int n;
    int A[MAX][MAX], B[MAX][MAX];
    char opcao;
    
    // Entrada da dimensao
    printf("Entre com a dimensao da matriz quadrada: ");
    scanf(" %d", &n);
    printf("\n");
    
    // Entrada de A
    printf("Entre com os elementos da primeira matriz:\n");
    ler_matriz(A, n);
    
    printf("A =\n");
    exibir_matriz(A, n);
    
    // Entrada de operacao
    printf("Operacoes:\n");
    printf("A - Soma\n");
    printf("B - Multiplicacao\n");
    printf("C - Transposta\n");
    printf("Opcao desejada: ");
    scanf(" %c", &opcao);
    printf("\n");
    
    // Calcula transposta de A
    if (opcao == 'C')
    {
        printf("Transposta =\n");
        transposta(A, n);
    }
    else
    {
        // Entrada de B
        printf("Entre com os elementos da segunda matriz:\n");
        ler_matriz(B, n);
        
        printf("B =\n");
        exibir_matriz(B, n);
        
        // Calcula A + B
        if (opcao == 'A')
        {
            printf("Soma =\n");
            somar(A, B, n);
        }
        // Calcula A * B
        else if (opcao == 'B')
        {
            printf("Produto =\n");
            multiplicar(A, B, n);
        }
    }
   
    return 0;
}

//----------------------------------------------------------------
// Leitura de uma matriz
//----------------------------------------------------------------

void ler_matriz(int A[][MAX], int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            printf("Elemento da linha %d, coluna %d: ", i, j);
            scanf(" %d", &A[i][j]);
        }
    }
    printf("\n");
}

//----------------------------------------------------------------
// Exibicao de uma matriz
//----------------------------------------------------------------

void exibir_matriz(int A[][MAX], int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            printf("%d ", A[i][j]);
        printf("\n");
    }
    printf("\n");
}

//----------------------------------------------------------------
// Soma de matrizes
//----------------------------------------------------------------

void somar(int A[][MAX], int B[][MAX], int n)
{
    int C[MAX][MAX];
    
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            C[i][j] = A[i][j] + B[i][j];
    
    exibir_matriz(C, n);
}

//----------------------------------------------------------------
// Produto de matrizes
//----------------------------------------------------------------

void multiplicar(int A[][MAX], int B[][MAX], int n)
{
    int C[MAX][MAX];
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            C[i][j] = 0;
            for (int k = 1; k <= n; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
    }
    
    exibir_matriz(C, n);
}

//----------------------------------------------------------------
// Transposta de uma matriz
//----------------------------------------------------------------

void transposta(int A[][MAX], int n)
{
    int T[MAX][MAX];
    
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            T[i][j] = A[j][i];
    
    exibir_matriz(T, n);
}

//----------------------------------------------------------------
