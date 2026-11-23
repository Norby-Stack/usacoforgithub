import sys
input=sys.stdin.readline
print=sys.stdout.write
from collections import defaultdict
length,turns = input().split()
length = int(length)
turns = int(turns)

rowl = {}
rowr = {}
rowt = {}

rowl = defaultdict(int)
rowr = defaultdict(int)
rowt = defaultdict(int)
amount = 0
for i in range(turns):
    x,y,z=map(int,input().split())
    rowl[(x,y)] += 1
    if rowl[(x,y)] == length:
        amount += 1
    rowr[(z,y)] += 1
    if rowr[(z,y)] == length:
        amount += 1
    rowt[(z,x)]  += 1
    if rowt[(z,x)] == length:
        amount += 1
    print(str(amount)+"\n")
   