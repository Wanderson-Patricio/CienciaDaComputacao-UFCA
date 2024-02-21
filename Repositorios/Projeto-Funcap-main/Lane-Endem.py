import matplotlib.pyplot as plt
import numpy as np

x = [0]
y = [1]
y_prime = [0]

passos = 10000
delta_x = 1/passos

n=3

i = 0
while y[-1]>0:
  x.append(x[i]+delta_x)
  if i>0:
    derivada = (y[i]-y[i-1])/(x[i]-x[i-1])
    y_prime.append(derivada)
  ratio = (x[i]/x[i+1])**2
  delta_y=ratio*(y_prime[i]-delta_x*((y[i])**n))*delta_x
  y.append(y[i]+delta_y)
  i=i+1
  
plt.style.use('Solarize_Light2')
fig, ax = plt.subplots()

ax.plot(x,y)

plt.show()
