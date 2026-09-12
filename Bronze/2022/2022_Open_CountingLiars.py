N = int(input())

lst = []

for i in range(N):
    c1,c2 = map(str,input().split())

    lst.append((c1,int(c2)))

smallestlie = 1000000000000000000000000000000000000000000000000000000000
for i,num in lst:
    amountoflies = 0
    for dir,cur_num in lst:
        if dir == "L":
            if cur_num > num:
                amountoflies += 1
        else:
            if cur_num < num:
                amountoflies += 1
    smallestlie = min(smallestlie,amountoflies)
print(smallestlie)