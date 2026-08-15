T = int(input())
def solve():
    N = int(input())
    cows = list(map(int,input().split()))
    works = set()
    if N == 1:
        print(cows[0])
    elif N == 2:
        if cows[0] == cows[1]:
            print(cows[0])
        else:
            print(-1)
    else:
        if cows[-1] == cows[-2]: 
            works.add(cows[-1])
        for i in range(N-2):
            if cows[i] == cows[i+2] or cows[i] == cows[i+1]:
                works.add(cows[i])
            
        if len(works) == 0:
            print(-1)
        else:
            print(*sorted(list(works)))
for _ in range(T):
    solve()