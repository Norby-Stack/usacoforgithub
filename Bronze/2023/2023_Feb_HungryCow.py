N, T = map(int, input().split())
hehe = 0

prevday, haybills = map(int, input().split())

for i in range(N-1):
    a,b = map(int, input().split())
    
    if a-prevday >= haybills:
        hehe += haybills
        haybills = 0

    
    else:
        hehe += a-prevday
        haybills -= a-prevday
    prevday = a
    haybills += b
  
if haybills > T-prevday:
    hehe += T-prevday+1
else:
    hehe += haybills
print(hehe) 