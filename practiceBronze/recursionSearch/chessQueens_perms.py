from itertools import permutations

n = 8
reserved = [[False] * n for _ in range(n)]

#iterating through each row and column of the chessboard to 
#get the input and the reserved positions
for ro in range(n):
    row = input()
    for co in range(n):
        reserved[ro][co] = (row[co] == '*')

count = 0

#since brute force would be much too slow,we will use permutations as queens
#will not be able to be in the same column (so we can encode a number)
#for each column and get that problem sorted out.
for queens in permutations(range(n)):
    valid = True
    for c in range(n):
        if reserved[queens[c]][c]:
            valid = False
            break
    
    #checking diagonals from top left to bottom right
    taken = [False] * (n * 2 - 1)
    for c in range(n):
        #if the diagonal with sum has been taken (for example, (0, 1) cannot be in the same diagonal as (1, 0))
        if taken[c + queens[c]]:
            valid = False
            break
        taken[c + queens[c]] = True
    
    #checking the diagonals from the top-right to the bottom left
    taken = [False] * (n * 2 - 1)
    for c in range(n):
        #since queens[c] - c can be negative, we add n - 1 to shift it into the positive range
        if taken[queens[c] - c + n - 1]:
            valid = False
            break
        taken[queens[c] - c + n - 1] = True
    
    if valid:
        count += 1
    
print(count)