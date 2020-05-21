//----------------------------------------------------------------
// Lista 5 - Problema 1
// Al Richard
//----------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//----------------------------------------------------------------

void mostrar(int passo, int i, int fim);

//----------------------------------------------------------------

int main(int argc, char *argv[])
{
    // Checa validez
    if (argc != 3)
    {
        printf("Utilize: ordenacao numero [\"crescente\"/\"decrescente\"]\n");
        return 0;
    }

    // Numero de repeticoes
    int n = atoi(argv[1]);

    // Mostra
    if (strcmp(argv[2], "crescente") == 0)
        mostrar(1, 1, n);
    else if (strcmp(argv[2], "decrescente") == 0)
        mostrar(-1, n, 1);

    return 0;
}

//----------------------------------------------------------------

void mostrar(int passo, int i, int fim)
{
    printf("%d\n", i);

    // Se nao terminou, chama o proximo
    if (i != fim)
        mostrar(passo, i + passo, fim);
}

//----------------------------------------------------------------
