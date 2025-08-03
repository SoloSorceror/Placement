#include <bits/stdc++.h>
using namespace std;

// User function Template for C++
class Solution
{
public:
    void topoSortDFS(int node, vector<bool> &visited, stack<int> &st, vector<pair<int, int>> adj[])
    {
        visited[node] = true;
        for (auto &neighbor : adj[node])
        {
            int v = neighbor.first;
            if (!visited[v])
            {
                topoSortDFS(v, visited, st, adj);
            }
        }
        st.push(node);
    }

    vector<int> shortestPath(int V, int E, vector<vector<int>> &edges)
    {
        // code here

        // create adjacency list
        vector<pair<int, int>> adj[V];
        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            adj[u].push_back({v, wt});
        }

        // topo sort

        vector<bool> visited(V, false);
        stack<int> st;
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                topoSortDFS(i, visited, st, adj);
            }
        }

        vector<int> dist(V, 1e9);
        dist[0] = 0; // source distance is 0

        // relaxation
        while (!st.empty())
        {
            int u = st.top();
            st.pop();

            if (dist[u] != 1e9)
            {
                for (auto &edge : adj[u])
                {
                    int v = edge.first;
                    int wt = edge.second;

                    dist[v] = min(dist[v], wt + dist[u]);
                }
            }
        }

        for (int i = 0; i < V; ++i)
        {
            if (dist[i] == 1e9)
                dist[i] = -1;
        }

        return dist;
    }
};

int main()
{
    Solution sol;

    // Example 1
    int V1 = 4, E1 = 2;
    vector<vector<int>> edges1 = {{0, 1, 2}, {0, 2, 1}};
    vector<int> result1 = sol.shortestPath(V1, E1, edges1);

    cout << "Output for Example 1: ";
    for (int x : result1)
        cout << x << " ";
    cout << endl;

    // Example 2
    int V2 = 6, E2 = 7;
    vector<vector<int>> edges2 = {
        {0, 1, 2}, {0, 4, 1}, {4, 5, 4}, {4, 2, 2}, {1, 2, 3}, {2, 3, 6}, {5, 3, 1}};
    vector<int> result2 = sol.shortestPath(V2, E2, edges2);

    cout << "Output for Example 2: ";
    for (int x : result2)
        cout << x << " ";
    cout << endl;

    return 0;
}