N = int(input())
cows = input().strip()
maxdays = 10000000000000000000000000
amountofones = 0
lol = []
for i in range(N):
    if cows[i] == '1':
        amountofones += 1
    else:
        if amountofones > 0:
            lol.append(amountofones)
        amountofones = 0

smallest = 10000000000000000000000000
for i in lol:
    
