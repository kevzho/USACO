import sys

sys.stdin = open('herding.in', 'r')
sys.stdout = open('herding.out', 'w')

arr = list(map(int, input().split()))
arr.sort()

x, y, z = arr

#find the two gaps
gap1 = y - x
gap2 = z - y

#calculating minimum moves -> if either gap is 1, then 0 moves needed
#if either of the gaps are 2, then 1 move is needed. 
#Otherwise, only 2 moves are needed no matter how big the gap is.

#This is because in one move, you can always reduce one of the gaps to 1 or 2, so at most 2 moves are needed.
if gap1 == 1 and gap2 == 1:
    min_moves = 0
elif gap1 == 2 or gap2 == 2:
    min_moves = 1
else:
    min_moves = 2

#max moves can be found by calcualting the largest gap and moving the other two cows towards each other one by one,
#resulting in max moves being largest gap - 1
max_moves = max(gap1, gap2) - 1

print(min_moves)
print(max_moves)