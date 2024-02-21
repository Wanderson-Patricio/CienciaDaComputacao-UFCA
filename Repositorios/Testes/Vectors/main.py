import pygame
from pygame.locals import *
from sys import exit
from force import force, spring
from particle import particle
from vector import vector

import matplotlib.pyplot as plt

WIDTH = 600
HEIGHT = 800
RED = (255,0,0)
BLACK = (0,0,0)
WHITE = (255,255,255)
m = 1
M = 3
size = 10
k = 0.001
restLenght = 200

a = particle(vector(WIDTH/4, HEIGHT/2), m, size, RED, False)
b = particle(vector(3*WIDTH/4, HEIGHT/2), m, size, RED, False)

spring = spring(k, restLenght, a, b)

pygame.init()
screen = pygame.display.set_mode((WIDTH, HEIGHT))
clock = pygame.time.Clock()

FPS = 100

position = []
i = 0
time = []

while(i < 1000):
    
    clock.tick(FPS)
    screen.fill(BLACK)

    for event in pygame.event.get():
        if event.type == QUIT:
            pygame.quit()
            exit()

    spring.draw(screen)

    f = spring.Force()
    a.applyForce(f)
    f.mult(-1)
    b.applyForce(f)

    a.update(screen)
    b.update(screen)

    position.append(b.r.x - HEIGHT / 2)
    i += 1
    time.append(i/FPS)

    pygame.display.update()

fig, ax = plt.subplots()

ax.scatter(time, position)
plt.show()