//----------------------------------------------------------------
// Lista 6 - Problema 3
// Al Richard
//----------------------------------------------------------------

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
    for (int i = 0; i < MAX; i++)
    {
        // Se ela e maiuscula, transforma em minuscula
        if (isupper(*(ptr + i)))
            *(ptr + i) = tolower(*(ptr + i));
    }
    
    // Mostra a string transformada
    printf("%s\n", ptr);
}

//----------------------------------------------------------------

void transformar_maiusculas(char *ptr)
{
    // Pra cada letra
    for (int i = 0; i < MAX; i++)
    {
        // Se ela e minuscula, transforma em maiuscula
        if (islower(*(ptr + i)))
            *(ptr + i) = toupper(*(ptr + i));
    }
    
    // Mostra a string transformada
    printf("%s\n", ptr);
}

//----------------------------------------------------------------

void transformar_camelcase(char *ptr)
{
    // Inicia um contador de posicao pra saber
    // onde inserir as letras transformadas
    int pos = 0;
    
    // Pra cada letra
    for (int i = 0; i < MAX; i++)
    {
        // Se for espaco, pula
        if (isspace(*(ptr + i)))
        {
            continue;
        }
        // Senao, se eh ela e a primeira da string, ou se o
        // que veio antes dela for um espaco, deixa maiuscula
        else if (i == 0 || isspace(*(ptr + i - 1)))
        {
            *(ptr + pos) = toupper(*(ptr + i));
        }
        // Senao, deixa minuscula
        else
        {
            *(ptr + pos) = tolower(*(ptr + i));
        }
        
        // Atualiza o contador de posicao
        pos++;
    }
    
    // Coloca o '\0' no final
    *(ptr + pos) = '\0';
    
    // Mostra a string transformada
    printf("%s\n", ptr);
}

//----------------------------------------------------------------
