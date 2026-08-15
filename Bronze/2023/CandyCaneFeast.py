N,M = map(int,input().split())
cows = list(map(int,input().split()))
candies = list(map(int,input().split()))

for candy in candies:
    bottom = 0
    for i in range(len(cows)):
        if cows[i] >= candy:
            cows[i] += candy - bottom
            break
        elif cows[i] > bottom:
            prevbottom = bottom
            bottom = cows[i]
            cows[i] += cows[i] - prevbottom
        
        
for cow in cows:
    print(cow)