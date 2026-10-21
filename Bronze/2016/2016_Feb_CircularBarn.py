# Source: https://usaco.guide/general/io
# Url: https://usaco.org/index.php?page=viewproblem2&cpid=616

'''
we can simulate all possible starting positions for the cows and then we
can find the maximun of them
'''

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