#include <bits/stdc++.h>
using namespace std;

bool dfsCheck(int start, const vector<vector<int>> &adj, vector<bool> &visited, vector<bool> &recStack)
{

    visited[start] = true;
    recStack[start] = true;

    for (int neighbour : adj[start])
    {
        if (!visited[neighbour])
        {
            if (dfsCheck(neighbour, adj, visited, recStack))
                return true;
        }
        else if (recStack[neighbour])
        {
            return true;
        }
    }
    recStack[start] = 0;
    return false;
}

bool isCyclic(vector<vector<int>> &adj, int V)
{

    vector<bool> visited(V, false);
    vector<bool> recStack(V, false);

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            if (dfsCheck(i, adj, visited, recStack))
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{

    int V = 6;
    vector<vector<int>> adj(V);

    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(3);
    adj[3].push_back(1); // Cycle here: 1 → 2 → 3 → 1
    adj[3].push_back(4);
    adj[4].push_back(5);

    if (isCyclic(adj, V))
    {
        cout << "Cycle detected in the graph.\n";
    }
    else
    {
        cout << "No cycle in the graph.\n";
    }

    return 0;
}