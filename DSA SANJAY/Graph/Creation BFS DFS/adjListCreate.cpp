//  Unweighted Graph Representation
//  Adjacency List (Unweighted)

// Code Explanation
// We'll use a vector of vectors: vector<vector<int>> adj;
// For each edge, we add the connection in the list.

#include<iostream>
#include<vector>
using namespace std;


void printAdjList(const vector<vector<int>>& adj){
    for(int i =0; i<adj.size(); ++i){
        cout<<i<<" ";
        for(int neighbour:adj[i]){
            cout<<neighbour<<" ";
        }
        cout<<endl;
    }
}

int main(){
    
    int V =5;
    vector<vector<int>> adj(V);

    adj[0].push_back(1);
    adj[1].push_back(0);

    adj[0].push_back(4);
    adj[4].push_back(0);

    adj[1].push_back(2);
    adj[2].push_back(1);

    adj[1].push_back(3);
    adj[3].push_back(1);

    adj[1].push_back(4);
    adj[4].push_back(1);

    adj[2].push_back(3);
    adj[3].push_back(2);

    adj[3].push_back(4);
    adj[4].push_back(3);

    printAdjList(adj);
    return 0;
}


/*
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int V, E;
    bool isDirected;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;
    cout << "Is the graph directed? (1 for Yes, 0 for No): ";
    cin >> isDirected;

    vector<vector<int>> adjList(V);

    for (int i = 0; i < E; ++i) {
        int u, v;
        cout << "Enter edge " << i+1 << " (u v): ";
        cin >> u >> v;
        adjList[u].push_back(v);
        if (!isDirected) {
            adjList[v].push_back(u);
        }
    }

    cout << "\nAdjacency List:\n";
    for (int i = 0; i < V; ++i) {
        cout << i << ": ";
        for (int neighbor : adjList[i]) {
            cout << neighbor << " ";
        }
        cout << endl;
    }
    return 0;
}
*/