def a(x,n):
    if n==0:
        return 100
    else:
        return (1/2)*(a(x,n-1)+x/a(x,n-1))

x = 100

for n in range(10):
    print(a(x,n))
