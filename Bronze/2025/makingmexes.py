N = int(input())
array = list(map(int, input().split()))

count = [0]*(N+1)
for i in array:
    count[i] += 1   


amount_missing = 0
for i in range( N+1):
    if amount_missing-count[i]<= 0:
        print(count[i])
    else:
        print(amount_missing)
    if count[i] == 0:
        amount_missing += 1

