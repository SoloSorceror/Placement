#include <bits/stdc++.h>
using namespace std;

// Modified DFS with cycle detection
bool dfs(int node, vector<vector<int>> &adj, vector<bool> &visited, vector<bool> &recStack, stack<int> &st)
{
    visited[node] = true;
    recStack[node] = true;

    for (int neighbour : adj[node])
    {
        if (!visited[neighbour])
        {
            if (dfs(neighbour, adj, visited, recStack, st))
                return true; // cycle detected in recursion
        }
        else if (recStack[neighbour])
        {
            return true; // cycle detected via back edge
        }
    }

    recStack[node] = false; // remove from recursion stack
    st.push(node);          // add to result after processing all children
    return false;
}

vector<int> topoSort(int V, vector<vector<int>> &adj)
{
    vector<bool> visited(V, false);
    vector<bool> recStack(V, false);
    stack<int> st;

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            if (dfs(i, adj, visited, recStack, st))
            {
                cout << "Cycle detected! Topological sort not possible." << endl;
                return {};
            }
        }
    }

    vector<int> topoOrder;
    while (!st.empty())
    {
        topoOrder.push_back(st.top());
        st.pop();
    }
    return topoOrder;
}

int main()
{
    int V = 6;
    vector<vector<int>> adj(V);

    // Test graph with a cycle
    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);
    adj[1].push_back(2); // 🔁 This creates a cycle: 1 → 2 → 3 → 1

    vector<int> result = topoSort(V, adj);

    if (!result.empty())
    {
        cout << "Topological Order: ";
        for (int node : result)
        {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}
