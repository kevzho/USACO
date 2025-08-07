#subsets with max length n
n = int(input())
weights = list(map(int, input().split()))

ans = float("inf")
for mask in range(1 << n):
    sum1 = 0
    sum2 = 0
    for i in range(n):
        if mask & (1 << i):
            sum1 += weights[i]
        else:
            sum2 += weights[i]
    
    ans = min(ans, abs(sum1 - sum2))

print(ans)