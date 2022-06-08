#include<iostream>
#include<array>


using namespace std;

int arr[1000];
int top =-1;
void push(int x)
{
    if(1000-top>0)
    {
        top++;
        arr[top]=x;
        return;
    }
    cout<<"Overflow"<<endl;
}

int pop()
{
    if(top<0)
    {
        cout<<"underflow"<<endl;
        return -1;
    }
    int t = arr[top];
    arr[top] = -1e7;
    top--;
    return t;
}

int peek()
{
    if(top<0)
    {
        cout<<"underflow";
        return -1;
    }
    return arr[top];
}

void printStack()
{
    for(int i=0; i<top; i++)
    {
        cout<<" "<<arr[i];
    }
}
int main()
{

    push(1);


    push(10);
    push(21);

    push(200);
    push(210);

    cout<<pop();
    push(100);

    printStack();

    return 0;
}