import sys 

sys.stdin = open('bcount.in', 'r')
sys.stdout = open('bcount.out', 'w')

input = sys.stdin.readline

N, Q = map(int, input().split())

#create prefix sum for all 3 cow id's

prefix = [[0]*4 for _ in range(N + 1)]

for i in range(1, N + 1):
    b = int(input())
    for j in range(1, 4):
        prefix[i][j] = prefix[i - 1][j]
    prefix[i][b] += 1

for _ in range(Q):
    a, b = map(int, input().split())
    print(f"{prefix[b][1] - prefix[a - 1][1]} {prefix[b][2] - prefix[a - 1][2]} {prefix[b][3] - prefix[a - 1][3]}")
