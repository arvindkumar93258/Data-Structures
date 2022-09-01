#include<bits/stdc++.h>
using namespace std;
long long maxSubArraySum(int arr[], int n)
{

    long long maxSum = INT_MIN;
    long long maxSoFar = 0;
    for(int i=0; i<n; i++)
    {
        maxSoFar +=arr[i];
        if(maxSoFar>maxSum)
        {
            maxSum = maxSoFar;
        }
        if(maxSoFar<0)
        {
            maxSoFar=0;
        }
    }
    return maxSum;
}

void printArray(int arr[], int n)
{
    cout<<"\nArray is : ";
    for(int i=0; i<n; i++)
    {
        cout<<" "<<arr[i];
    }
}

int main()
{

    int t;
    cin>>t; //number of test cases 
    while(t--)
    {
        int n;
        cin>>n; //number of elements in the array 
        int arr[n];
        for(int i=0; i<n; i++)
        {
            int temp;
            cin>>temp;
            arr[i] = temp;
        }
        printArray(arr, n);
        cout<<"\nMaximus sum of continuous sub-array sum : "<<maxSubArraySum(arr, n);
    }


    return 0;
}