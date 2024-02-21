import matplotlib.pyplot as plt
import numpy as np

#Define 'e' e 'pi'
e, pi = np.e, np.pi

#Define a função distribuição em função dos parâmetros: E, E_f e T
def f(E,E_f, T):
    k_b = 1.380649*10**(-23) #Define a constante de Boltzmann
    dem = 1+e**((E-E_f)/(k_b*T)) #Define o Denominador
    return 1/dem

def main():
    #Define a enegia de Fermi e a temperatura
    E_f = 4000
    T = 5000

    #Define a lista de energias
    energy = []
    frequency = []

    #Iteração para preencher as frequcias
    E_final = 10000
    for E in range(E_final):
       energy.append(E)
       frequency.append(f(E,E_f,T))

    #Plota o gráfico
    plt.style.use('Solarize_Light2')
    fig, ax = plt.subplots()

    ax.plot(energy, frequency)
    ax.set_title('Fermi-Dirac Distribution')
    ax.set_xlabel('E')
    ax.set_ylabel('f(E)')
    ax.set(xticks=np.linspace(0,E_final,21), yticks=np.linspace(-0.1, 1.01, 21))

    plt.show()

if __name__=='__main__':
    main()
