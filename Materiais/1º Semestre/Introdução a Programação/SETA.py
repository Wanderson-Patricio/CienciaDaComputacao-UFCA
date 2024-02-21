import math
import numpy as np
import matplotlib.pyplot as plt

def f(u):
    f = (u**4)/(math.sqrt(1+u**2))
    return f

def integral(x):
    me = 9.1093837*10**(-22)
    c = 299792458
    pi = np.pi
    h = (6.62607015*(10**(-34)))/(2*pi)

    aux = (1/3)*((me**4*c**5)/(pi**2*h**3))
    soma = 0
    passos = 10000
    delta = x/passos
    for i in range(passos):
        soma += f(i*delta)*delta

    return aux*soma

def func_analitica(x):
    me = 9.1093837*10**(-22)
    c = 299792458
    pi = np.pi
    h = (6.62607015*(10**(-34)))/(2*pi)
    aux = (1/24)*((me**4*c**5)/(pi**2*h**3))
    f = ((2*x**3-3*x)*math.sqrt(x**2+1)+3*math.log(math.sqrt(x**1+1)+x))
    return aux*f

plt.style.use('ggplot')
fig, ax = plt.subplots()

x = [x for x in range(10000)]
numerico = [integral(item) for item in x]
ax.plot(x,numerico)
ax.plot(x, func_analitica(x))

plt.show()
