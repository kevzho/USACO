N = 4

adj_matrix = [[0 for _ in range(N)] for _ in range(N)]

edges = [(0, 1), (1, 2), (2, 3), (3, 0)]

for i, j in edges:
    adj_matrix[i][j] = 1
    #For undirected graph: adj_matrix[j][i] = 1 

print("Adjacency Matrix:")
for row in adj_matrix:
    print(row)