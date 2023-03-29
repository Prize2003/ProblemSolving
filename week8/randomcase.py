n = 10
print(n)
alpha=[chr(i) for i in range(ord("A"),ord("Z")+1)]
m=1000
from random import randint
for i in range(n):
    for j in range(m):
        print(alpha[randint(0,25)],end="")
    print("\n")