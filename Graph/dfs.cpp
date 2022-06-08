#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int> g[N];
int vis[N];

void dfs(int startV)
{
    if (vis[startV] == true)
    {
        return;
    }
    cout<<" "<<startV;
    vis[startV] = true;
    for (int i : g[startV])
    {
        if (vis[i] == false)
        {
            dfs(i);
        }
    }
}

int main()
{
    for (int i = 0; i < N; i++)
    {
        vis[i] = false;
    }

    int numOfVertex, numOfEdge;
    cin>>numOfVertex>>numOfEdge;

    for(int i=0; i<numOfEdge; i++)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0);

    return 0;
}