#include <bits/stdc++.h>
using namespace std;

void dfs(int start, vector<vector<int>> &adj, vector<bool> &visited, stack<int> &st)
{
    visited[start] = true;
    for (int neighbour : adj[start])
    {
        if (!visited[neighbour])
        {
            dfs(neighbour, adj, visited, st);
        }
    }
    st.push(start);
}

vector<int> topoSort(int V, vector<vector<int>> &adj)
{

    vector<bool> visited(V, false);
    stack<int> st;

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            dfs(i, adj, visited, st);
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

    // No cycles; valid DAG
    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);

    vector<int> result = topoSort(V, adj);

    cout << "Topological Order: ";
    for (int node : result)
    {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}