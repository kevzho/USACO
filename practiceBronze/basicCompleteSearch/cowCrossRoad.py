#USACO 2017 February Contest, Bronze Problem 2. Why Did the Cow Cross the Road II
with open("circlecross.in", "r") as f:
    read = f.readline().strip()

#generate index map
indices = [[] for _ in range(26)]

#track indices for all 52 uppercase letters, 2 indices for each individual letter
for i, char in enumerate(read):
    indices[ord(char) - ord('A')].append(i)

count = 0

#brute-force & check if start index of the first pair is less than the start index of the other pair which is less than the end index of the first pair which is less than the end index of the other pair
#essentially, we're looking for x..y..x..y form.
for i in range(26):
    for j in range(i, 26):
        if (indices[i][0] < indices[j][0] < indices[i][1] < indices[j][1] or 
            indices[j][0] < indices[i][0] < indices[j][1] < indices[i][1]):
            count += 1

with open("circlecross.out", "w") as f:
    f.write(str(count))
