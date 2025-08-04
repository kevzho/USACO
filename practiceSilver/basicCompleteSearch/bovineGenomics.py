#USACO 2017 US Open Contest, Silver Problem 2. Bovine Genomics
from itertools import combinations

with open("cownomics.in", "r") as f:
    lines = f.readlines()

#getting n & m
n, m = map(int, lines[0].split())

#splitting genomes into spotty & normal genomic sequences
spotty = [line.strip() for line in lines[1:n + 1]]
normal = [line.strip() for line in lines[n + 1:]]

count = 0

#iterate through each combination possible
for i, j, k in combinations(range(m), 3):
    #using tuples to check for sequences of possible spotty genomes 
    spotty_seen = set((s[i], s[j], s[k]) for s in spotty)

    if all((n[i], n[j], n[k]) not in spotty_seen for n in normal):
        count += 1

with open("cownomics.out", "w") as f:
    f.write(str(count))