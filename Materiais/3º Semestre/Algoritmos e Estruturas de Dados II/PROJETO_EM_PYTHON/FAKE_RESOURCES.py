from pandas import DataFrame as df
from random import randint
from faker import Faker

fake = Faker('pt-BR')

dados = {'id': [], 'nome': [], 'idade': [], 'origem': [], 'doente': [], 'especializado': []}

indices = []
for i in range(1,27):
    for j in range(5):
        indices.append(i)
        
count = 1
for i in range(1,27):
    for j in range(1,6):
        dados['id'].append(1000 + count)
        count += 1
        
        dados['nome'].append(fake.name())
        dados['idade'].append(randint(5, 70))
        dados['origem'].append(1000 + i)
        dados['doente'].append(randint(0,1))
        dados['especializado'].append(randint(0,1))
        
df(dados, index = indices).to_csv('teste.csv')