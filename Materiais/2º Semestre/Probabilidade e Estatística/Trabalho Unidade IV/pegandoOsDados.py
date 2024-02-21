import pyautogui as pg
from time import sleep
import pyperclip

# Fecha o VS Code
sleep(2)
pg.click(x=1486, y=11)

for i in range(1, 51):
    texto = str(i*1000000)
    pyperclip.copy(texto)

    sleep(5)
    pg.click(x=228, y=514, clicks=2)
    pg.hotkey('ctrl', 'v')

    sleep(2)
    pg.click(x=286, y=36)

    sleep(2)
    pg.click(x=306, y=87)

    sleep(20)
    pg.click(x=517, y=288, clicks=2)
    pg.hotkey()
    pg.hotkey('ctrl', 'c')

    sleep(5)
    pg.click(x=1295, y=150)

    sleep(2)
    pg.moveTo(x=285, y=899)

    sleep(5)

    pg.click(x=285, y=899)
    pg.hotkey('ctrl', 'v')

    sleep(2)
    if i<10:
        texto = " s - n = {} * 10^6".format(i)
    else:
        texto = " s - n = {:.1f} * 10^7".format(i/10)
    
    pyperclip.copy(texto)
    pg.hotkey('ctrl', 'v')
    pg.press('Enter')

    sleep(2)
    pg.hotkey('Alt', 'Tab')