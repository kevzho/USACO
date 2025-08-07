from itertools import permutations

s = input()

# perms is a sorted list of all the permutations of the given string
perms = sorted(set(permutations(s)))

print(len(perms))
for perm in perms:
	print("".join(perm))