N,S = map(int,input().split())

line = []
for i in range(N):
    line.append(tuple(map(int,input().split())))



visited = set()

direction = 1
power = 1
position = S-1
while True:
    if 0 > position or position >= N:
        break
    if line[position][0] == 1:
        if power >= line[position][1]:
            if position not in visited:
                visited.add(position)
        
    else:
        direction *= -1
        power += line[position][1]
    position += direction*power
print(len(visited))