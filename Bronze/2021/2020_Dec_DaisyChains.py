n = int(input())

nums = list(map(int, input().split()))
count = 0
numstart = 0
average = [0] * n
for i in range(len(nums)):
    numstart += nums[i]
    average[i] = numstart

for i in range(len(average)):
    for r in range(i, len(average)):
        length = r - i + 1

        if   i-1 < 0:
            num = average[r]
        else:
            num = average[r] - average[i-1]
        averagenum = num / length
        if averagenum in nums[i:r+1]:
            count += 1

print(count)