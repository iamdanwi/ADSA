#include <iostream>
#include <vector>
using namespace std;

class GraphMatrix
{
public:
    vector<vector<int>> adj;

    GraphMatrix(int n)
    {
        adj = vector<vector<int>>(n, vector<int>(n, 0));
    }

    void addEdge(int u, int v, bool isDirected)
    {
        adj[u][v] = 1;
        if (isDirected)
        {
            adj[v][u] = 1;
        }
    }

    void printMatrix(int n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << adj[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;
    GraphMatrix g(n);
    cout << "Enter edges (u v):" << endl;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v, 0);
    }

    // print adjacency matrix
    cout << "\nAdjacency Matrix:\n";
    g.printMatrix(n);

    return 0;
}
