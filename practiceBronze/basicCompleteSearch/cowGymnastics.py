#USACO 2019 December Contest, Bronze Problem 1. Cow Gymnastics

from collections import defaultdict
with open("gymnastics.in", "r") as f:
    lines = f.readlines()

k, n = list(map(int, lines[0].split()))

placing = [list(map(int, line.split())) for line in lines[1:]]
consistent = defaultdict(int)

count = 0

for place in placing:
    for i in range(n):
        for j in range(i + 1, n):
            consistent[(place[j], place[i])] += 1

for value in consistent.values():
    if value == k:
        count += 1

with open("gymnastics.out", "w") as f:
    f.write(str(count))
            