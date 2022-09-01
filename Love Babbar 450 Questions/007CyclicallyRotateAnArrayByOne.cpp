#include<bits/stdc++.h>
using namespace std;


void cyclicallyRotateArray(int arr[], int n)
{
    int lastElement = arr[n-1];
    for(int i=n-1; i>0; i--)
    {
        arr[i] = arr[i-1];
    }
    arr[0] = lastElement;

    cout<<"\nNow Array is : ";
    for(int i=0; i<n; i++)
    {
        cout<<" "<<arr[i];
    }
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
        cin>>n; // number of elements in array 
        int arr[n];
        for(int i=0; i<n; i++)
        {
            int temp;
            cin>>temp;
            arr[i] = temp;
        }
        printArray(arr, n);
        cyclicallyRotateArray(arr, n);
    }


    return 0;
}