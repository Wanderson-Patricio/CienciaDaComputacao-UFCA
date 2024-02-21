import pygame
from pygame.locals import *
from sys import exit
import pecas
from board import board

pygame.init()

# Frame rate, dimensões da tela e tamanho da casa do tabueiro
FPS = 2
HEIGTH, WIDTH = 720, 720
HOUSE_WIDTH = WIDTH/8
WHITE = (226,210,159)
BROWN = (179,141,96)
BLACK = (0,0,0)

prev_position = (0,0)
current_piece = None

#peças
board = board()
whites = [pecas.pawn('images/white_pawn.png', 0, 1, 'white', HOUSE_WIDTH),
          pecas.pawn('images/white_pawn.png', 1, 1, 'white', HOUSE_WIDTH),
          pecas.pawn('images/white_pawn.png', 2, 1, 'white', HOUSE_WIDTH),
          pecas.pawn('images/white_pawn.png', 3, 1, 'white', HOUSE_WIDTH),
          pecas.pawn('images/white_pawn.png', 4, 1, 'white', HOUSE_WIDTH),
          pecas.pawn('images/white_pawn.png', 5, 1, 'white', HOUSE_WIDTH),
          pecas.pawn('images/white_pawn.png', 6, 1, 'white', HOUSE_WIDTH),
          pecas.pawn('images/white_pawn.png', 7, 1, 'white', HOUSE_WIDTH),
          pecas.knight('images/white_knight.png', 1, 0, 'white', HOUSE_WIDTH),
          pecas.knight('images/white_knight.png', 6, 0, 'white', HOUSE_WIDTH),
          pecas.rook('images/white_rook.png', 0, 0, 'white', HOUSE_WIDTH),
          pecas.rook('images/white_rook.png', 7, 0, 'white', HOUSE_WIDTH),
          pecas.bishop('images/white_bishop.png', 2, 0, 'white', HOUSE_WIDTH),
          pecas.bishop('images/white_bishop.png', 5, 0, 'white', HOUSE_WIDTH),
          pecas.queen('images/white_queen.png', 3, 0, 'white', HOUSE_WIDTH),
          pecas.king('images/white_king.png', 4, 0, 'white', HOUSE_WIDTH)]

blacks = [pecas.pawn('images/black_pawn.png', 0, 6, 'black', HOUSE_WIDTH),
          pecas.pawn('images/black_pawn.png', 1, 6, 'black', HOUSE_WIDTH),
          pecas.pawn('images/black_pawn.png', 2, 6, 'black', HOUSE_WIDTH),
          pecas.pawn('images/black_pawn.png', 3, 6, 'black', HOUSE_WIDTH),
          pecas.pawn('images/black_pawn.png', 4, 6, 'black', HOUSE_WIDTH),
          pecas.pawn('images/black_pawn.png', 5, 6, 'black', HOUSE_WIDTH),
          pecas.pawn('images/black_pawn.png', 6, 6, 'black', HOUSE_WIDTH),
          pecas.pawn('images/black_pawn.png', 7, 6, 'black', HOUSE_WIDTH),
          pecas.knight('images/black_knight.png', 1, 7, 'black', HOUSE_WIDTH),
          pecas.knight('images/black_knight.png', 6, 7, 'black', HOUSE_WIDTH),
          pecas.rook('images/black_rook.png', 0, 7, 'black', HOUSE_WIDTH),
          pecas.rook('images/black_rook.png', 7, 7, 'black', HOUSE_WIDTH),
          pecas.bishop('images/black_bishop.png', 2, 7, 'black', HOUSE_WIDTH),
          pecas.bishop('images/black_bishop.png', 5, 7, 'black', HOUSE_WIDTH),
          pecas.queen('images/black_queen.png', 3, 7, 'black', HOUSE_WIDTH),
          pecas.king('images/black_king.png', 4, 7, 'black', HOUSE_WIDTH)]

# Iniciaçização da tela do jogo
display = pygame.display.set_mode((WIDTH, HEIGTH))
clock = pygame.time.Clock()
pygame.display.set_caption('XADREZ')

#---------------------------------------------------------------------------------------------------------------------------------------
# Funções
def drawPieces():
    """Draw all pieces in the board"""
    
    for piece in whites:
        piece.draw(display)
    for piece in blacks:
        piece.draw(display)
        
def selectedPiece(pos: tuple) -> pecas.peca:
    """Ao clicar na tela, caso seja tocado em uma peça, ela é retornada pela função"""
    for piece in whites:
        if piece.x*HOUSE_WIDTH <= pos[0] and (piece.x + 1)*HOUSE_WIDTH >= pos[0] and piece.y*HOUSE_WIDTH <= pos[1] and (piece.y + 1)*HOUSE_WIDTH >= pos[1]:
            aux = piece
          
    for piece in blacks:
        if piece.x*HOUSE_WIDTH <= pos[0] and (piece.x + 1)*HOUSE_WIDTH >= pos[0] and piece.y*HOUSE_WIDTH <= pos[1] and (piece.y + 1)*HOUSE_WIDTH >= pos[1]:
            aux = piece
            
    print(aux.color)
    
    return aux

def updateBoardHouses():
    for piece in whites:
        board.change(piece.x, piece.y, piece.color)
    
    for piece in blacks:
        board.change(piece.x, piece.y, piece.color)

# ---------------------------------------------------------------------------------------------------------------------------------------
# LOOP do jogo

while(True):
    clock.tick(FPS)
    display.fill(BLACK)
            
    board.draw(display, (WHITE, BROWN), HOUSE_WIDTH)
    drawPieces()
    updateBoardHouses()
    
    board.print()
    print()
    
    for event in pygame.event.get():
        
        if event.type == QUIT:
            pygame.quit()
            exit()
            
        if event.type == pygame.MOUSEBUTTONDOWN:
            pos = pygame.mouse.get_pos()
            current_x, current_y = int(pos[0]/HOUSE_WIDTH), int(pos[1]/HOUSE_WIDTH)
            
            if current_piece != None:
                current_piece.mover(current_x, current_y, board)
                current_piece = None
            
            if board.isOccupied(current_x, current_y):
                if current_piece == None:
                    current_piece = selectedPiece(pos)

                
            
            
            
            
    
    pygame.display.update()