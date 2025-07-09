#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:

    bool dfs(int node, int parent, vector<vector<int>> &adj, vector<bool> &visited ){

        visited[node] = true;
        for(int neighbour: adj[node]){
            if(!visited[neighbour]){
               if (dfs(neighbour,node,adj, visited)){
                    return true;
            }
            }else if(neighbour!=parent){
                    return true;
            }
        }
        return false;
    }

    bool isCycle(int V, vector<vector<int>> &adj){
        vector<bool> visited(V,false);

        for(int i =0; i<V; i++){
            if(!visited[i]){
                if(dfs(i,-1,adj,visited)){
                    return true;
                }
            }
        }
        return false;

    }


};



int main() {
    int V = 4; // Number of vertices
    vector<vector<int>> adj(V);

    // Edges (undirected graph)
    adj[0].push_back(1);
    adj[1].push_back(0);

    adj[1].push_back(2);
    adj[2].push_back(1);

    adj[1].push_back(3);
    adj[3].push_back(1);

    adj[2].push_back(3);
    adj[3].push_back(2);

    Solution s;
    if (s.isCycle(V, adj)) {
        cout << "Cycle detected ✅" << endl;
    } else {
        cout << "No cycle ❌" << endl;
    }

    return 0;
}