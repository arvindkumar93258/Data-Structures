#include <bits/stdc++.h>
using namespace std;

bool BFS(int start, vector<int>& visited, vector<int> adj[])
{
    queue<int> q;

    visited[start] = 0;
    q.push(start);

    while (!q.empty())
    {
        int cur_v = q.front();
        q.pop();

        for (auto child : adj[cur_v])
        {
            if (visited[child] == -1)
            {
                visited[child] = 1 - visited[cur_v];
                q.push(child);
            }
            if (visited[child] == visited[cur_v])
            {
                return false;
            } 
        }
    }
    return true;
}

bool isBipartite(int V, vector<int> adj[])
{
    // Code here
    vector<int> visited(V, -1);

    for (int i = 0; i < V; i++)
    {
        if (visited[i] == -1)
        {
            if (!BFS(i, visited, adj))
                return false;
        }
    }
    return true;
}

int main()
{
    int e = 6;
    int v = 6;
    cin >> v >> e;
    vector<int> adj[v];

    adj[0].push_back(1);
    adj[1].push_back(0);

    adj[1].push_back(2);
    adj[2].push_back(1);

    adj[7].push_back(1);
    adj[1].push_back(7);

    adj[2].push_back(3);
    adj[3].push_back(2);

    adj[4].push_back(7);
    adj[7].push_back(4);

    adj[3].push_back(4);
    adj[4].push_back(3);

    // for(int i=0; i<e; i++)
    // {
    //     int v1, v2;
    //     cin>>v1>>v2;
    //     adj[v1].push_back(v2);
    //     adj[v2].push_back(v1);
    // }

    cout << "\nIs graph bipartite :" << isBipartite(v, adj);

    return 0;
}