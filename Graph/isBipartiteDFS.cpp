#include<bits/stdc++.h>
using namespace std;

bool DFS(int start, int visited[], vector<int> adj[])
{
    if(visited[start]==-1)
    {
        visited[start] = 1;
    }
    for(auto child: adj[start])
    {
        if(visited[child]==-1)
        {
            if(!DFS(child, visited, adj)) return false;
        }
        else if(visited[child] == visited[start])
        {
            return false;
        }
    }
    return true;
}


bool isBipartite(int v, vector<int> adj[])
{
    int visited[v];
    for(int i=0; i<v; i++)
    {
        visited[i] =-1;
    }

    for(int i=0; i<v; i++)
    {
        if(visited[i]==-1)
        {
            if(!DFS(i, visited, adj))
            {
                return false;
            }
        }
    }
    return true;

}


int main()
{
    int T;
    cin>>T;
    while(T)
    {
        int v, e;
        cin>>v>>e;
        vector<int> adj[v];
        for(int i=0; i<v; i++)
        {
            int v1, v2;
            cin>>v1>>v2;
            adj[v1].push_back(v2);
            adj[v2].push_back(v1);
        }
        cout<<"\nIs graph bipartite "<<isBipartite(v, adj);
        T--;
    }


    return 0;
}