from math import sqrt

class vector:

    def __init__(self, x: float, y: float) -> None:
        self.x = x
        self.y = y

    def __str__(self) -> str:
        return f'({self.x}, {self.y})'
    
    def __eq__(self, __value: object) -> bool:
        """This function returns if this vector is equals to the one passed as parameter"""
        if not isinstance(__value, vector):
            return False
        
        return self.x == __value.x and self.y == __value.y
    
    def set(self, v) -> None:
        if isinstance(v, vector):
            self.x = v.x
            self.y = v.y

    def copy(self):
        """Returns a copy of the vector"""
        return vector(self.x, self.y)

    def mag(self) -> float:
        """Returns the magnitude of the vector"""
        return sqrt(self.x**2 + self.y**2)

    def normalize(self) -> None:
        """Divides the vector by its magnitude, so it becomes a unit vector"""
        mag = self.mag()
        self.x /= mag
        self.y /= mag

    def add(self, v):
        """return the sum of the vector self and the vector v"""
        if isinstance(v, vector):
            return vector(self.x + v.x, self.y + v.y)
        
        return None

    def sub(self, v):
        """return the subtration of the vector self and the vector v"""
        if isinstance(v, vector):
            return vector(self.x - v.x, self.y - v.y)
        
        return None
    
    def mult(self, k: float):
        """returns the multiplication of the vector by a number k"""
        self.x *= k
        self.y *= k

    def dot(self, v) -> float:
        return self.x*v.x + self.y*v.y
    
