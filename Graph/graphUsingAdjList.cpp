#include<iostream>
#include<unordered_map>
#include<string>
#include<list>

using namespace std;

class graph
{
    public:
    unordered_map<int, list<int>> adj;

    void addEdge(int u, int v, bool direction)
    {
        adj[u].push_back(v);
        if(direction==false)
        {
            adj[v].push_back(u);
        }
    }

    void printGraph()
    {
        cout<<"Graph is \n";
        for(auto i: adj)
        {
            cout<<"\n "<<i.first<<" ->";
            for(auto j: i.second)
            {
                cout<<" "<<j;
            }
        }
    }

};



int main()
{
    graph g ;
    int n;
    cout<<"Enter number of nodes : ";
    cin>>n;

    cout<<"\nEnter number of edges : ";
    int m;
    cin>>m;

    for(int i=0; i<m; i++)
    {
        int u, v;
        cin>>u>>v;

        //creating undirected graph
        g.addEdge(u,v,0);
    }
    g.printGraph();

    return 0;
}