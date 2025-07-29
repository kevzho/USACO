n = int(input())
x = list(map(int, input().split()))
y = list(map(int, input().split()))

max_dist = 0
for i in range(len(x)):
    for j in range(i + 1, len(y)):
        max_dist = max(max_dist, (y[j] - y[i])**2 + (x[j] - x[i])**2)

print(max_dist)