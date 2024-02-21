from heap import heap
from nave import nave
from passenger import passenger

MAX_NAVES = 100
MAX_PASSAGEIROS = 5
MAX_RECURSOS = 3


def gera_heap(passageiros: str, recursos: str):
    fila = heap()
    passengers = []
    resources = []
    
    with open(passageiros,  'r') as p:
        linha = 0
        for line in p:
            
            index = 0
            if linha == 0:
                linha = 1
            else:
                line.join(',')
                for data in line:
                    print(data + '  ', end = '')
                    
            print()
                
        
    
    


def inicializar():
    pass


dir_pass = r'C:\Users\Wanderson Patricio\Documents\Materiais - Faculdade\Listas\3º Semestre\Algoritmos e Estruturas de Dados II\PROJETO_EM_PYTHON\HEAP\passageiros.csv'
dir_rec = r'C:\Users\Wanderson Patricio\Documents\Materiais - Faculdade\Listas\3º Semestre\Algoritmos e Estruturas de Dados II\PROJETO_EM_PYTHON\HEAP\recursos.csv'
gera_heap(dir_pass, dir_rec)