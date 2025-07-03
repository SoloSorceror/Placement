1. What is a Graph?
A graph is a data structure consisting of a set of vertices (or nodes) and a set of edges (connections between the vertices). Graphs can be:

Directed (edges have direction)
Undirected (edges have no direction)

Weighted (edges have weights/costs)
Unweighted (edges are just connections)

2. Graph Representation Methods
2.1. Adjacency List

Explanation:
An adjacency list represents a graph as an array (or vector) of lists.
Each index of the array represents a vertex.
The list at each index contains all the vertices adjacent to that vertex.

Advantages:
Space efficient for sparse graphs (graphs with fewer edges).
Easy to iterate over all neighbors of a vertex.

Disadvantages:
Checking if a specific edge exists can be slower (O(degree of vertex)).

2.2. Adjacency Matrix
Explanation: An adjacency matrix is a 2D array of size V×V where V is the number of vertices.

If there is an edge from vertex i to vertex j, matrix[i][j] is 1 (or the weight, if weighted); otherwise, it is 0.

Advantages:
Very fast to check if an edge exists (O(1)).
Simple to implement.

Disadvantages:
Uses more space, especially for sparse graphs (O(V^2) space).