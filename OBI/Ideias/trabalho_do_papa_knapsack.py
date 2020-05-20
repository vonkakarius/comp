#--------------------------------------------------------------
# Trabalho do Papa
#--------------------------------------------------------------
# Problema da mochila
#--------------------------------------------------------------

def mochila(pos, aguenta):
    global dp
    # Casos base
    if pos >= n: return 0
    if dp[pos][aguenta] != -1: return dp[pos][aguenta]
    
    # Caso em que não entra
    caso_n = mochila(pos+1, aguenta)
    # Caso em que entra
    caso_s = 0
    if caixas[pos][1] <= aguenta:
        # Novo "aguenta" da pilha
        r = min(aguenta-caixas[pos][1], caixas[pos][0]-caixas[pos][1])
        if r >= 0:
            caso_s = 1 + mochila(pos+1, r)
    
    # Verifica o melhor e retorna
    dp[pos][aguenta] = max(caso_s, caso_n)
    return dp[pos][aguenta]
    
#--------------------------------------------------------------
# Função principal
#--------------------------------------------------------------

if __name__ == "__main__":

    # Variáveis
    global n, dp, caixas
    caixas = []
    dp = []
    n = 0
    INF = 1000010
    
    # Número de caixas
    n = int(input())
    dp = [[-1]*INF]*INF

    # Recebe dados das caixas
    for _ in range(n):
        p, r = [int(d) for d in input().split()]
        caixas.append([r, p])

    # Ordem óptima
    caixas.sort()
    caixas = caixas[::-1]
    caixas.append([INF, INF])

    # Mostra resposta
    print(mochila(0, INF-1))

#--------------------------------------------------------------
