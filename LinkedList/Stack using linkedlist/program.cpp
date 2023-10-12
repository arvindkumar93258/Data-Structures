#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class Stack
{
public:
    Node *head;
    int length;
    Stack()
    {
        this->head = NULL;
        this->length = 0;
    }
    void push(int data)
    {
        Node *temp = new Node(data);
        if (this->head == NULL)
        {
            this->head = temp;
            this->length += 1;
            return;
        }
        temp->next = this->head;
        this->head = temp;
        this->length += 1;
        return;
    }
    int pop()
    {
        if (this->head == NULL)
        {
            cout << "Stack is empty!!";
            return INT_MIN;
        }
        int result = this->head->data;
        Node *temp = this->head;
        this->head = temp->next;
        free(temp);
        this->length -= 1;
        return result;
    }
    int top()
    {
        if (this->head == NULL)
        {
            cout << "Stack is empty!!";
            return INT_MIN;
        }
        return this->head->data;
    }
    int size()
    {
        return this->length;
    }
    bool isEmpty()
    {
        if (this->head == NULL)
        {
            return true;
        }
        return false;
    }
    void print()
    {
        Node *ptr = this->head;
        cout << "\nStack element: ";
        while (ptr != NULL)
        {
            cout << " " << ptr->data;
            ptr = ptr->next;
        }
    }
};

int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.print();
    s.pop();
    s.print();
    s.push(1);
    s.print();
    cout << "Stack size is : " << s.size();
    return 0;
}
