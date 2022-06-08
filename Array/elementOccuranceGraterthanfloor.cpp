#include<bits/stdc++.h>
using namespace std;

void occurance(vector<int>& A)
{
    int size = A.size();
    cout<<"\n"<<size<<endl;
    int limit = floor(size/2);
    cout<<"limit is "<<limit<<endl;

    int count =0;
    for(int i=0; i<size; i++)
    {
        count = 0;
        for(int j=0; j<size; j++)
        {
            if(i!=j && A[i]==A[j])
            {
                count++;
            }
        }
        if(count>limit)
        {
            cout<<"result is : "<<A[i]<<endl;
            //break;
        }
    }

}


int main()
{
    vector<int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(1);
    for(int i=0; i<3; i++)
    {
        cout<<" "<<a[i];
    }

    occurance(a);



    return 0;
}