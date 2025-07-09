#include <iostream>
#include <vector>
using namespace std;

void printWeightedAdjMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            if (val == 0)
                cout << "INF ";
            else
                cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    int V = 5;
    vector<vector<int>> matrix(V, vector<int>(V, 0));

    // Example edges with weights
    matrix[0][1] = matrix[1][0] = 2;
    matrix[0][4] = matrix[4][0] = 1;
    matrix[1][2] = matrix[2][1] = 3;
    matrix[1][3] = matrix[3][1] = 8;
    matrix[1][4] = matrix[4][1] = 5;
    matrix[2][3] = matrix[3][2] = 7;
    matrix[3][4] = matrix[4][3] = 4;

    printWeightedAdjMatrix(matrix);
    return 0;
}

