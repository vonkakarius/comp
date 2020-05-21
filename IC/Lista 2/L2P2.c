//----------------------------------------------------------------
// Lista 2 - Problema 2
// Al Richard
//----------------------------------------------------------------

#include <stdio.h>
#include <math.h>

//----------------------------------------------------------------

int main()
{
    // Declaracoes
    double pi = M_PI;
    double a[] = {.0, pi/6, pi/4, pi/3, pi/2};
    
    // Saida
    for (int i = 0; i < 5; i++)
    {
        printf("Angulo: %.3f\n", a[i]);
        printf("Seno: %.3f\n", sin(a[i]));
        printf("Cosseno: %.3f\n", cos(a[i]));
        printf("\n");
    }
    
    return 0;
}

//----------------------------------------------------------------
