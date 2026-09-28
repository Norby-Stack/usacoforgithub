'''N = int(input())
nums = [0]


number = 0
for i in range(N):
    n = int(input())
    number += n
    nums.append(number)


print(nums)
p1 = 0
p2 = 1
heightest = -1
while p1 != p2:
    if (nums[p2] - nums[p1]) % 7 == 0:
        heightest = max(heightest,p2-p1)
        p2 += 1
    else:
        p1 += 1'''
	
n = int(input())
prefix = [0]
for _ in range(n): prefix.append((int(input()) + prefix[-1]) % 7)
last_found = [-1 for _ in range(7)]
maxVal = 0

for i in range(n):
    if last_found[prefix[i]] == -1: last_found[prefix[i]] = i
    else:
        maxVal = max(i - last_found[prefix[i]], maxVal)

print(maxVal,prefix)