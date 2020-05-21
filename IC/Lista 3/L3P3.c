//----------------------------------------------------------------
// Lista 3 - Problema 3
// Al Richard
//----------------------------------------------------------------

#include <stdio.h>
#define MAX 100

//----------------------------------------------------------------

void exibir(char t[MAX][MAX]);
int terminou(char t[MAX][MAX]);
int n;

//----------------------------------------------------------------

int main()
{
    // Declaracoes
    int vez = 1, l, c, valida = 0;
    char j[3][30], sinal[3] = {' ', 'O', 'X'};
    char t[MAX][MAX];
    
    // Pede dimensao
    printf("Dimensao do tabuleiro: ");
    scanf(" %d", &n);
    
    // Limpa o tabuleiro
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
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
        exibir(t);
        
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

void exibir(char t[MAX][MAX])
{
    for (int i = 1; i <= n; i++)
    {
        // Linha
        for (int j = 1; j <= n; j++)
        {
            printf("%c", t[i][j]);
            if (j < n)
                printf("|");
        }
        printf("\n");
        
        // Divisoria
        if (i < n)
        {
            for (int k = 1; k < n; k++)
                printf("-+");
            printf("-\n");
        }
    }
    printf("\n");
}

//----------------------------------------------------------------

int terminou(char t[MAX][MAX])
{
    // Auxiliares
    char primeiro;
    int venceu;
    
    // Checa linhas
    for (int i = 1; i <= n; i++)
    {
        primeiro = t[i][1];
        venceu = 1;
        
        // Se a linha nao for igual, pula
        for (int j = 1; j <= n; j++)
            if (t[i][j] != primeiro)
                venceu = 0;
        
        if (!venceu) continue;
        
        // J1 ganhou
        if (primeiro == 'O') return 1;
        // J2 ganhou
        if (primeiro == 'X') return 2;
    }
    
    // Checa colunas
    for (int j = 1; j <= n; j++)
    {
        primeiro = t[1][j];
        venceu = 1;
        
        // Se a coluna nao for igual, pula
        for (int i = 2; i <= n; i++)
            if (t[i][j] != primeiro)
                venceu = 0;
        
        if (!venceu) continue;
        
        // J1 ganhou
        if (primeiro == 'O') return 1;
        // J2 ganhou
        if (primeiro == 'X') return 2;
    }
    
    // Checa diagonal principal
    primeiro = t[1][1];
    venceu = 1;
    
    for (int i = 2; i <= n; i++)
        if (t[i][i] != primeiro)
            venceu = 0;
    
    if (venceu)
    {
        // J1 ganhou
        if (primeiro == 'O') return 1;
        // J2 ganhou
        if (primeiro == 'X') return 2;
    }
    
    // Checa diagonal secundaria
    primeiro = t[1][n];
    venceu = 1;
    
    for (int i = 2; i <= n; i++)
        if (t[i][n+1-i] != primeiro)
            venceu = 0;
    
    if (venceu)
    {
        // J1 ganhou
        if (primeiro == 'O') return 1;
        // J2 ganhou
        if (primeiro == 'X') return 2;
    }
    
    // Checa velha
    int velha = 0;
    
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (t[i][j] == ' ')
                velha = -1;
    
    return velha;
}

//----------------------------------------------------------------
