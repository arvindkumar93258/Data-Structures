#include<bits/stdc++.h>
using namespace std;


void max_heapify(vector<int> &arr, int n, int i)
{
    int left = 2*i+1;
    int right = 2*i +2;
    int largest;
    if(left<n && arr[i]<arr[left])
    {
        largest = left;
    }
    else{
        largest = i;
    }
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

void build_MaxHeap(vector<int>& arr, int n)
{
    for(int i=(n/2)-1; i>=0; i--)
    {
        max_heapify(arr, n, i);
    }
}

vector<int> heap_Sort(vector<int> arr)
{
    int n = arr.size();
    build_MaxHeap(arr, n);

    vector<int> tempArr = arr;

    for(int i=0; i<n; i++)
    {
       int temp = arr[i];
       tempArr[i] = tempArr[n-i-1];
       tempArr[n-i-1] = temp;
       max_heapify(tempArr, n-i-1, 0);
    }
    return tempArr;
}

void printHeap(vector<int> arr)
{
    cout<<"\nHeap is : ";
    for(auto itr = arr.begin(); itr!=arr.end(); itr++)
    {
        cout<<*itr<<" ";
    }
    cout<<endl;
}

void insertKey(vector<int> &arr, int key)
{
    arr.push_back(key);
    build_MaxHeap(arr, arr.size());
}

void deleteKey(vector<int> &arr, int key)
{
    int itr=0;
    int n = arr.size();
    for(itr=0; itr!=arr.size(); itr++)
    {
        if(arr[itr]==key)
        {
            break;
        }
    }

    int temp = arr.back();
    arr[itr] = temp;   
    arr.pop_back();

    build_MaxHeap(arr, arr.size());
}


void increaseKey(vector<int> &arr, int key, int newKey)
{
    int i =0; 
    for(i=0; i<arr.size(); i++)
    {
        if(arr[i]==key)
        {
            if(newKey>arr[i])
            {
                arr[i] = newKey;
                build_MaxHeap(arr, arr.size());
            }
            break;
        }
    }
}


int main()
{
    vector<int> heap = {3,1,5,8,9,15,2,10};
    printHeap(heap);
    build_MaxHeap(heap, heap.size());
    printHeap(heap);

    insertKey(heap, 7);
    printHeap(heap);

    deleteKey(heap, 10);
    printHeap(heap);

    increaseKey(heap, 7, 17);
    printHeap(heap);

    increaseKey(heap, 1, 12);

    printHeap(heap);


    return 0;
}