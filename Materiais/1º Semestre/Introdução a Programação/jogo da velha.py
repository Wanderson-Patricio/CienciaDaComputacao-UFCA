verificador = 's'
vitoria_x = 0
vitoria_o = 0
while verificador == 's':
    jogada = 1
    jogador = 1
    vitoria = 0
    linha0 = ['[',' ',']','[',' ',']','[',' ',']']
    linha1 = ['[',' ',']','[',' ',']','[',' ',']']
    linha2 = ['[',' ',']','[',' ',']','[',' ',']']
    while jogada <= 9 and vitoria == 0:
        print(*linha0)
        print(*linha1)
        print(*linha2)
        print('Esta rodada é do jogador ', jogador)
        linha = int(input('Escolha uma linha: '))
        coluna = int(input('Escolha uma coluna: '))
        if linha == 1 and linha0[3*coluna-2] != ' ':
            linha = int(input('Escolha uma linha: '))
            coluna = int(input('Escolha uma coluna: '))
        if linha == 2 and linha1[3*coluna-2] != ' ':
            linha = int(input('Escolha uma linha: '))
            coluna = int(input('Escolha uma coluna: '))
        if linha == 3 and linha2[3*coluna-2] != ' ':
            linha = int(input('Escolha uma linha: '))
            coluna = int(input('Escolha uma coluna: '))
        if jogador == 1:
            if linha == 1:
                linha0[3*coluna-2] = 'X'
            else:
                if linha == 2:
                    linha1[3*coluna-2] = 'X'
                else:
                    linha2[3*coluna-2] = 'X'
            jogador = 2
        else:
            if linha == 1:
                linha0[3*coluna-2] = 'O'
            else:
                if linha == 2:
                    linha1[3*coluna-2] = 'O'
                else:
                    linha2[3*coluna-2] = 'O'
            jogador = 1
        if linha0[1] == linha0[4] == linha0[7] and linha0[1] != ' ':
            vitoria = 1
        else:
            if linha1[1] == linha1[4] == linha1[7] and linha1[1] != ' ':
                vitoria = 1
            else:
                if linha2[1] == linha2[4] == linha2[7] and linha2[1] != ' ':
                   vitoria = 1
                else:
                    if linha0[1] == linha1[1] == linha2[1] and linha0[1] != ' ':
                        vitoria = 1
                    else:
                        if linha0[4] == linha1[4] == linha2[4] and linha0[4] != ' ':
                            vitoria = 1
                        else:
                            if linha0[7] == linha1[7] == linha2[7] and linha0[7] != ' ':
                                vitoria = 1
                            else:
                                if linha0[1] == linha1[4] == linha2[7] and linha0[1] != ' ':
                                    vitoria = 1
                                else:
                                    if linha0[7] == linha1[4] == linha2[1] and linha0[7] != ' ':
                                        vitoria = 1
        jogada = jogada + 1
    print(*linha0)
    print(*linha1)
    print(*linha2)
    if vitoria == 0:
        print('O jogo deu velha.')
    else:
        if jogador == 2:
            print('O jogador 1 venceu')
            vitoria_x+=1
        else:
            print('O jogador 2 venceu')
            vitoria_o+=1
    print('Partidas ganhas:')
    print('X -> ', vitoria_x)
    print('O -> ', vitoria_o)
    verificador = input('Quer jogar de novo? \n Sim - s \n Não - Qualquer outra tecla \n')
