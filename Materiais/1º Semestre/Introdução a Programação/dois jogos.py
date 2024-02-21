from random import choice

def jogo_da_velha():
    verificador = 's'
    vitoria_x = 0
    vitoria_o = 0

    #Verificador para múltiplas paridas consecutivas

    while verificador == 's':

        #inicializando as condições para cada partida
    
        jogada = 1
        jogador = 1
        vitoria = 0

        #montando o tabuleiro
    
        jogo = [['[',' ',']','[',' ',']','[',' ',']'],['[',' ',']','[',' ',']','[',' ',']'],['[',' ',']','[',' ',']','[',' ',']']]

        #iniciando o jogo

        while jogada <= 8 and vitoria == 0:

            #imprimindo o tabuleiro na tela
            
            for lista in jogo:
                for elemento in lista:
                    print(elemento, end='')
                print()
            if jogador == 1:
                print('Essa jogada é do jogador X.')
            else:
                print('Essa jogada é do jogador O.')
    
            #recebendo uma jogada
                
            linha = int(input('Escolha uma linha: '))
            coluna = int(input('Escolha uma coluna: '))

            #verificando se a jogada é válida

            while linha > 3 or linha < 1 or coluna > 3 or coluna < 1 or jogo[linha-1][3*coluna-2] != ' ':
                print('Posição inválida. Escolha outra opção.')
                linha = int(input('Escolha uma linha: '))
                coluna = int(input('Escolha uma coluna: '))

            #realizando a jogada
            
            if jogador == 1:
                jogo[linha-1][3*coluna-2]='X'
                jogador = 2
            else:
                jogo[linha-1][3*coluna-2]='O'
                jogador = 1

            #verificando se houve vitoria
            
            if jogo[0][1] == jogo[0][4] == jogo[0][7] and jogo[0][1] != ' ':
                vitoria = 1
            else:
                if jogo[1][1] == jogo[1][4] == jogo[1][7] and jogo[1][1] != ' ':
                    vitoria = 1
                else:
                    if jogo[2][1] == jogo[2][4] == jogo[2][7] and jogo[2][1] != ' ':
                       vitoria = 1
                    else:
                        if jogo[0][1] == jogo[1][1] == jogo[2][1] and jogo[0][1] != ' ':
                            vitoria = 1
                        else:
                            if jogo[0][4] == jogo[1][4] == jogo[2][4] and jogo[0][4] != ' ':
                                vitoria = 1
                            else:
                                if jogo[0][7] == jogo[1][7] == jogo[2][7] and jogo[0][7] != ' ':
                                    vitoria = 1
                                else:
                                    if jogo[0][1] == jogo[1][4] == jogo[2][7] and jogo[0][1] != ' ':
                                        vitoria = 1
                                    else:
                                        if jogo[0][7] == jogo[1][4] == jogo[2][1] and jogo[0][7] != ' ':
                                            vitoria = 1
            jogada = jogada + 1

        #realizando automaticamente a última jogada
        
        if jogada == 9:
            for lista in jogo:
                for elemento in lista:
                    if jogo[lista][elemento] == ' ':
                        if jogador == 1:
                            jogo[lista][elemento]='X'
                        else:
                            jogo[lista][elemento]='O'

        #verificando se houve vitoria
                        
        if jogo[0][1] == jogo[0][4] == jogo[0][7] and jogo[0][1] != ' ':
                vitoria = 1
        else:
            if jogo[1][1] == jogo[1][4] == jogo[1][7] and jogo[1][1] != ' ':
                vitoria = 1
            else:
                if jogo[2][1] == jogo[2][4] == jogo[2][7] and jogo[2][1] != ' ':
                    vitoria = 1
                else:
                    if jogo[0][1] == jogo[1][1] == jogo[2][1] and jogo[0][1] != ' ':
                        vitoria = 1
                    else:
                        if jogo[0][4] == jogo[1][4] == jogo[2][4] and jogo[0][4] != ' ':
                            vitoria = 1
                        else:
                            if jogo[0][7] == jogo[1][7] == jogo[2][7] and jogo[0][7] != ' ':
                                vitoria = 1
                            else:
                                if jogo[0][1] == jogo[1][4] == jogo[2][7] and jogo[0][1] != ' ':
                                    vitoria = 1
                                else:
                                    if jogo[0][7] == jogo[1][4] == jogo[2][1] and jogo[0][7] != ' ':
                                        vitoria = 1

        #imprimindo o tabuleiro na tela

        for lista in jogo:
            for elemento in lista:
                print(elemento, end='')
            print()

        #imprime na tela o resultado do jogo

        if vitoria == 0:
            print('O jogo deu velha.')
        else:
            if jogador == 2:
                print('O jogador X venceu')
                vitoria_x+=1
            else:
                print('O jogador O venceu')
                vitoria_o+=1

        #mostra a quantidade de vitórias totais de cada jogador
            
        print('Partidas ganhas:')
        print('X -> ', vitoria_x)
        print('O -> ', vitoria_o)

        #verifica se o jogador quer jogar novamente
    
        verificador = input('Quer jogar de novo? \n Sim - s \n Não - n \n')

def batalha_naval():
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

op = -1
while op !=0:
    print('Qual jogo você deseja jogar?\n Jogo Da Velha - Digite 1\n Batalha Naval - Digite 2\n Sair - Digite 0')
    op = int(input())
    if op == 1:
        jogo_da_velha()
    elif op == 2:
        batalha_naval()
print('Muito obrigado por acessar o aplicativo')
