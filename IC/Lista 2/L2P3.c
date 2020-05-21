//----------------------------------------------------------------
// Lista 2 - Problema 3
// Al Richard
//----------------------------------------------------------------

#include <stdio.h>

//----------------------------------------------------------------

int main()
{
    // Declaracoes
    char s[6];
    
    // Entrada
    printf("Digite 6 letras: ");
    for (int i = 0; i < 6; i++)
        scanf(" %c", &s[i]);
    
    // Minusculas
    printf("Minusculas (mesma ordem): ");
    for (int i = 0; i < 6; i++)
        if ('a' <= s[i] && s[i] <= 'z')
            printf("%c", s[i]);
    printf("\n");
    
    // Maiusculas
    printf("Maiusculas (ordem inversa): ");
    for (int i = 5; i >= 0; i--)
        if ('A' <= s[i] && s[i] <= 'Z')
            printf("%c", s[i]);
    printf("\n");
    
    return 0;
}

//----------------------------------------------------------------
