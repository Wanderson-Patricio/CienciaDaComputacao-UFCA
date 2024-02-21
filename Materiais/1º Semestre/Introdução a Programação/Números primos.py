def primo(n):
    result = 0
    divisores = 1;
    for i in range(2,n+1):
        if n%i==0:
            divisores += 1
    if divisores == 2:
        result = 1
    return result

for i in range(2,100):
    if primo(i) == 1:
        print(i)
