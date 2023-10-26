#include <stdio.h>
#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

class Graph
{
public:
    unordered_map<int, list<int>> adj;

    void addEdge(int u, int v, bool direction)
    {
        // making edge between u to v
        adj[u].push_back(v);
        // ig graph is undirected then making edge v to u
        if (!direction)
        {
            adj[v].push_back(u);
        }
    }
    void printGraph()
    {
        for (auto i : adj)
        {
            cout << "\n"
                 << i.first << " -> ";
            for (auto j : i.second)
            {
                cout << " -> ";
                cout << j;
            }
        }
    }
};

int main()
{
    Graph g;
    int n;
    cin >> n;
    int numOfEdges;
    cin >> numOfEdges;
    for (int i = 0; i < numOfEdges; i++)
    {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v, 0);
    }
    g.printGraph();

    return 0;
}
