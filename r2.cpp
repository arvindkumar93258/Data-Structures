#include<bits/stdc++.h>
using namespace std;

int maxStrength(int N, int k, int normal[], int advanced[])
{
    int result =0;
    for(int i=0; i<N; i++)
    {
        if(i%2==0)
        {
            result+=advanced[i];
        }
        else{
            result += normal[i];
        }
       // result+=max(normal[i], advanced[i]);
    }
    return result;
}



int main()
{

    int k, N;
    cin>>N>>k;

    int normal[N];
    int advanced[N];

    for(int i=0; i<N; i++)
    {
        cin>>normal[i];
    }
    for(int i=0; i<N; i++)
    {
        cin>>advanced[i];
    }

    cout<<maxStrength(N, k, normal, advanced);



    return 0;
}