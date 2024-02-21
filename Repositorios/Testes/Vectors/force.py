from vector import vector
from pygame import display, draw

class force(vector):
    """The main purpose of the class force is just to diferenciate from another vector, but is, indeed, a vector"""
    def __init__(self, x: float, y: float) -> None:
        super().__init__(x, y)

"""Here you can define another types of forces"""

class spring:

    def __init__(self, k: float, restLenght : float, a ,b) -> None:
        self.a = a
        self.b = b
        self.k = k
        self.restLenght = restLenght

    def draw(self, display: display) -> None:
        draw.line(display, (255,255,255), (self.a.r.x, self.a.r.y), (self.b.r.x, self.b.r.y), 1)

    def Force(self) -> force:
        x = self.b.r.sub(self.a.r).mag() - self.restLenght
        
        #Vetor unitario na direção de a para b
        v = self.b.r.sub(self.a.r)
        v.normalize()

        #força elástica
        v.mult(self.k * x)
        
        return v