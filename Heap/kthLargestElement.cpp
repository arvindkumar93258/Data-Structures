#include<bits/stdc++.h>
using namespace std;

void max_heapify(vector<int> &arr, int n, int i)
{
    int left = 2*i+1;
    int right = 2*i+2;
    int largest;
    if(left<n && arr[left]>arr[i])
    {
        largest = left;
    }
    else{ largest = i; }
    if(right<n && arr[right]>arr[largest])
    {
        largest = right;
    }
    if(largest!=i)
    {
        int temp = arr[largest];
        arr[largest] = arr[i];
        arr[i] = temp;

        max_heapify(arr, n, largest); 
    }
}

void build_Heap(vector<int> &arr, int n)
{
    for(int i=(n/1)-1; i>=0; i--)
    {
        max_heapify(arr, n, i);
    }
}


//kth largest element 
int kthLargestElement(vector<int>& arr, int k)
{
    int n = arr.size();
    build_Heap(arr, n);
    for(int i=1; i<k; i++)
    {
        int temp = arr[0];
        arr[0] = arr[n-i-1];
        arr[n-i-1] = temp;

        max_heapify(arr, n-i-1, 0);
    }
    return arr[0];
}

void printHeap(vector<int> arr)
{
    cout<<"\nHeap is : ";
    for(int i=0; i<arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }
}



int main()
{


    vector<int> heap = { 1,4,3,2,10, 12, 20, 50, 30};
    build_Heap(heap, heap.size());
    printHeap(heap);

    cout<<"\nKth largest element is : "<<kthLargestElement(heap, 2);


    return 0;
}