#include <bits/stdc++.h>
using namespace std;

void printGraph(const vector<vector<int>> &adj, int V)
{
    for (int i = 0; i < V; i++)
    {
        cout << i << " ";
        for (int neighbour : adj[i])
        {
            cout << neighbour << " ";
        }
        cout << endl;
    }
}

void dfs(int start, const vector<vector<int>> &adj, int V, vector<bool> &visit)
{

    visit[start] = true;
    cout << start << " ";

    for (int neighbour : adj[start])
    {
        if (!visit[neighbour])
        {
            dfs(neighbour, adj, V, visit);
        }
    }
}

void bfs(int start, const vector<vector<int>> &adj, int V)
{

    vector<bool> visited(V, false);
    queue<int> q;
    visited[start] = true;
    q.push(start);

    while (!q.empty())
    {

        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int neighbour : adj[node])
        {
            if (!visited[neighbour])
            {
                visited[neighbour] = true;
                q.push(neighbour);
            }
        }
    }
}

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
    recStack[start] = false;

    return false;
}

bool isCycle(int V, const vector<vector<int>> &adj)
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

    int V = 5;

    vector<vector<int>> adj(V);
    vector<bool> visit(V, false);

    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[0].push_back(4);

    adj[1].push_back(0);
    adj[1].push_back(2);
    adj[1].push_back(3);

    adj[2].push_back(1);
    adj[2].push_back(0);
    adj[2].push_back(3);

    adj[3].push_back(2);
    adj[3].push_back(1);
    adj[3].push_back(4);

    adj[4].push_back(3);
    adj[4].push_back(2);
    adj[4].push_back(0);

    printGraph(adj, V);
    cout << endl;
    bfs(0, adj, V);
    cout << endl;
    dfs(0, adj, V, visit);
    cout << endl;

    if (isCycle(V, adj))
    {
        cout << "Cycle detected " << endl;
    }
    else
    {
        cout << "No cycle ❌" << endl;
    }

    return 0;
}