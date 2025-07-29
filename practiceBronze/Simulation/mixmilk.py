#USACO 2018 December Contest, Bronze Problem 1. Mixing Milk

import os
print(os.getcwd())

#change for testing
read = open("mixmilk.in")

#contains 2 spaced separated integer : caacity of first bucket & amount of milk in first bucket. milk will not be overflowing
#same for second and 3 lines

buckets = [list(map(int, read.readline().split())) for _ in range(3)]
#buckets[i][0] is the capacity of bucket i, buckets[i][1] is the amount of milk in bucket 

for i in range(100):
    #pour milk
    src = i % 3
    dest = (i + 1) % 3
    pour = min(buckets[src][1], buckets[dest][0] - buckets[dest][1]) #buckets[0][1] is the amount of milk in bucket 0, buckets [1][0] - buckets[1][1] remaining space in bucket 2
    buckets[src][1] -= pour
    buckets[dest][1] += pour

with open("mixmilk.out", "w") as f:
    for bucket in buckets:
        f.write(str(bucket[1]) + "\n")