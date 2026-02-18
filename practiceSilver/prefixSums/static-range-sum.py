#python static-range-sum.py < static-range-sum.txt

import sys

input = sys.stdin.read
data = input().split()

idx = 0
N = int(data[idx])
idx += 1
Q = int(data[idx])
idx += 1

a = []

for i in range(N):
    a.append(int(data[idx]))
    idx += 1

prefix = [0] * (N + 1)
for i in range(N):
    prefix[i + 1] = prefix[i] + a[i]

for i in range(Q):
    l = int(data[idx]) + 1
    idx += 1
    r = int(data[idx])
    idx += 1
    
    res = prefix[r] - prefix[l - 1]
    print(res)