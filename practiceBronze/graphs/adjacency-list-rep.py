N = 4

adj_list = [[] for _ in range(N)]

edges = [(0, 1), (1, 2), (2, 3), (3, 0)]

for i, j in edges:
    adj_list[i].append(j)
    #for undirected graph: adj_list[j].append(i)

print("Adjacency List:")
for i, neighbors in enumerate(adj_list):
    print(f"{i}: {neighbors}")