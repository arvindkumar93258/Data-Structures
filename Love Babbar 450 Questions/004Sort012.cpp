#include<bits/stdc++.h>
using namespace std;


void sort012(vector<int>& arr, int N)
{
    /* 0, 1, 2, 1, 2, 0, 0, 2, 1, 1, 0
    low = 0, mid =0, hifh = N-1;
    case : 1 arr[mid] == 0
    { 
        swap(low, mid)
        low++; 
        mid++; 
    }
    case : 2 arr[mid] == 1
    { 
        mid++;
    }
    case : 3 arr[mid] == 2
    {
        swap(high, mid)
        high--
    }
    run while loop until the mid<=high
    */

   int high = N-1;
   int mid = 0;
   int low = 0;

    while(mid<=high)
    {
        if(arr[mid] == 0)
        {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid] == 1)
        {
            mid++;
        }
        else{
            swap(arr[high], arr[mid]);
            high--;
        }
    }
    cout<<"\nNow Array is : ";
    for(int i=0; i<N; i++)
    {
        cout<<" "<<arr[i];
    }
    cout<<endl;

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