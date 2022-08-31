#include<bits/stdc++.h>
using namespace std;

void reverseArray(int arr[], int start, int end)
{
    while(start<end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++; end--;
    }

}

void printArray(int arr[], int size)
{
    cout<<"\nArray is : ";
    for(int i=0; i<size; i++)
    {
        cout<<" "<<arr[i];
    }
}


int main(){
    int t; //number of test cases
    cout<<"Number of test cases : ";
    cin>>t;
    while(t--){
        cout<<"Enter size of the array";
        int length;
        cin>>length;
        int arr[length];
        for(int i=0; i<length; i++)
        {
            cin>>arr[i];
        }
        cout<<"\nBefore the reversing : ";
        printArray(arr, length);
        reverseArray(arr, 0, length-1);
        printArray(arr, length);
    }


    return 0;
}