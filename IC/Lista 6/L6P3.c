//----------------------------------------------------------------
// Lista 6 - Problema 3
// Al Richard
//----------------------------------------------------------------

// MANEIRO, ELE LANÇOU O CONFLITO



// VISH, MUDEI COISA ONLINE

#include <stdio.h>
#include <ctype.h>
#define MAX 51

//----------------------------------------------------------------

void transformar_minusculas(char *ptr);
void transformar_maiusculas(char *ptr);
void transformar_camelcase(char *ptr);

//----------------------------------------------------------------

int main()
{
    // Declaracoes
    char string[MAX];
    
    // Entrada
    printf("Digite um texto de ate 50 caracteres:\n");
    scanf(" %[^\n]s", string);
    printf("\n");
    
    // Mostra em minusculas
    printf("TEXTO EM LETRAS MINUSCULAS:\n");
    transformar_minusculas(string);
    printf("\n");
    
    // Mostra em MAIUSCULAS
    printf("TEXTO EM LETRAS MAIUSCULAS:\n");
    transformar_maiusculas(string);
    printf("\n");
    
    // Mostra em CamelCase
    printf("TEXTO EM CAMELCASE:\n");
    transformar_camelcase(string);
    
    return 0;
}

//----------------------------------------------------------------

void transformar_minusculas(char *ptr)
{
    // Pra cada letra
    int i = 0;
    while (*(ptr + i) != '\0')
    {
        // Se ela e maiuscula, transforma em minuscula
        if (isupper(*(ptr + i)))
            *(ptr + i) = tolower(*(ptr + i));
        i++;
    }
    
    // Mostra a string transformada
    printf("%s\n", ptr);
}

//----------------------------------------------------------------

void transformar_maiusculas(char *ptr)
{
    // Pra cada letra
    int i = 0;
    while (*(ptr + i) != '\0')
    {
        // Se ela e minuscula, transforma em maiuscula
        if (islower(*(ptr + i)))
            *(ptr + i) = toupper(*(ptr + i));
        i++;
    }
    
    // Mostra a string transformada
    printf("%s\n", ptr);
}

//----------------------------------------------------------------

void transformar_camelcase(char *ptr)
{
    // Pra cada letra
    int i = 0;
    while (*(ptr + i) != '\0')
    {
        // Se for espaco, ignora
        if (isspace(*(ptr + i)))
        {
            i++;
            continue;
        }
        // Se inicia palavra, deixa maiuscula
        else if (i == 0 || isspace(*(ptr + i - 1)))
            printf("%c", (int) toupper(*(ptr + i)));
        // Senao, deixa minuscula
        else
            printf("%c", (int) tolower(*(ptr + i)));
        i++;
    }
    printf("\n");
}

//----------------------------------------------------------------
