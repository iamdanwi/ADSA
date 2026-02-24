//
// Created by Dainwi on 17/02/26.
//
#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

class graphAdjList {
    public:
        unordered_map<int, list<int> > adjList;

        void addEdge(int u, int v, bool directed=true) {
            adjList[u].push_back(v);
            if (directed) adjList[v].push_back(u);
        }

        void printAdjList() const {
            for (auto & it : adjList) {
                cout << it.first << " -> ";
                for (const int & jt : it.second) {
                    cout << jt << " ";
                }
                cout << endl;
            }
        }
};

int main() {
    graphAdjList graph;
    int u, v;
    for (int i = 0; i < 5; i++) {
        cin >> u >> v;
        graph.addEdge(u, v);
    }
    graph.printAdjList();

    return 0;
}