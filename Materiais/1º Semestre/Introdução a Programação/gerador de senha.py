import string
from random import choice
tam_senha=int(input('Quantos caracteres terão a senha: '))
carac=string.ascii_letters+string.digits+string.punctuation
senha=''
for i in range(tam_senha):
    senha+=choice(carac)
print('senha gerada: ', senha)
