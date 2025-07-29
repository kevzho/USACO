#USACO 2016 December Contest, Bronze Problem #2

#change this once we submit
with open("blocks.in", "r") as f:
    lines = f.readlines()

n = lines[0]

words = [list(map(str, line.split())) for line in lines[1:]]

letters_list = [0]*26

for pair in words:
    one = [0] * 26
    two = [0] * 26
    for char in pair[0]:
        one[ord(char) - ord('a')] += 1
    for char in pair[1]:
        two[ord(char) - ord('a')] += 1
    
    for j in range(26):
        letters_list[j] += max(one[j], two[j])


with open("blocks.out", "w") as f:
    for letter in letters_list:
        f.write(str(letter) + "\n")