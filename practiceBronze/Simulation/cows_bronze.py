#USACO 2019 January Contest, Bronze Problem 1. Shell Game

read = open("shell.in")

n = int(read.readline())

#create a list of 3 integers to simluate the shells
sim  = [i for i in range(3)]

#initialize counter to count how many times each shell is guessed
counter = [0, 0, 0]

for i in range(n):
    a, b, g = [int(i) - 1 for i in read.readline().split()]
    #swap the shells
    sim[a], sim[b] = sim[b], sim[a]
    #increment the counter for the guessed shell
    counter[sim[g]] += 1

#now all we have to do is to find the max counter value and its index
print(max(counter), file=open("shell.out", "w"))
