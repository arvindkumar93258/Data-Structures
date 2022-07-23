#include<bits/stdc++.h>
using namespace std;

#define N 100
vector<int> stack1;
vector<int> stack2;

void push(int x)
{
    try
    {
        stack1.push_back(x);
        if(!stack2.empty() && stack2.back()>x)
        {
            stack2.push_back(x);
        }
        else
        {
            stack2.push_back(stack2.back());
        }
    }
    catch(const std::exception& e)
    {
        cout<<"Error in push operation \n";
    }
    
}

void pop()
{
    cout<<"\nPopped element is "<<stack1.back();
    stack1.pop_back();
    stack2.pop_back();
}


void findMin()
{
    cout<<"\nMinimum element is : "<<stack2.back();
}

void printStack()
{
    cout<<"Stack is :";
    for(auto itr=stack1.begin(); itr!=stack1.end(); itr++)
    {
        cout<<*itr<<" ";
    }
    cout<<endl;
}


int main()
{

    push(1);
    printStack();
     push(21);
    printStack();
     push(42);
    printStack();
     push(50);
    printStack();
     push(100);
    printStack();
     push(151);
    printStack();
    pop();
    printStack();
    pop();
    printStack();


    return 0;
}

