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
int size=0;


struct Node* push(int x) //time complexity = O(1)
{
    struct Node* temp = new Node(x);
    if(temp==NULL)
    {
        cout<<"memory overflow"<<endl;
        return top;
    }
    temp->next = top;
    top = temp;
    cout<<"Pushed "<<x<<endl;
    size++;
    return top;
}

void pop() //time complexity = O(1)
{
    if(top==NULL)
    {
        cout<<"Stack underflow"<<endl;
    }
    int t = top->data;
    struct Node* temp = top;
    top=top->next;
    free(temp);
    size--;
    cout<<"Popped "<<t<<endl;
}

int topElement()
{
    if(top==NULL)
    {
        return -1;
    }
    return top->data;
}

void printStack() //time complexity = O(n)
{
    struct Node* ptr = top;
    cout<<"\nStack : ";
    while(ptr)
    {
        cout<<" "<<ptr->data;
        ptr= ptr->next;
    }
    cout<<endl;
}

int main()
{
    printStack();
    cout<<"\nSize of stack is : "<<size<<endl;
    top = push(1);
    cout<<"\nSize of stack is : "<<size<<endl;
    printStack();
    top = push(12);
    cout<<"\nSize of stack is : "<<size<<endl;
    printStack();
    top = push(100);
    printStack();
    top = push(200);
    cout<<"\nSize of stack is : "<<size<<endl;
    printStack();
   pop();
   printStack();
   pop();
    cout<<"\nSize of stack is : "<<size<<endl;
    
    printStack();
    cout<<"\nSize of stack is : "<<size<<endl;

    return 0;
}