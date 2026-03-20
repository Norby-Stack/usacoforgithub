# https://usaco.org/index.php?page=viewproblem2&cpid=1059

nums = list(map(int, input().split()))

nums.sort()


A = nums[0]
B = nums[1]
C = nums[-1] - A - B

print(A,B,C)