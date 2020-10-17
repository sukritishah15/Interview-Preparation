# Graphs


### Graph
1. Graph is a set of vertices and a set of edges connecting them.
2. A graph is a pair (V,E), 
where V is a set of nodes, called vertices, 
and E is a collection of pairs of vertices,
called edges. 
3. Example - Social Media Network, Road network in a country, Representing relationships between components in electronic circuits, Computer Networks (LAN, Internet etc.), ER Diagrams

### Directed Edge 
1. Ordered pair of vertices (u,v)
2. First vertex u is the origin
3. Second vertex v is the destination
4. Example - one-way road traffic

### Undirected Edge
1. Unordered pair of vertices (u,v)
2. Example - Railway lines

### Directed Graph 
1. All edges are directed.
2. Example - Route network

### Undirected Graph
1. All edges are undirected.
2. Example - Flight network

### Adjacent Vertices
1. Vertices are said to be adjacent when they are connected by an edge incident on both of them i.e. a direct edge.

### Tree is a special kind of graph
1. All nodes are connected i.e. there would exist a path from any node to any other node.
2. It has NO CYCLES
3. **A tree is an acyclic connected graph.**

### Self Loop
1. A self loop is an edge that connects a vertex to itself.

### Parallel Edges 
1. Two edges are parallel if they connect the same pair of vertices.

### Degree of a vertex
1. Degree of a vertex is the no. of edges incident on it.

### Subgraph
1. It is a subset of graph's edges (with associated vertices) that form a graph

### Path
1. It is a collection of edges through which one can reach from one node to the other.
2. It is a sequence of adjacent vertices.
3. **Simple Path** - A path with no repeated vertices.

### Cycle 
1. A path where the first and last vertices are the same.
2. **Simple Cycle** - A cycle with no repeated edges or vertices (except the first and last one).

### Connected vertices
1. One vertex is connected to another if there is a **path** that contains both of them.

### Connected Graph
1. A graph is connected if there is a **path** from every vertex to every other vertex.

### Connected Components
1. A graph that is not connected, consists of a set of connected components.

### Directed Acyclic Graph (DAG)
1. A directed graph with no cycles.

### Complete Graphs
1. A graph with all edges present i.e. a graph in which every vertex is connected to every other vertex.

### Sparse Graphs
1. A graph with relatively few edges [Generally, Edges<(V*log(V)) ]

### Dense Graphs
1. A graph with relatively less missing edges is called dense.

### Weighted Graphs
1. A graph in which integers (weights) are assigned to each edge (to represent distances or costs).

- **Directed Weighted Graphs** are sometimes called **network**.

**Important note**
- If we are given a graph with n vertices, then -
1. Minimum no. of edges in the graph = 0
2. Minimum no. of edges in an acyclic connected graph (i.e. a tree) = n-1
3. Minimum no. of edges in a complete graph = nC2 = n*(n-1)/2
4. Basically, we can say that min. no. of edges can be O(n) and max. no. of edges can be O(n^2), which means that **No. of edges are quadratic in terms of no. of vertices.**

### Forest
1. Disjoint set of trees

### Spanning Tree
1. A spanning tree of a **connected graph**
is a subgraph that contains all the graph's vertices and 
is a single tree.

### Spanning Forest
1. In a graph,
the **union of spanning trees of connected components of the graph** form
a spanning forest.

### Bipartite Graph
1. A graph whose vertices can be divided into two sets,
such that all edges connect,
a vertex in one set with a vertex in the other set.



## Representation of Graphs

1. Adjacency Matrix - We use a matrix of size V*V.
- In case of unweighted graphs - Boolean matrix - Initialized/Filled with 0's
- In case of weighted graphs - Integer matrix - Initialized/Filled with 0's
- To represent an undirected edge between u and v, adjMat[u][v]=1 and adjMat[v][u]=1
- To represent a directed edge from u to v, adjMat[u][v]=1 
- Space Complexity - O(V^2)
- Time Complexity - 
a. Lookup time - O(1)
b. Initialization - O(V^2)
- Disadvantageous in case of Sparse Graphs

2. Adjacency List - All vertices connected to a vertex V, are added to the adjacency list corresponding to V.
- Easy implementation via Linked List.
- Space Complexity - O(E+V)
- Time Complexity - Lookup time - O(V)
- Disadvantageous, if nodes are to be deleted.



## Graph Traversals

Graph traversal means visiting every vertex and edge exactly once in a well-defined order. While using certain graph algorithms, you must ensure that each vertex of the graph is visited exactly once. The order in which the vertices are visited are important and may depend upon the algorithm or question that you are solving.

During a traversal, it is important that you track which vertices have been visited. The most common way of tracking vertices is to mark them.

1. Depth First Search (DFS)
- Works similar to preorder traversal of trees
- Like preorder traversal, it also uses stack, internally












