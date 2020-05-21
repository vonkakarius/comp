//----------------------------------------------------------------
// Lista 3 - Problema 1
// Al Richard
//----------------------------------------------------------------

#include <stdio.h>
#include <string.h>

//----------------------------------------------------------------

int main()
{
    // Declaracoes
    char frase[] = "E CHEGA DE DISPUTAR ESSA RUA COM A MONICA!! EU PODEREI COMPRAR QUANTAS RUAS EU QUISER!! PODEREI COMPRAR AVENIDAS INTEIRAS!! BAIRROS!! CIDADES!! PLANETAS!!";
    int n = strlen(frase), pos = -1;
    
    // Traduz
    for (int i = 0; i < n; i++)
    {
        // Incrementa a posicao pra adicionar a proxima letra
        pos++;
        
        // Se nao for R, ou estiver no fim de uma palavra
        if (frase[i] != 'R' || i == n || frase[i+1] < 'A' || 'Z' < frase[i+1])
        {
            frase[pos] = frase[i];
            continue;
        }
        
        // Senao, troca por L
        frase[pos] = 'L';
        
        // E se o proximo for outro R, pula ele
        if (i < n-1 && frase[i+1] == 'R')
            i++;
    }
    
    // Mostra
    printf("%s\n", frase);
    
    return 0;
}

//----------------------------------------------------------------
