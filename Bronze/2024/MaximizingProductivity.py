N,Q = map(int,input().split())
close = list(map(int,input().split()))
thing = list(map(int,input().split()))

newlist = []
for i,r in zip(close,thing):
    newlist.append(i-r)

newlist.sort(reverse=True)
lol = []

amount = 0
i = 0
print(newlist)
while i < N-1:
    print(lol,i)
    if newlist[i+1] <=0:
        for _ in range(newlist[i]):
             
            lol.append(amount+1)
        break

    elif newlist[i] != newlist[i+1]:
        amount += 1
        for _ in range(newlist[i]-newlist[i+1]):

            lol.append(amount)
        i += 1
    else:
        
        amount += 1
        while newlist[i] == newlist[i+1]:

            i+= 1
            amount += 1
        i+=1
        lol.append(amount)


print(lol)




'''for i in range(Q):
    V,S = map(int,input().split())'''