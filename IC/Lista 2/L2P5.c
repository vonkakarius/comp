//----------------------------------------------------------------
// Lista 2 - Problema 5
// Al Richard
//----------------------------------------------------------------

#include <stdio.h>

//----------------------------------------------------------------

int main()
{
    // Listas
    int estrela[] = {5, 4, 5, 4, 2, 3, 4};
    int tempo[] = {5, 2, 3, 1, 2, 4, 3};
    
    // Notas
    int nota[7];
    
    for (int i = 0; i < 7; i++)
        nota[i] = estrela[i] + 6 - tempo[i];
    
    // Counting Sort
    int vezes[11], ord[7];
    for (int i = 0; i < 11; i++) vezes[i] = 0;
    
    for (int i = 0; i < 7; i++)
        vezes[nota[i]]++;
    
    int cont = 0;
    for (int i = 10; i >= 0; i--) {
        for (int j = 0; j < vezes[i]; j++) {
            ord[cont] = i;
            cont++;
        }
    }
    
    // Procura a nota campea
    int nota_campea = ord[0];
    char campeao;
    
    for (int i = 0; i < 7; i++)
        if (nota[i] == nota_campea)
            campeao = 'A' + i;
    
    // Mostra o campeao
    printf("O bizu e pedir na pizzaria %c\n", campeao);
    
    return 0;
}

//----------------------------------------------------------------
