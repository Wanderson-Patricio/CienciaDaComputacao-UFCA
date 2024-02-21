'''diretory = r'Dados coletados busca linear.txt'
tempo = []

with open(diretory, 'r') as arquivo:
    for valor in arquivo:
        tempo.append(float(valor))

print(tempo)'''

import pyautogui as pg
import time

time.sleep(10)
pg.moveTo(x=1416, y=99)