size = int(input())

cows = sorted(list(map(int,input().split())))
stalls = sorted(list(map(int,input().split())))

stallworks = [0]*size
for i in range(size):
    for r in range(size):
        if cows[i] <= stalls[r]:
            stallworks[i] += 1

possibilities = 1
for i in range(size - 1, -1, -1):
	possibilities *= stallworks[i] - (size - i - 1)
print(possibilities)