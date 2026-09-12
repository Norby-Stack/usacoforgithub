N,K = map(int,input().split())

schedule = list(map(int,input().split()))
total_cost = K+1


for i in range(N-1):
    if schedule[i+1] - schedule[i] + 1 <= K+1:
        
        total_cost += schedule[i+1] - schedule[i]
    else:
        total_cost += K+1
    
print(total_cost)