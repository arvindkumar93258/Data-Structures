#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        this->next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class List
{
public:
    Node *head;
    Node *last;
    List()
    {
        head = NULL;
        last = NULL;
    }

    void print(Node *head)
    {
        cout << "\nList is ";
        Node *ptr = head;
        while (ptr)
        {
            cout << " " << ptr->data;
            ptr = ptr->next;
        }
    }
    void push_back(int x)
    {
        Node *temp = new Node(x);
        if (this->head == NULL)
        {
            head = temp;
            last = temp;
        }
        else
        {
            last->next = temp;
            last = last->next;
        }
    }
    void push_front(int x)
    {
        Node *temp = new Node(x);
        temp->next = head;
        head = temp;
    }
    void pop_back()
    {
        if (head == NULL)
        {
            cout << "List is empty!!!";
            return;
        }
        if (head->next == NULL)
        {
            Node *temp = head;
            head = NULL;
            last = NULL;
            free(temp);
            return;
        }
        Node *ptr = head;
        while (ptr->next->next != NULL)
        {
            ptr = ptr->next;
        }
        last = ptr;
        Node *temp = ptr->next;
        ptr->next = NULL;
        free(temp);
        return;
    }
    void pop_front()
    {
        if (head == NULL)
        {
            cout << " Lis is empty!";
            return;
        }
        else if (head == last)
        {
            Node *temp = head;
            head = NULL;
            last = NULL;
            free(temp);
            return;
        }
        else
        {
            Node *temp = head;
            head = head->next;
            free(temp);
            return;
        }
    }
    void reverse()
    {
        if (this->head == NULL)
        {
            cout << "List is empty!!!";
            return;
        }
        else if (this->head->next == NULL)
        {
            return;
        }
        Node *prev = NULL;
        Node *cur = this->head;
        last = this->head;
        Node *next = NULL;
        while (cur != NULL)
        {
            cout << "Node " << cur->data;
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        head = prev;
    }
    void reverseKGroup(int k);
};

void List::reverseKGroup(int k)
{
    return;
}
int main()
{

    List list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.push_back(5);

    list.print(list.head);
    list.reverse();
    list.print(list.head);

    return true;
}
