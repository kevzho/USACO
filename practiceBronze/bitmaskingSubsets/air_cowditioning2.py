n, m = map(int, input().split())

#cows (start, end, cooling requirement)
cows = [list(map(int, input().split())) for _ in range(n)]

#air conditioners (cooling start, cooling end, reduced temp, cost)
air_conditioners = [list(map(int, input().split())) for _ in range(m)]

min_cost = float("inf")

#iterating through subsets of all air conditioners as a bitmask
for mask in range(1 << m):
    #pruning: compute cost and stop early if it's already too high
    cost = 0
    for i in range(m):
        #check if ith bit of integer is 1 or not (if bit is set in mask)
        if 1 & (mask >> i):
            cost += air_conditioners[i][3] #adding cost
            if cost >= min_cost:
                break
    if cost >= min_cost:
        continue

    #building cooling array using difference array
    diff = [0] * 102
    for i in range(m):
        if (mask >> i) & 1:
            start, end, temp_reduction, price = air_conditioners[i]
            #apply the temp diff at the start of the stalls
            diff[start] += temp_reduction
            #disengage the temp diff at the end of the stalls (stops cooling)
            if end + 1 < len(diff):
                diff[end + 1] -= temp_reduction
            #this step is important for our next step to work correctly

    cooling = [0] * 101
    running = 0
    for s in range(1, 101):
        #accumulate the cooling costs with running sum
        running += diff[s]
        #cooling[s] will tell us the total cooling applied to stall s
        cooling[s] = running
    
    #checking if cows are ok
    ok = True
    for (s, t, c) in cows:
        for stall in range(s, t + 1):
            #checking if their cooling needs aren't met
            if cooling[stall] < c:
                ok = False
                break
        if not ok:
            break
    
    if ok:
        min_cost = min(min_cost, cost)

print(min_cost)