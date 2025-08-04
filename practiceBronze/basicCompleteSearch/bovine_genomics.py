<<<<<<< HEAD
#USACO 2017 US OPen Contest, Bronze Problem #2. Bovine Genomics

with open("cownomics.in", "r") as f:
    lines = f.readlines()

#getting n & m
n, m = map(int, lines[0].split())

#splitting genomes into spotty & normal genomic sequences
spotty = [line.strip() for line in lines[1:n + 1]]
normal = [line.strip() for line in lines[n + 1:]]

count = 0

#iterate through the length of the entire genomic sequence
for i in range(m):
    #create a set to see what were the possible healthy genomes 
    possible = set()
    for j in range(n):
        possible.add(normal[j][i])
    
    #if there was even ONE spotty cow that had a genome in the same spot as a healthy one, then the current genome would not affect the mutation
    confirmed = True
    for k in range(n):
        if spotty[k][i] in possible:
            confirmed = False
    
    #if confirmed stays true, increase count by one
    if confirmed:
        count += 1

with open("cownomics.out", "w") as f:
=======
#USACO 2017 US OPen Contest, Bronze Problem #2. Bovine Genomics

with open("cownomics.in", "r") as f:
    lines = f.readlines()

#getting n & m
n, m = map(int, lines[0].split())

#splitting genomes into spotty & normal genomic sequences
spotty = [line.strip() for line in lines[1:n + 1]]
normal = [line.strip() for line in lines[n + 1:]]

count = 0

#iterate through the length of the entire genomic sequence
for i in range(m):
    #create a set to see what were the possible healthy genomes 
    possible = set()
    for j in range(n):
        possible.add(normal[j][i])
    
    #if there was even ONE spotty cow that had a genome in the same spot as a healthy one, then the current genome would not affect the mutation
    confirmed = True
    for k in range(n):
        if spotty[k][i] in possible:
            confirmed = False
    
    #if confirmed stays true, increase count by one
    if confirmed:
        count += 1

with open("cownomics.out", "w") as f:
>>>>>>> fbbdee5b55c52884146d22b9479bb0d98dcb4864
    f.write(str(count))