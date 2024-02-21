from abc import abstractclassmethod
import pygame
from board import board

class peca:
    
    def __init__(self, image_src: str, x: int, y: int, color: str, house_width: int) -> None:
        self.image = pygame.transform.scale(pygame.image.load(image_src), (house_width, house_width))
        self.x = x
        self.y = y
        self.house_width = house_width
        self.color = color
        
    def draw(self, display: pygame.display) -> None:
        display.blit(self.image, (self.x*self.house_width, self.y*self.house_width))
        
        
    @abstractclassmethod
    def move(self, x: int, y: int) -> None:
        pass
    
    def mover(self, x: int, y: int, board: board) -> None:
        if x >= 0 and x <= 7 and y >= 0 and y <= 7:
            board.change(self.x, self.y, '')
            self.move(x, y)
            board.change(self.x, self.y, self.color)
            
class pawn(peca):
    
    def __init__(self, image_src: str, x: int, y: int, color: str, house_width: int) -> None:
        super().__init__(image_src, x, y, color, house_width)
        self.jogada = 0
        
    def move(self, x: int, y: int) -> None:
        if self.color == 'white':
            if y == self.y + 1:
                self.y += 1
            elif y == self.y + 2 and self.jogada == 0:
                self.y += 2
                self.jogada = 1
        else:
            if y == self.y - 1:
                self.y -= 1
            elif y == self.y - 2 and self.jogada == 0:
                self.y -= 2
                self.jogada = 1


class rook(peca):
    
    def __init__(self, image_src: str, x: int, y: int, color: str, house_width: int) -> None:
        super().__init__(image_src, x, y, color, house_width)
        
    def move(self, x: int, y: int) -> None:
        pass
        
class bishop(peca):
    
    def __init__(self, image_src: str, x: int, y: int, color: str, house_width: int) -> None:
        super().__init__(image_src, x, y, color, house_width)
        
class knight(peca):
    
    def __init__(self, image_src: str, x: int, y: int, color: str, house_width: int) -> None:
        super().__init__(image_src, x, y, color, house_width)
        
class queen(peca):
    
    def __init__(self, image_src: str, x: int, y: int, color: str, house_width: int) -> None:
        super().__init__(image_src, x, y, color, house_width)
        
class king(peca):
    
    def __init__(self, image_src: str, x: int, y: int, color: str, house_width: int) -> None:
        super().__init__(image_src, x, y, color, house_width)