# Source: https://usaco.guide/general/io

amount = int(input())
lstsub = [45,445,4445,44445,444445,4444445,44444445,444444445,4444444445,44444444445]
lst = [5,60,615,6170,61725,617280,6172835,61728390,617283945,6172839500,0]
for i in range(amount):
    number = input().strip()
    lastnum = int(number[0])
    length = int(len(number))
    if int(number) <= 44:
        print(0)
        continue
    if lastnum < 4:
        print(lst[length-3])
    elif lastnum > 4:
        print(lst[length-2])
    else:
        x = int(number)-lstsub[length-2]+1

        if x <=0:
            print(lst[length-3])
        else:
            print(lst[length-3]+x)
