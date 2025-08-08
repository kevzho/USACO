n = 8
reserved = [[False] * n for _ in range(n)]

for ro in range(n):
    row = input()
    for co in range(n):
        reserved[ro][co] = (row[co] == '*')

count = 0

rows_taken = [False] * n
#for checking diagonals going from bottom left to top right
diag1 = [False] * (n * 2 - 1)
#checking diagonals going from bottom right to top left
diag2 = [False] * (n * 2 - 1)

def place_queens(col):
    global count

    if col == n:
        count += 1
        return
    
    for row in range(n):
        if not reserved[row][col] and not diag1[row + col] and not diag2[row - col + n - 1] and not rows_taken[row]:
            #placing the queen
            diag1[row + col] = True
            diag2[row - col + n - 1] = True
            rows_taken[row] = True

            place_queens(col + 1)

            #backtrack
            diag1[row + col] = False
            diag2[row - col + n - 1] = False
            rows_taken[row] = False

place_queens(0)
print(count)