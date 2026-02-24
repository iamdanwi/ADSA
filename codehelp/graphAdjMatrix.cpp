//
// Created by Dainwi on 17/02/26.
//
#include <iostream>
#include <vector>
using namespace std;

class GraphAdjMatrix {
    public:
    vector<vector<int>> adjMatrix;

    explicit GraphAdjMatrix(const int n) {
        adjMatrix = vector<vector<int>>(n, vector<int>(n, 0));
    }

    void addEdge(const int u, const int v, const bool isDirected = false) {
        adjMatrix[u][v] = 1;
        if (isDirected) {
            adjMatrix[v][u] = 1;
        }
    }

    void printAdjMatrix() const {
        for (const auto & i : adjMatrix) {
            for (const int j : i) {
                cout << j << " ";
            }
            cout << endl;
        }
    }
};
int main() {
    int n, m;
    cin >> n >> m;
    GraphAdjMatrix graphAdjMatrix(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graphAdjMatrix.addEdge(u, v);
    }

    graphAdjMatrix.printAdjMatrix();
    return 0;
}