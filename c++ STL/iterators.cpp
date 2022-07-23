#include<iostream>
#include<iterator>
#include<vector>

using namespace std;



int main()
{

    vector<int> arr = {1,2,3,4,5};

    //declaration of the iterator
    vector<int>::iterator itr;

    for (itr = arr.begin(); itr < arr.end(); ++itr)
    {
        cout<<"  "<<*itr;
    }

    
    

    return 0;
}