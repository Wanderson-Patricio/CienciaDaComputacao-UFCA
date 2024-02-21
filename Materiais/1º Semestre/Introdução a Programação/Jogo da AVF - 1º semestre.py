from random import choice
verificador = 's'

#verificando múltiplas partidas
while verificador == 's':
    
    #inicializando as condições da partida
    turno = 1
    turnos_restantes = 20
    vitoria = 0
    acertos = 0
    
    #incializando o tabuleiro do jogo
    tabuleiro = [['0','0','0','0','0'],['0','0','0','0','0'],['0','0','0','0','0'],['0','0','0','0','0'],['0','0','0','0','0']]
    tabuleiro_aux = [['X','X','X','X','X'],['X','X','X','X','X'],['X','X','X','X','X'],['X','X','X','X','X'],['X','X','X','X','X']]
    opcoes = [x for x in range(5)]
    
    #escolhendo aleatoriamente as posições dos navios
    for i in range(5):
        linha = choice(opcoes)
        coluna = choice(opcoes)
        while tabuleiro[linha][coluna] != '0':
            linha = choice(opcoes)
            coluna = choice(opcoes)
        tabuleiro[linha][coluna] = '1'

    #iniciando o jogo
    while turno <=20 and vitoria == 0:

        #imprimindo o tabuleiro auxiliar na tela
        for i in range(7):
            if i == 0:
                for j in range(6):
                    if j == 0:
                        print('  | ', end='')
                    elif j == 1:
                        print('a  ', end='')
                    elif j == 2:
                        print('b  ', end='')
                    elif j == 3:
                        print('c  ', end='')
                    elif j == 4:
                        print('d  ', end='')
                    else:
                        print('e  ', end='')
                print()
            elif i == 1:
                for j in range(6):
                    print('---', end='')
                print()
            else:
                for j in range(6):
                    if j == 0:
                        print(i-1,'| ', end='')
                    else:
                        print(tabuleiro_aux[i-2][j-1],' ', end='')
                print()
        print('\n Restam ',turnos_restantes,' jogadas.')

        #Escolhendo uma posição
        print('\n Escolha uma posição:')
        coluna_letra = input('coluna>> ')
        linha = int(input('linha>> '))
        if coluna_letra == 'a':
            coluna = 1
        elif coluna_letra == 'b':
            coluna = 2
        elif coluna_letra == 'c':
            coluna = 3
        elif coluna_letra == 'd':
            coluna = 4
        elif coluna_letra == 'e':
            coluna = 5

        #verificando se a jogada é válida
        while linha < 1 or linha > 5 or coluna < 1 or coluna > 5 or tabuleiro_aux[linha-1][coluna-1] != 'X':
            print('Jogada inválida. Jogue novamente.')
            coluna_letra = input('coluna>> ')
            linha = int(input('linha>> '))
            if coluna_letra == 'a':
                coluna = 1
            elif coluna_letra == 'b':
                coluna = 2
            elif coluna_letra == 'c':
                coluna = 3
            elif coluna_letra == 'd':
                coluna = 4
            elif coluna_letra == 'e':
                coluna = 5

        #Realizando a jogada e vendo se foi acertado algum navio
        tabuleiro_aux[linha-1][coluna-1] = tabuleiro[linha-1][coluna-1]
        if tabuleiro[linha-1][coluna-1] == '0':
            print('Você não acertou nenhum navio :(')
        else:
            print('Você acertou um navio :)!!')
            acertos = acertos + 1

        #aumentando a quantidade de turnos
        turno = turno + 1
        turnos_restantes = turnos_restantes - 1

        #verificando se houve vitória
        if acertos == 5:
            vitoria = 1

    #imprimindo o tabuleiro inicial após o encerramento da partida
    for i in range(5):
        for j in range(5):
            print(tabuleiro[i][j],' ', end='')
        print()
    if vitoria == 1:
        print('Você ganhou a partida após ', turno,' jogadas')
    else:
        print('Você perdeu a partida')

    #verificando se o jogador quer jogar de novo
    verificador = input('Você quer jogar novamente? \n Sim - Digite s\n Não - Digite n\n')
    while verificador != 's' and verificador != 'n':
        verificador = input('Você quer jogar novamente? \n Sim - Digite s\n Não - Digite n\n')
