#include<bits/std++.h>
using namespace std;


void sort012(vector<int>& arr, int N)
{
    // 0, 1, 2, 1, 2, 0, 0, 2, 1, 1, 0
    





}

void printArray(vector<int> arr, int N)
{
    cout<<"\nArray is : ";
    for(int i=0; i<N; i++)
    {
        cout<<" "<<arr[i];
    }
    cout<<endl;
}

int main()
{
    int t;
    cin>>t; //for number of test cases 
    while(t--)
    {
        int N; //number of inputs 
        cin>>N;
        vector<int> arr;
        for(int i=0; i<N; i++)
        {
            int temp;
            cin>>temp;
            arr.push_back(temp);
        }
        printArray(arr, N);
        sort012(arr, N);
    }
    return 0;
}