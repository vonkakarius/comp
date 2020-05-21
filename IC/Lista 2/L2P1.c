//----------------------------------------------------------------
// Lista 2 - Problema 1
// Al Richard
//----------------------------------------------------------------

#include <stdio.h>

//----------------------------------------------------------------

int main()
{
    // Declaracoes
    int numeros[6];
    
    // Entrada
    printf("Digite 6 inteiros positivos: ");
    for (int i = 0; i < 6; i++)
        scanf(" %d", &numeros[i]);
    
    // Saida
    printf("Esses sao os impares na ordem inversa: ");
    for (int i = 5; i >= 0; i--)
        if (numeros[i] % 2 == 1)
            printf("%d ", numeros[i]);
    printf("\n");
    
    return 0;
}

//----------------------------------------------------------------
