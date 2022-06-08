// Online C++ compiler to run C++ program online
#include<bits/stdc++.h>
using namespace std;

void printarray(int a[])
{
    int len=sizeof(a);
    for(int i=0;i<len;i++)
    {
        cout<<a[i]<<" ";
        
    }
}

int reversearray(int a[])
{
    int s,e;
    s=0;
    e=sizeof(a);
    while(s<e)
    {
        (a[s]^=a[e]), (a[e]^=a[s]), (a[s]^=a[e]);
        s++;
        e--;
    }
    printarray(a);
}

int main() {
    // Write C++ code here
    std::cout << "Hello world!";
    
    int arr={1,2,3,4,5,6,7};
    cout<<"Array is :"<<printarray(&arr)<<endl;
    cout<<"Reversed array is :"<<(reversearray(&arr)<<endl;
    

    return 0;
}