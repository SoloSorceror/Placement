#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool isCycle(int V, vector<vector<int>>& adj) {
        vector<bool> visited(V, false);

        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                if (bfs(i, adj, visited)) {
                    return true;
                }
            }
        }

        return false;
    }

private:
    bool bfs(int start, vector<vector<int>>& adj, vector<bool>& visited) {
        queue<pair<int, int>> q; // {node, parent}
        visited[start] = true;
        q.push({start, -1});

        while (!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push({neighbor, node});
                } else if (neighbor != parent) {
                    return true; // Cycle found
                }
            }
        }

        return false;
    }
};
