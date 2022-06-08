#include <iostream>
#include <stdio.h>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

struct Node *push(struct Node *head, int val)
{
    struct Node *temp = new Node(val);
    if (temp == NULL)
    {
        cout << "Memory erroe";
        return head;
    }
    temp->next = head;
    head = temp;
    return head;
}

void printList(struct Node *head)
{
    struct Node *ptr = head;
    while (ptr)
    {
        cout << " " << ptr->data;
        ptr = ptr->next;
    }
    return;
}

int middleElement(struct Node *head)
{
    // 1st approach
    // find size of LL and then diveide by 2 and then using pointer we can find that middle element

    // 2nd approach
    // using two pointers slow and fast
    struct Node *slow = head;
    struct Node *fast = head;
    while (fast != NULL || fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow->data;
}

int main()
{

    struct Node *head = NULL;
    head = push(head, 1);
    head = push(head, 2);
    head = push(head, 3);
    head = push(head, 4);
    head = push(head, 5);

    cout << "\n Middle element is " << middleElement(head) << endl;

    printList(head);
    return 0;
}