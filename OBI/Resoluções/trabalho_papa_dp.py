#--------------------------------------------------------------
# Trabalho do Papa
#--------------------------------------------------------------

if __name__ == "__main__":
    
    # Variáveis
    caixas = []
    recorde = 0
    menor_peso = [1000010]*1010
    menor_peso[0] = 0
    
    # Pega resistência e peso de cada caixa
    n = int(input())
    for _ in range(n):
        p, r = [int(d) for d in input().split()]
        caixas.append([r, p])

    # Ordem óptima
    caixas.sort()
    
    '''
    Percorre as caixas, tentando montar uma
    pilha com a caixa da vez embaixo
    '''
    for i in range(n):
        '''
        Do maior tamanho já conseguido pro menor,
        tenta colocar a caixa i embaixo da pilha
        mais leve já criada com k-1 caixas
        '''
        for k in range(recorde+1, 0, -1):
            '''
            Se essa for a pilha de k caixas
            mais leve, guarda isso
            '''
            if caixas[i][0]-caixas[i][1] >= menor_peso[k-1] and menor_peso[k-1] + caixas[i][1] < menor_peso[k]:
                menor_peso[k] = menor_peso[k-1] + caixas[i][1]
                # Se o recorde foi batido, atualiza
                if k > recorde:
                    recorde = k
    
    # Mostra o resultado
    print(recorde)

#--------------------------------------------------------------
