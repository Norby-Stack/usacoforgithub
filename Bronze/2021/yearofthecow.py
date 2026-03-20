N = int(input())
years = [
    'Ox',
    'Tiger',
    'Rabbit',
    'Dragon',
    'Snake',
    'Horse',
    'Goat',
    'Monkey',
    'Rooster',
    'Dog',
    'Pig',
    'Rat'
]

cows = {'Bessie':0}



for i in range(N):
    sentence = input().split()
    if sentence[3] == 'previous':
        year = cows[sentence[7]]-1
        while years[year%12]!=sentence[4]:
            year-=1
       
        
    else:
       
        year = cows[sentence[7]]+1
        while years[year%12]!=sentence[4]:
            year+=1

    cows[sentence[0]] = year
print(abs(cows['Elsie']))

