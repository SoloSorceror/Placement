bool dfs(int node, vector<vector<int>> &adj, vector<bool> &visited, vector<bool> &recStack)
{
    visited[node] = true;
    recStack[node] = true;

    for (int neighbor : adj[node])
    {
        if (!visited[neighbor])
        {
            if (dfs(neighbor, adj, visited, recStack))
                return true;
        }
        else if (recStack[neighbor])
        {
            // If neighbor is in the recursion stack → cycle detected
            return true;
        }
    }

    recStack[node] = false; // Backtrack
    return false;
}

bool isCyclic(int V, vector<vector<int>> &adj)
{
    vector<bool> visited(V, false), recStack(V, false);

    for (int i = 0; i < V; ++i)
    {
        if (!visited[i])
        {
            if (dfs(i, adj, visited, recStack))
                return true;
        }
    }

    return false;
}
