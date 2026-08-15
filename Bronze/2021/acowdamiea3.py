N,M = map(int,input().split())

matrix = []

for i in range(N):
    row = list(input().strip())
    matrix.append(row)
bob = 0
visited = set()
for row in range(len(matrix)):
    for col in range(len(matrix[row])):
        char = matrix[row][col]
        if char == 'G':
            amount = 0
            cowspos = []
            for dx, dy in [(-1,0),(1,0),(0,-1),(0,1)]:
                newx = row + dx
                newy = col + dy
               
                if 0 <= newx < len(matrix) and 0 <= newy < len(matrix[row]):
                    if matrix[newx][newy] == 'C':
                        amount += 1
                        cowspos.append((newx,newy))
            if amount == 2:
                if (cowspos[0],cowspos[1]) not in visited:
                    bob += 1
                    visited.add((cowspos[0],cowspos[1]))
                    visited.add((cowspos[1],cowspos[0]))
                    
            elif amount > 2:
                bob += 1
      
print(bob)