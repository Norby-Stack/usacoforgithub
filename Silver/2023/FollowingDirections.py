N = int(input())
matrix = []

for _ in range(N):
    row, num = input().split()
    matrix.append(list(row)+[num])
matrix.append(input().split())

counter = []
for _ in range(N):
    counter.append([1]*N+[0])
counter.append([0]*N)

for row in range(N):
    for col in range(N):
        if matrix[row][col] == 'R':
            counter[row][col+1] += counter[row][col]
        else:
            counter[row+1][col] += counter[row][col]

ans = 0
for i in range(N):
    ans += int(matrix[i][N])*counter[i][N]
for i,r in zip(counter[N],matrix[N]):
    ans += int(i)*int(r)

print(ans)
def update(px, py, delta):
    global ans
    while True:
        if px >= N or py >= N:
            ans += delta * counter[x][y] * int(matrix[px][py])
            break

        counter[px][py] += delta * counter[x][y]

        if matrix[px][py] == 'R':
            py += 1
        else:
            px += 1


Q = int(input())
for i in range(Q):
    x, y = map(int, input().split())
    x -= 1
    y -= 1

    if matrix[x][y] == 'R':
        # old path (right)
        update(x, y + 1, -1)

        # new path (down)
        update(x + 1, y, 1)

        matrix[x][y] = 'D'
    else:
        # old path (down)
        update(x + 1, y, -1)

        # new path (right)
        update(x, y + 1, 1)
    
        matrix[x][y] = 'R'

    print(ans)