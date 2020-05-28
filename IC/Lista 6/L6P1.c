//----------------------------------------------------------------
// Lista 6 - Problema 1
// Al Richard
//----------------------------------------------------------------

#include <stdio.h>

//----------------------------------------------------------------

int soma_min_max(int *min, int *max);

//----------------------------------------------------------------

int main()
{
    // Declaracoes
    int a, b;
    
    // Entrada
    printf("Digite o primeiro numero inteiro: ");
    scanf(" %d", &a);
    printf("Digite o segundo numero inteiro: ");
    scanf(" %d", &b);
    printf("\n");
    
    // Garante que o menor valor fique em a e o maior fique em b
    if (a > b)
    {
        // Trocando a e b se for preciso
        int temp = a;
        a = b;
        b = temp;
    }
    
    // Mostra minimo e maximo
    printf("Menor valor = %d\nMaior valor = %d\n", a, b);
    
    // Mostra soma
    printf("Soma = %d\n", soma_min_max(&a, &b));
    
    return 0;
}

//----------------------------------------------------------------

int soma_min_max(int *min, int *max)
{
    // Retorna a soma dos valores guardados nesses enderecos
    return *min + *max;
}

//----------------------------------------------------------------
