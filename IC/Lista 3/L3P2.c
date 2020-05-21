//----------------------------------------------------------------
// Lista 3 - Problema 2
// Al Richard
//----------------------------------------------------------------

#include <stdio.h>

//----------------------------------------------------------------

int terminou(char t[4][4]);

//----------------------------------------------------------------

int main()
{
    // Declaracoes
    int vez = 1, l, c, valida = 0;
    char j[3][30], sinal[3] = {' ', 'O', 'X'};
    char t[4][4];
    
    // Limpa o tabuleiro
    for (int i = 1; i <= 3; i++)
        for (int j = 1; j <= 3; j++)
            t[i][j] = ' ';
    
    // Pede os nomes
    printf("Nome do jogador 1: ");
    scanf(" %s", j[1]);
    printf("Nome do jogador 2: ");
    scanf(" %s", j[2]);
    printf("\n");
    
    // E executa o jogo ate acabar
    while (1)
    {
        // Mostra o tabuleiro
        printf("%c|%c|%c\n", t[1][1], t[1][2], t[1][3]);
        printf("-+-+-\n");
        printf("%c|%c|%c\n", t[2][1], t[2][2], t[2][3]);
        printf("-+-+-\n");
        printf("%c|%c|%c\n\n", t[3][1], t[3][2], t[3][3]);
        
        // Checa situacao
        int situacao = terminou(t);
        
        // Alguem venceu
        if (situacao > 0)
        {
            printf("%s venceu!\n", j[situacao]);
            break;
        }
        // Deu velha
        else if (situacao == 0)
        {
            printf("Deu velha!\n");
            break;
        }
        
        // Se nao terminou, pede a proxima jogada
        while (!valida)
        {
            printf("Vez de %s\n", j[vez]);
            printf("Linha: ");
            scanf(" %d", &l);
            printf("Coluna: ");
            scanf(" %d", &c);
            
            // Checa validez
            if (t[l][c] == ' ')
                valida = 1;
            else
                printf("Essa casa ja esta ocupada, tente mais uma vez.\n\n");
        }
        
        // Preenche
        t[l][c] = sinal[vez];
        printf("\n");
        
        // Prepara proxima jogada
        vez = (vez % 2) + 1;
        valida = 0;
    }
    
    return 0;
}

//----------------------------------------------------------------

int terminou(char t[4][4])
{
    // Checa linhas
    for (int i = 1; i <= 3; i++)
    {
        // Se a linha é igual
        if (t[i][1] == t[i][2] && t[i][2] == t[i][3])
        {
            // J1 ganhou
            if (t[i][1] == 'O') return 1;
            // J2 ganhou
            if (t[i][1] == 'X') return 2;
        }
    }
    
    // Checa colunas
    for (int i = 1; i <= 3; i++)
    {
        // Se a coluna é igual
        if (t[1][i] == t[2][i] && t[2][i] == t[3][i])
        {
            // J1 ganhou
            if (t[1][i] == 'O') return 1;
            // J2 ganhou
            if (t[1][i] == 'X') return 2;
        }
    }
    
    // Checa diagonal principal
    if (t[1][1] == t[2][2] && t[2][2] == t[3][3])
    {
        // J1 ganhou
        if (t[2][2] == 'O') return 1;
        // J2 ganhou
        if (t[2][2] == 'X') return 2;
    }
    
    // Checa diagonal secundaria
    if (t[1][3] == t[2][2] && t[2][2] == t[3][1])
    {
        // J1 ganhou
        if (t[2][2] == 'O') return 1;
        // J2 ganhou
        if (t[2][2] == 'X') return 2;
    }
    
    // Checa velha
    int velha = 0;
    
    for (int i = 1; i <= 3; i++)
        for (int j = 1; j <= 3; j++)
            if (t[i][j] == ' ')
                velha = -1;
    
    return velha;
}

//----------------------------------------------------------------
