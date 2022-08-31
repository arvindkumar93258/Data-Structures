#include<bits/stdc++.h>
using namespace std;


int kthSmallest(int arr[], int N, int k)
{
    if(k>N)
    {
        cout<<"\n"<<k<<" is greater than "<<N;
    }
    priority_queue<int, vector<int>, greater<int> > pq;
    for(int i=0; i<N; i++)
    {
        pq.push(arr[i]);
    }

    for(int i=1; i<k; i++)
    {
        pq.pop();
    }
    return pq.top();
}

//for printing the array 
void printArray(int arr[], int N)
{
    cout<<" Array is : ";
    for(int i=0; i<N; i++)
    {
        cout<<" "<<arr[i];
    }
}
int main()
{
    int t; //number of test cases 
    cin>>t;
    while(t--)
    {
        int N; //size of the array
        cin>>N;
        int arr[N];
        for(int i=0; i<N; i++)
        {
            int temp;
            cin>>temp;
            arr[i]= temp;
        }
        int k;  //kth element to find 
        cin>>k;
        printArray(arr, N);
        cout<<"\n"<<k<<"th smallest element is : "<<kthSmallest(arr, N, k);
    }


    return 0;
}