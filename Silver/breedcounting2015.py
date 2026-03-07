cows = []

n,q = map(int,input().split())

current = (0,0,0)
for i in range(n):
    num = int(input())
    if num == 1:
        current = (current[0]+1,current[1],current[2])
    elif num == 2: 
        current = (current[0],current[1]+1,current[2])
    else:
        current = (current[0],current[1],current[2]+1)
    cows.append(current)

for i in range(q):
    a,b = map(int,input().split())
    if a == 1:
        print(cows[b-1][0],cows[b-1][1],cows[b-1][2])
    else:
        print(cows[b-1][0]-cows[a-2][0],cows[b-1][1]-cows[a-2][1],cows[b-1][2]-cows[a-2][2])




    