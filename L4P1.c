//----------------------------------------------------------------
// Lista 4 - Problema 1
// Al Richard
//----------------------------------------------------------------

#include <stdio.h>

//----------------------------------------------------------------

int converter(int num_antes, int base_origem, int base_destino);

//----------------------------------------------------------------

int main()
{
    // Variaveis
    int op, dec, bin;
    char repete = 'S';
    
    // Loop
    while (repete == 'S' || repete == 's')
    {
        // Cabecalho
        printf("Escolha a opcao desejada:\n");
        printf("1 - Converter de binario para decimal\n");
        printf("2 - Converter de decimal para binario:\n");
        printf("Opcao: ");
        
        // Entrada
        scanf(" %d", &op);
        
        // Processamento
        switch (op)
        {
            case 1:
                // Entrada
                printf("Entre com o numero binario: ");
                scanf(" %d", &bin);
                
                // Exibe
                dec = converter(bin, 2, 10);
                printf("%d equivale a %d em decimal\n", bin, dec);
                break;
            
            case 2:
                // Entrada
                printf("Entre com o numero decimal: ");
                scanf(" %d", &dec);
                
                // Exibe
                bin = converter(dec, 10, 2);
                printf("%d equivale a %d em binario\n", dec, bin);
                break;
            
            default:
                printf("Opcao invalida!\n");
        }
        
        // Checa repeticao
        printf("\nDeseja fazer outra conversao? (S/N): ");
        scanf(" %c", &repete);
        printf("\n");
    }
    
    return 0;
}

//----------------------------------------------------------------

int converter(int n_antes, int base_origem, int base_destino)
{
    // Inicia
    int n_depois = 0, potencia = 1, unidade;
    
    // Monta o numero
    while (n_antes > 0)
    {
        // Incrementa
        unidade = n_antes % base_destino;
        n_depois += unidade * potencia;
        
        // Prepara proxima iteracao
        n_antes /= base_destino;
        potencia *= base_origem;
    }
    
    // Retorna
    return n_depois;
}

//----------------------------------------------------------------
