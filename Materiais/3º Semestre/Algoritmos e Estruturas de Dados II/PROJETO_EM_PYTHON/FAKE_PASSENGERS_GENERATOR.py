from faker import Faker
import pandas as pd
from random import choice

fake = Faker()

for i, method in enumerate(dir(fake)):
    print(f'{i+1} : {method}')

