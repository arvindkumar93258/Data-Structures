#include<bits/stdc++.h>
using namespace std;


int main()
{
    string str = "The first second was alright but the second second was tough";

    // the -> 2
    //second -> 3
    int length = str.length(); //length = 40


    map<string, int> m;
    
    int ptr = 0;
    string s;
    while(ptr<length)
    {
        s = "";
        while(str[ptr]!=' ')//the
        {
            s.push_back(str[ptr]);
            ptr++;
        } // s = "The"
        ptr++;
        m[s]+=1;
    }

    // The - 1+1
    //first - 1
    //second - 1+1+1
    //was - 1+1
    //alright - 1
    // but - 1
    //tough - 1


    //now finding maximum count;
    int max =0;
    string result = "";
    for(auto it = m.begin(); it!=m.end(); it++)
    {
        if(it->second > max)
        {
            max = it->second;
            result = it->first;
        }

    }

    cout<<"\nMost frequent word is "<<result<<endl;



    return 0;
}