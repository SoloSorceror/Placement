// Breadth-First Search (BFS)
// Explanation
// BFS explores the graph level by level.

// It uses a queue to keep track of the next vertex to visit.
// BFS is great for finding the shortest path in unweighted graphs.

// Flow
// Start from a source vertex.
// Mark it as visited and enqueue it.
// While the queue is not empty:
// Dequeue a vertex.
// For each unvisited neighbor, mark as visited and enqueue.

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(int start, const vector<vector<int>>& adj, vector<bool>& visited) {
    queue<int> q;
    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    int V = 5;
    vector<vector<int>> adj(V);

    // Example edges (undirected)
    adj[0] = {1, 4};
    adj[1] = {0, 2, 3, 4};
    adj[2] = {1, 3};
    adj[3] = {1, 2, 4};
    adj[4] = {0, 1, 3};

    vector<bool> visited(V, false);
    cout << "BFS Traversal starting from node 0: ";
    bfs(0, adj, visited);
    cout << endl;
    return 0;
}
