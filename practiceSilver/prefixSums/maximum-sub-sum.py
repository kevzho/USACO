n = int(input())

a = list(map(int, input().split()))

max_sum = float('-inf')
curr = 0

for x in a:
    curr += x
    max_sum = max(max_sum, curr)

    if curr < 0:
        curr = 0

print(max_sum)