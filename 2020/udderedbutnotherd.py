alphabet = input().strip()

word = input().strip()

amounttimes = 1
pos = 0
for i in word:

    position = alphabet.index(i)
    
    if position <= pos:
        amounttimes += 1
    pos = position
    
print(amounttimes)