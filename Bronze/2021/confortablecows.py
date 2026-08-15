N = int(input())

lst = []
for _ in range(1000):
    lst.append([[False,0] for _ in range(1000)])
counter = 0
for _ in range(N):
    x,y = map(int,input().split())
    lst[x][y][0] = True
    
    neigh = 0
    for dx, dy in [(-1,0),(1,0),(0,-1),(0,1)]:
        nx, ny = x+dx, y+dy
        if 0 <= nx < 1000 and 0 <= ny < 1000:
            if lst[nx][ny][0]:
                neigh += 1

    lst[x][y][1] = neigh

    if neigh == 3:
        counter += 1


    if x-1>=0:
        lst[x-1][y][1] += 1
        if lst[x-1][y][1]  == 3 and lst[x-1][y][0]:
            counter +=1
        elif lst[x-1][y][1]  == 4 and lst[x-1][y][0]:
            counter -= 1
    if x+1 <= 999:
        lst[x+1][y][1]  += 1
        if lst[x+1][y][1]  == 3 and lst[x+1][y][0]:
            counter +=1
        elif lst[x+1][y][1]  == 4 and lst[x+1][y][0]:
            counter -= 1
    if y-1>=0:
        lst[x][y-1][1]  += 1
        if lst[x][y-1][1]  == 3 and lst[x][y-1][0]:
            counter +=1
        elif lst[x][y-1][1]  == 4 and lst[x][y-1][0]:
            counter -= 1
    if y+1 <= 999:
        lst[x][y+1][1]  += 1
        if lst[x][y+1][1]  == 3 and lst[x][y+1][0]:
            counter +=1
        elif lst[x][y+1][1]  == 4 and lst[x][y+1][0]:
            counter -=1
    print(counter)