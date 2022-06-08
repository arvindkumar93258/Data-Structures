#include<iostream>
#include<stdio.h>
#include<stack>

using namespace std;

bool balanced(string str)
{
    int length = str.length();
    if(length<1)
    {
        return true;
    }
    stack<char> s;
    for(int i=0; i<length; i++)
    {
        char c=str[i];
        if(c=='[' || c=='{' || c=='(')
        {
            s.push(c);
        }
        else if(s.empty()==true)
        {
            return false;
        }
        else
        {
            if(s.top()=='[' && c==']')
            {
                s.pop();
            }
            else if(s.top()=='{' && c=='}')
            {
                s.pop();
            }
            else if(s.top()=='(' && c==')')
            {
                s.pop();
            }
            else{
                return false;
            }
        }
    }
    return s.empty();
}

int main()
{
    string str = "({[]})()";
    cout<<balanced(str)<<endl;

    return 0;
}