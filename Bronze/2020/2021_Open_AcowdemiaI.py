N, L = map(int,input().split())
lst = list(map(int,input().split()))
lst.sort(reverse=True)
print(lst)
goup = 10**5+1
for i in range(N):
    if lst[i] <i+1:
        if lst[i]+1 == i+1 and L > 0:
            L -= 1
        else:
            print(i)
            break
    
    
    if goup < i:
        print(i)
        break

    goup = min(goup,lst[i]-1)