#include<stdio.h>
#include<iostream>
#include<array>
#include<stdlib.h>

using namespace std;
int heapsize = 6;


void max_Heapify(int A[], int i)
{
    int left = 2*i+1;
    int right = 2*i + 2;
    

    int largest ;
    if(left<heapsize && A[i]<A[left])
    {
        largest = left;
    }
    else{
        largest = i;
    }
    if(right<heapsize && A[largest]<A[right])
    {
        largest = right;
    }
    if(largest!=i)
    {
        swap(A[i], A[largest]);
        max_Heapify(A, largest);
    }

}
void build_Heap(int A[])
{
    for(int i=heapsize/2 -1; i>=0; i--)
    {
        max_Heapify(A, i);
    }

    for (int i = heapsize - 1; i > 0; i--) {
        
        // Move current root to end
        swap(A[0], A[i]);
        heapsize-=1;
  
        // call max heapify on the reduced heap
        max_Heapify(A, 0);
    }
}


int main()
{
    int A[] = { 12, 11, 13, 5, 6, 7};
    cout<<"\nBefore sorting : ";
    for(int i=0;i<heapsize; i++)
    {
        cout<<" "<<A[i];
    }

    build_Heap(A);

    heapsize = 6;

    cout<<"\n After sorting : ";
    for(int i=0; i<heapsize; i++)
    {
        cout<<" "<<A[i];
    }


    return 0;
}