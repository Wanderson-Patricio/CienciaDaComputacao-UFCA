from vector import vector
from force import force
from pygame import display, draw

class particle:

    def __init__(self, position: vector, mass: float, size: float, color: tuple,isLocked: bool) -> None:
        self.r : vector = position #position of the particle
        self.v : vector = vector(0,0)  #inicial velocity
        self.a : vector = vector(0,0)  #inicial aceleration
        self.m : float  = mass
        self.isLocked : bool= isLocked
        self.size : float = size
        self.color = color

    def move(self) -> None:
        """Moves the particle"""
        if self.isLocked:
            return

        self.v = self.v.add(self.a)
        self.r = self.r.add(self.v)

    def applyForce(self, F: force) -> None:
        copy_f = F.copy()
        copy_f.mult(1/self.m)
        self.a = copy_f

    def draw(self, display : display) -> None:
        draw.circle(display, self.color, (self.r.x, self.r.y), self.size)

    def update(self, display : display) -> None:
        self.move()
        self.draw(display)