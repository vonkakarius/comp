//----------------------------------------------------------------
// Lista 2 - Problema 4
// Al Richard
//----------------------------------------------------------------

#include <stdio.h>
#include <string.h>

//----------------------------------------------------------------

int main()
{
    // Recebe o tamanho
    int n;
    printf("Quantas letras tem a string que voce quer ordenar? ");
    scanf(" %d", &n);
    
    // Recebe a string
    char s[n+1];
    printf("Digita ela: ");
    scanf(" %s", s);
    
    // Bubble Sort
    printf("\nOrdenacao 1: (Bubble Sort - O(n^2))\n");
    
    char b[n+1], temp;
    strcpy(b, s);
    
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < n-i; j++) {
            if (b[j] > b[j+1]) {
                temp = b[j+1];
                b[j+1] = b[j];
                b[j] = temp;
            }
        }
    }
    
    for (int i = 0; i < n; i++)
        printf("%c", b[i]);
    printf("\n");
    
    // Insertion Sort
    printf("\nOrdenacao 2: (Insertion Sort - O(n^2))\n");
    
    char in[n+1], chave;
    strcpy(in, s);
    
    for (int i = 1; i < n; i++) {
        chave = in[i];
        int j = i - 1;
        while (j >= 0 && in[j] > chave) {
            in[j+1] = in[j];
            j--;
        }
        in[j+1] = chave;
    }
    
    for (int i = 0; i < n; i++)
        printf("%c", in[i]);
    printf("\n");
    
    // Counting Sort
    printf("\nOrdenacao 3: (Counting Sort - O(n))\n");
    
    int vezes[256];
    for (int i = 0; i < 256; i++)
        vezes[i] = 0;
        
    for (int i = 0; i < n; i++)
        vezes[s[i]]++;
    
    for (int i = 0; i < 256; i++)
        if (vezes[i] > 0)
            for (int j = 0; j < vezes[i]; j++)
                printf("%c", (char) i);
    printf("\n");
    
    return 0;
}

//----------------------------------------------------------------
