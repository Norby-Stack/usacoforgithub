n = int(input())



def solve():
    l = int(input())
    lst = list(map(int,input().split()))
    lengthrn = len(lst)
    sumlst = sum(lst)
    factors = []
    if sumlst == 0:
        print(0)
        return
    else:
        for i in range(1,sumlst+1):
            if sumlst % i == 0:
                factors.append(i)
    
        
        
        for i in factors:
            work = True
            count = 0
            length = len(lst)
            lstcopy = lst.copy()
            
            while True:
                
                if count >= length-1:
                    break
                if lstcopy[count] > i:
                    work = False
                    break
                elif lstcopy[count] == i:
                    count+= 1
                else:
                    lstcopy[count] += lstcopy[count+1]
                    lstcopy.pop(count+1)
                    length-= 1
                
           
           
            if work:
                print(lengthrn-length)
                break
        
            
        
for i in range(n):
    solve()
            