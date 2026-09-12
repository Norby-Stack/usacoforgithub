# Source: https://usaco.guide/general/io

board = []

for i in range(3):
    board.append(input().strip())

single = []
double = []

for i in range(3):

    peices = board[i]
    length = "".join(set(peices))
    if len(length) == 2:
        double.append("".join(sorted(length)))
    if len(length) == 1:
        single.append("".join(sorted(length))) 



for i in range(3):

    peices = board[0][i] + board[1][i] + board[2][i]
    length = "".join(set(peices))
    if len(length) == 2:
        double.append("".join(sorted(length)))
    if len(length) == 1:
        single.append("".join(sorted(length)))



peices = board[0][0] + board[1][1] + board[2][2]
length = "".join(set(peices))

if len(length) == 2:
    double.append("".join(sorted(length)))
if len(length) == 1:
    single.append("".join(sorted(length)))

peices = board[0][2] + board[1][1] + board[2][0]
length = "".join(set(peices))

if len(length) == 2:
    double.append("".join(sorted(length)))
if len(length) == 1:
    single.append("".join(sorted(length)))

print(len(set(single)))
print(len(set(double)))