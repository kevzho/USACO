# Graph Theory 
[Visualizer](https://csacademy.com/app/graph_editor/)

- Graph is a way to represent relationships between objects
- Objects are called graph **nodes** or **vertices**.
- The relationships between the lines are called **edges**.

### Directed Graphs

- While undirected graphs are mutual, directed graphs have one direction. The edges in an undirected graph are called **arcs**, and now nodes can be differentiated between a *source node* and a *target node*. 
- Asymmetry 

### Graph examples:

- **Word game:** : If you're given a 3 letter word and you want to transform a word into another one by changing the letter, you can model it using graphs, where nodes connected by an edge are words that are different by one single letter. 

      cat
       |
      cot
     /   \
   dot    cog
     \   /
      dog

---

# Graph Representation

### Adjacency Matrix

##### IF DIRECTED:

-  For $N$ vertices, use a $N*N$ binary matrix (outcomes are 0 and 1) where the element on row $i$ and column $j$ is 1 if the arc $(i, j)$ exists in the graph, and 0 otherwise.
- So in our directed graph if $i$ is our source node and $j$ is our target node, (i, j) will be equal to 1 in our 2D matrix if there is an arrow pointing from our source node to our target node.

##### IF UNDIRECTED: 
- Would still be the same thing, except it would also be $(j, i)$ that would be equal to one if there was an edge between nodes $i$ and $j$. 

- Edge lookup is easy, adding & deleting new edges is easy, best for dense graphs. 
- Memory allocation is disadvantage (always N*N matrix), and finding all its **neighbours** for a node requires checking an entire row of elements (to check if there is a "1" in any).

### Adjacency List

##### IF DIRECTED:

- Index is our source node, and in each index, there will be an array with the target nodes. In directed arrays, we'll store the neighbors j only if the arc exists between $(i, j)$.

##### IF UNDIRECTED:

- Same thing, except add ALL neighbors of the source node into the array placed on that specific index. 

- Ideal for storing sparse graphs, but bad for edge lookup and erasing edges. 