#include <iostream>
#include <vector>
using namespace std;

void printWeightedAdjList(const vector<vector<pair<int, int>>>& adj) {
    for (int i = 0; i < adj.size(); ++i) {
        cout << i << ": ";
        for (auto& edge : adj[i]) {
            cout << "(" << edge.first << ", weight=" << edge.second << ") ";
        }
        cout << endl;
    }
}

int main() {
    int V = 5;
    vector<vector<pair<int, int>>> adj(V);

    // Example edges with weights
    adj[0].push_back({1, 2});
    adj[1].push_back({0, 2});

    adj[0].push_back({4, 1});
    adj[4].push_back({0, 1});

    adj[1].push_back({2, 3});
    adj[2].push_back({1, 3});

    adj[1].push_back({3, 8});
    adj[3].push_back({1, 8});

    adj[1].push_back({4, 5});
    adj[4].push_back({1, 5});

    adj[2].push_back({3, 7});
    adj[3].push_back({2, 7});

    adj[3].push_back({4, 4});
    adj[4].push_back({3, 4});

    printWeightedAdjList(adj);
    return 0;
}
