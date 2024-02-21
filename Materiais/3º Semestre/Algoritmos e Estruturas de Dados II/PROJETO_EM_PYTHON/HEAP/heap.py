from nave import nave

MAX_NAVES = 100

class heap:
    
    def __init__(self) -> None:
        self.tamanho: int = 0
        self.naves: list[nave] = [None for _ in range(MAX_NAVES)]
        
    
    def __str__(self) -> str:
        info = 'Naves na fila: \n'
        
        def exibir_nave(h: heap, i: int, info: str):
            if i < h.tamanho:
                info += h.naves[i].__str__()
                
                exibir_nave(h, 2*i, info)
                exibir_nave(h, 2*i + 1, info)
                
        info += exibir_nave(self, 0, info)
        
        return info
    
    
    def subir(self, index: int) -> None:
        j = index//2
        
        if j>=0:
            if self.naves[index].prioridade > self.naves[j].prioridade:
                self.naves[index], self.naves[j] = self.naves[j], self.naves[index]
                
                self.subir(j)
                
    
    def descer(self, index: int) -> None:
        j = 2*index
        
        if j <= self.tamanho - 1:
            if j < self.tamanho - 1:
                if self.naves[j+1].prioridade > self.naves[j].prioridade:
                    j += 1
                    
            if self.naves[index].prioridade < self.naves[j].prioridade:
                self.naves[index], self.naves[j] = self.naves[j], self.naves[index]
                
                self.descer(j)
    
    
    def add(self, nave: nave) -> None:
        if self.tamanho >= MAX_NAVES:
            print('A fila está cheia.')
            return
        
        nave.verificar_prioridade()
        
        self.naves[self.tamanho] = nave
        self.subir(self.tamanho)
        
        self.tamanho += 1
        print('Inserido com sucesso.')
        
        
    def remove(self) -> None:
        if self.tamanho > 0:
            print('Nave a partir')
            print(self.naves[0])
            
            self.naves[0], self.naves[self.tamanho - 1] = self.naves[self.tamanho - 1], self.naves[0]
            self.tamanho -= 1
            
