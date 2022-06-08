#include<bits/stdc++.h>
using namespace std;

const int N = 1001;

int graphUndir[N][N];
int graphDir[N][N];

void buildGraph(int n, bool direction)
{
    for(int i=0; i<n; i++)
    {
        int m,n;
        cout<<"Enter nodes in which edge is present ";
        cin>>m>>n;
        if(direction==false)
        {
            graphUndir[m][n]=1;
            graphUndir[n][m]=1;
        }
        else{
            graphDir[m][n]=1;
        }
    }
}

// void printGraph(int n, int m,  int *g[][n])
// {
//     for(int i=0; i<n; i++)
//     {
//         for(int j=0; j<n; j++)
//         {
//             cout<<" "<<g[i][j];
//         }
//         cout<<endl;
//     }
// }

int mani()
{
    int n=5;
    //printGraph(n, n, &graphUndir);
    return 0;
}