#include <bits/stdc++.h>
using namespace std;

void unionOfSortedArray(vector<int> &arr1, vector<int> &arr2, int n1, int n2)
{
    int s1 = 0, s2 = 0;
    vector<int> result;
    while (s1<n1 && s2<n2)
    {
        if(arr1[s1]==arr2[s2])
        {
            result.push_back(arr1[s1]);
            s1++;
            s2++;
        }
        else if(arr1[s1]>arr2[s2])
        {
            result.push_back(arr2[s2]);
            s2++;
        }
        else{
            result.push_back(arr1[s1]);
            s1++;
        }
    }
    while(s1<n1)
    {
        result.push_back(arr1[s1++]);
    }
    while (s2<n2)
    {
        result.push_back(arr2[s2++]);
    }
    

    cout<<"\nUnion of array is : ";
    for(auto i: result)
    {
        cout<<" "<<i;
    }
    
}

void intersectionOfSortedArray(vector<int> &arr1, vector<int> &arr2, int n1, int n2)
{
    int s1=0, s2=0;
    vector<int> result;
    while(s1<n1 && s2<n2)
    {
        if(arr1[s1]==arr2[s2])
        {
            result.push_back(arr1[s1]);
            s1++;
            s2++;
        }
        else if(arr1[s1]>arr2[s2])
        {
            s2++;
        }
        else{
            s1++;
        }
    }
    cout<<"\nIntersection of array is : ";
    for(auto i: result)
    {
        cout<<" "<<i;
    }
}

void printArray(vector<int> arr1, vector<int> arr2)
{
    cout<<"\nArray 1 is : ";
    for(auto i: arr1)
    {
        cout<<" "<<i;
    }
    cout<<"\nArray 2 is : ";
    for(auto i: arr2)
    {
        cout<<" "<<i;
    }
}

int main()
{

    int t;
    cin >> t; // number of test cases
    while (t--)
    {
        int n1, n2;
        cin>>n1>>n2;
        vector<int> arr1, arr2;
        for(int i=0; i<n1; i++)
        {
            int temp;
            cin>>temp;
            arr1.push_back(temp);

        }
        for(int i=0; i<n2; i++)
        {
            int temp;
            cin>>temp;
            arr2.push_back(temp);
        }
        printArray(arr1, arr2);
        unionOfSortedArray(arr1, arr2, n1, n2);
        intersectionOfSortedArray(arr1, arr2, n1, n2);
    }

    return 0;
}