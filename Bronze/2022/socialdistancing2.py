N = int(input())
cows = []
for i in range(N):
    cows.append(tuple(map(int,(input().split()))))

cows.sort(key=lambda x: x[0])

shortest = 10**7
for i in range(N-1):
    if cows[i][1] == 1 and cows[i+1][1] == 0:
        shortest = min(shortest, cows[i+1][0]-cows[i][0])
    elif cows[i][1] == 0 and cows[i+1][1] == 1:
        shortest = min(shortest, cows[i+1][0]-cows[i][0])


newcowlst = []
for i in range(N):
    if cows[i][1] == 1:
        newcowlst.append(cows[i][0])

length = len(newcowlst)

hehe = 0

for i in range(length-1):
    if newcowlst[i+1]-newcowlst[i] >= shortest:
      
        hehe += 1

print(hehe+1)