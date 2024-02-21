from passenger import passenger
from random import randint

class nave:
    
    def __init__(self, id: str, recursos: list[str], passageiros: list[passenger]) -> None:
        self.id = id
        self.recursos = recursos
        self.passageiros = passageiros
        
        self.prioridade: int = randint(0, 100)
        
    def __str__(self) -> str:
        info = '******************************************************* \n'
        
        info += f'Id da nave: {self.id} \n'
        info += f'Prioridade: {self.prioridade} \n'
        info += '------Recursos na nave------ \n'
        
        for index, recurso in enumerate(self.recursos):
            info += f'{index + 1} - ' + recurso + '\n'
            
        info += '------Passageiros na nave------ \n'
        
        for pessoa in self.passageiros:
            info += pessoa.__str__()
        
        info += '******************************************************* \n'
        
        return info
    
    def verificar_prioridade(self) -> None:
        probabilidade = randint(1, 10)
        
        if probabilidade == 10:
            self.prioridade = randint(0, 100)
    
    
  







'''      
wanderson = passenger('TER0001', 'Wanderson', 21, 'TER', True, False)

resources = ['ARROZ', 'FEIJÃO', 'CARNE']

nave = nave('TER0001', resources, [wanderson for i in range(10)])
print(nave)
'''