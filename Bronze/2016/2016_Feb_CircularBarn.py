# Source: https://usaco.guide/general/io

n = int(input())
r = []
for i in range(n):
    r.append(int(input()))

maximun = 1000000000000000000000000000000000
for i in range(n):
    add = 0
    
    for cap in range(n):
        add+= (cap)*r[cap]
        
    r.append(r[0])
    r.pop(0)
    
    maximun = min(maximun,add)
print(maximun)