#include <bits/stdc++.h>
using namespace std;

vector<int> kahnTopoSort(int V, vector<vector<int>> &adj)
{
    vector<int> indegree(V, 0);
    vector<int> topoOrder;

    // Step1: Calculate in-degrees
    for (int u = 0; u < V; u++)
    {
        for (int v : adj[u])
        {
            indegree[v]++; // ✅ FIXED typo here (was indegree[vector]++)
        }
    }

    /*
    Loop through all vertices u
    For each u → v, increment indegree[v] by 1
    Because v has one more edge coming in from u
    After this, indegree[i] tells you how many prerequisites node i has.
    */

    // Step 2: Queue all nodes with in-degree 0
    queue<int> q;
    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    // Nodes with no incoming edges(i.e, indegree 0 can be started fast)
    //  Push all such nodes
    //  These are like independent tasks that can be performed immediately

    // Step 3: Process the queue
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        topoOrder.push_back(node);

        // We did a simple bfs, poped the current node from the queue
        // Add it to the topOrder because it's ready to be scheduled

        for (int neighbour : adj[node])
        {
            indegree[neighbour]--;
            if (indegree[neighbour] == 0)
            {
                q.push(neighbour);
            }
        }
        // For every neighbor of the current node:
        // Reduce its indegree (because we "processed" one of its prerequisites)
        // If that neighbor now has 0 indegree, it's ready → push it to queue
    }

    if (topoOrder.size() != V)
    {
        cout << "Cycle detected! Topological sort not possible. \n";
        return {};
    }

    return topoOrder;
}

int main()
{
    int V = 6;
    vector<vector<int>> adj(V);

    // DAG
    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);

    // 🕒 Start timer
    auto start = chrono::high_resolution_clock::now();

    vector<int> result = kahnTopoSort(V, adj);

    // 🕒 End timer
    auto end = chrono::high_resolution_clock::now();

    if (!result.empty())
    {
        cout << "Topological Order (Kahn's): ";
        for (int node : result)
        {
            cout << node << " ";
        }
        cout << endl;
    }

    // 📏 Print duration
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Time taken by code: " << duration.count() << " microseconds" << endl;

    return 0;
}
