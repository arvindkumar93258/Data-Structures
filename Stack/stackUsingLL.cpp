#include<iostream>
#include<stdio.h>

using namespace std;

struct Node
{
    int data;
    struct Node* next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
struct Node* top = NULL;


struct Node* push(int x)
{
    struct Node* temp = new Node(x);
    if(temp==NULL)
    {
        cout<<"memory overflow"<<endl;
        return top;
    }
    temp->next = top;
    top = temp;
    cout<<" Pushed "<<x;
    return top;
}

void pop()
{
    if(top==NULL)
    {
        cout<<"Stack underflow"<<endl;
    }
    int t = top->data;
    struct Node* temp = top;
    top=top->next;
    free(temp);
    cout<<" popped "<<t;
}

int topElement()
{
    if(top==NULL)
    {
        return -1;
    }
    return top->data;
}

void printStack()
{
    struct Node* ptr = top;
    while(ptr)
    {
        cout<<" "<<ptr->data;
        ptr= ptr->next;
    }
}

int main()
{
    top = push(1);
    top = push(12);
    top = push(100);
    top = push(200);
   pop();
   pop();
    
    printStack();

    return 0;
}