N = int(input())



def solve():
    answer = ""
    u = ""
    d = ""
    l = ""
    r = ""
    x = 0
    y = 0
    string = str(input())
    for pos,i in enumerate(string):
        if i == 'N':
            y += 1
        elif i == 'E':
            x += 1
        elif i == 'S':
            y -= 1
        else:
            x -= 1
    
        if x == 0:
            
            if pos+1 == len(string):
                break
            if string[pos+1] != "S":
                u = [string[pos+1],y]
                
            
            if string[pos+1] != "N":
                d = [string[pos+1],y]
        elif y == 0:


            if string[pos+1] != "E":
                l = [string[pos+1],x]

            if string[pos+1] != "W":
                r = [string[pos+1],x]

    if u[0] != "":
        if u[0] == "E":
            answer = "CW"
        else:
            answer = "CCW"
    elif d[0] != "":
        if d[0] == "E":
            answer = "CCW"
        else:
            answer = "CW"
    elif l[0] != "":
        if l[0] == "S":
            answer = "CCW"
        else:
            answer = "CW"
    elif r[0] != "":
        if r[0] == "N":
            answer = "CCW"
        else:
            answer = "CW"
    
    print(answer)

for i in range(N):
    solve()