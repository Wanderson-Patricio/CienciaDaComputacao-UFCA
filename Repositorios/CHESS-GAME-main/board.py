import pygame

class board:
    
    def __init__(self) -> None:
        """Create an empty board"""
        self.houses = [[0 for i in range(8)] for j in range(8)]
        
    def draw(self, display, colors, house_width: int) -> None:
        """Draw the board in the given display. The colors of the houses and its widths must be given as parameters of the function"""
        for x in range(len(self.houses)):
            for y in range(len(self.houses)):
            
                if (x+y)%2 == 0:
                    pygame.draw.rect(display, colors[0], (x*house_width, y*house_width, house_width, house_width))
                else:
                    pygame.draw.rect(display, colors[1], (x*house_width, y*house_width, house_width, house_width))
                    
    def color(self, x: int, y: int) -> str:
        if self.houses[y][x] == 0:
            return ''
        elif self.houses[y][x] == 1:
            return 'white'
        else:
            return 'black'
        
                    
    def isOccupied(self, x: int, y: int) -> bool:
        return self.houses[y][x] != 0
    
    def change(self, x:int, y:int, color:str) -> None:
        if color == 'white':
            self.houses[y][x] = 1
        elif color == 'black':
            self.houses[y][x] = -1
        else:
            self.houses[y][x] = 0
            
    def print(self):
        for i in range(8):
            for j in range(8):
                print(str(self.houses[i][j]) + ' ', end = '')
            print()