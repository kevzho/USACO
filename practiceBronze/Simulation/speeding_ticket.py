#USACO 2015 December Contest, Bronze Problem 2. Speeding Ticket

with open("speeding.in", "r") as f:
    lines = f.readlines()

N, M = map(int, lines[0].split())

limits = [list(map(int, line.split())) for line in lines[1:N+1]]
speed = [list(map(int, line.split())) for line in lines[N+1:N+M+1]]

max_over = 0

idx = 0
for i in range(len(limits)):
    #comparing distances
    while limits[i][0] != 0:
        subtract = min(limits[i][0], speed[idx][0])
        limits[i][0] -= subtract
        speed[idx][0] -= subtract
        max_over = max(max_over, speed[idx][1] - limits[i][1])
        if speed[idx][0] == 0:
            idx += 1

with open("speeding.out", "w") as f:
    f.write(str(max_over))
    
    
