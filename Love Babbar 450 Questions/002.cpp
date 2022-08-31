#include<bits/stdc++.h>
using namespace std;

pair<int, int> minAndMaxFind(int arr[], int size)
{
    int min = arr[0], max = arr[0];
    if(length<=1)
    {
        cout<<"Array has only "<<size<<" elements ";
        return;
    }
    for(int i=1; i<size; i++)
    {
        if(arr[i]>max)
        {
            max = arr[i];
        }
        else if(arr[i]<min)
        {
            min = arr[i];
        }
    }
    pair<int, int> result;
    result.first = min;
    result.second = max;
    return result;
}

int main()
{

    int t; //number of test cases
    cin>>t;
    while(t--)
    {
        int length; //length of array;
        cout<<"Enter the length of the array : ";
        cin>>length;
        int arr[length];
        cout<<"Enter the elements in the array : ";
        for(int i=0; i<length; i++)
        {
            cin>>arr[i];
        }
        cout<<"\nArray is : ";
        for(int i=0; i<length; i++)
        {
            cout<<" "<<arr[i];
        }
        pair<int, int> result = minAndMaxFind(arr, length);
        cout<<"\nMin : "<<result.first<<" max : "<<result.second;
    }



    return 0;
}