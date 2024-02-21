import pygame
from pygame.locals import *
import os
import sys
from math import pi, sin, cos

diretorio_atual = os.path.dirname(os.path.abspath(__file__))
diretorio_pai = os.path.join(diretorio_atual, '..')
sys.path.append(diretorio_pai)

from particle import particle
from vetor import vector
from drawer import *

## Inicialização dos atributos iniciais do programa

FPS = 120
DT = 10/FPS
BLUE = (0, 0, 255)
BLACK = (0, 0, 0)
GREY = (48, 45, 45)
YELLOW = (235,231,18)
WIDTH, HEIGHT = 1200, 800
G = 100

## Inicialização do pygame

pygame.init()
screen = pygame.display.set_mode((WIDTH, HEIGHT))
clock = pygame.time.Clock()

## Inicialização dos objetos

Sun = particle((600,400), 100, 10, YELLOW, True)
Earth = particle((900,400), 10, 2.5, BLUE)
Moon = particle((910, 400), 1, 1, GREY)
Earth.v = vector(0,-1)
Moon.v = vector(0,-.1)

while True:
    clock.tick(FPS)
    #screen.fill(BLACK)
    
    for event in pygame.event.get():
        
        if event.type == QUIT:
            pygame.quit()
            exit()
            
    R_moon_sun = Sun.r - Moon.r
    R_moon_earth = Earth.r - Moon.r
    R_earth_sun = Sun.r - Earth.r
    
    f_moon_sun = G*(Sun.m)*(Moon.m) / (R_moon_sun.mag()**2) * 0.001
    f_moon_earth = G*(Earth.m)*(Moon.m) / (R_moon_earth.mag()**2) * 0.1
    f_earth_sun = G*(Earth.m)*(Sun.m) / (R_earth_sun.mag()**2)
    
    R_moon_sun.norm()
    R_moon_earth.norm()
    R_earth_sun.norm()
    
    Moon.applyForce(R_moon_sun * f_moon_sun + R_moon_earth * f_moon_earth)
    Earth.applyForce(R_earth_sun * f_earth_sun - R_moon_earth * f_moon_earth)
    
    Moon.move(DT)
    Earth.move(DT)
    
    drawParticle(Earth, screen)
    drawParticle(Moon, screen)
    drawParticle(Sun,  screen)
    
    pygame.display.update()