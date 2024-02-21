class passenger:
    
    def __init__(self, id: str, nome: str, idade: int, origem: str, doente: bool, especializado: bool) -> None:
        self.id = id
        self.nome = nome
        self.idade = idade
        self.origem = origem
        self.doente = doente
        self.especializado = especializado
        
    def __str__(self) -> str:
        info = f'Nome: {self.nome} \n'
        info += f'Idade: {self.idade} anos \n'
        info += f'Id: {self.id} \n'
        info += f'Planeta de origem: {self.origem} \n'
        info += 'Possui especialização \n' if self.especializado else 'Não possui especialização \n'
        info += 'Está doente \n' if self.doente else 'Não está doente \n'
        info += '\n'
        
        return info
    