N = int(input())
cows = list(map(int, input().split()))
cows = sorted(cows, reverse=True)


start_index = 0

amount = 1

prevcow = cows[0]
thingy = {prevcow:1}
for i in range(1,N):
    amount += 1
    if cows[i] == prevcow:
        thingy[prevcow] = amount
    else:
        prevcow = cows[i]
        thingy[prevcow] = amount
print(thingy)
maximun = 0

for i, r in reversed(thingy.items()):
    if i * r > maximun:
        maximun = i * r
        hehe = i
print(maximun, hehe)