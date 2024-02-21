s = input()
if s=='q':
    def f(x):
        return x**2
elif s=='c':
    def f(x):
        return x**3
else:
    def f(x):
        return 0
print(f(2))
