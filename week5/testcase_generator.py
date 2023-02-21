import random
with open('t.txt') as fp:
    f = fp.readline()
    print(f.strip('\n'),100,random.randint(500,1000))
    print(' '.join(map(str,random.sample(range(1,1000),100))))
    i = fp.readlines()[1:]
for j in i:
    print(j.strip('\n'),random.randint(0,1))