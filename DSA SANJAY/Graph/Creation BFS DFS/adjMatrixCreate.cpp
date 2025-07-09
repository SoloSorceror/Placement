#include <iostream>
#include <vector>
using namespace std;

void printAdjMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    int V = 5;
    vector<vector<int>> matrix(V, vector<int>(V, 0));

    // Example edges for an undirected graph
    matrix[0][1] = matrix[1][0] = 1;
    matrix[0][4] = matrix[4][0] = 1;
    matrix[1][2] = matrix[2][1] = 1;
    matrix[1][3] = matrix[3][1] = 1;
    matrix[1][4] = matrix[4][1] = 1;
    matrix[2][3] = matrix[3][2] = 1;
    matrix[3][4] = matrix[4][3] = 1;

    printAdjMatrix(matrix);
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

    vector<vector<int>> adjMatrix(V, vector<int>(V, 0));

    for (int i = 0; i < E; ++i) {
        int u, v;
        cout << "Enter edge " << i+1 << " (u v): ";
        cin >> u >> v;
        adjMatrix[u][v] = 1;
        if (!isDirected) {
            adjMatrix[v][u] = 1;
        }
    }

    cout << "\nAdjacency Matrix:\n";
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

*/