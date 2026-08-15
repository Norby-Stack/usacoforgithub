N, M = map(int, input().split())
directions = input().strip()

milk = list(map(int,input().split()))


change = [0] * N

for i in range(1, N - 1):
    if directions[i] == 'R':
        change[i + 1] += 1
        change[i] -= 1
    else:
        change[i - 1] += 1
        change[i] -= 1

if directions[0] == 'R':
    change[1] += 1
    change[0] -= 1
elif directions[0] == 'L':
    change[N - 1] += 1
    change[0] -= 1
elif directions[N - 1] == 'L':
    change[N - 2] += 1
    change[N - 1] -= 1
elif directions[N - 1] == 'R':
    change[0] += 1
    change[N - 1] -= 1

for i in range(N):
    milk[i] += min(milk[i], max(0, change[i] * M))

print(sum(milk))