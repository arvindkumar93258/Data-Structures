#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    Node(int x)
    {
        this->data = x;
        this->next=NULL;
    }
    int data;
    Node* next;
};

Node* push(int x, Node* head)
{
    Node* temp = new Node(x);
    temp->next=head;
    head= temp;
    return head;
}
void printList(Node* h)
{
    Node* p = h;
    while(p)
    {
        cout<<" "<<p->data;
        p=p->next;
    }
}

Node* reverse(Node* h)
{
    if(h==NULL || h->next==NULL)
    {
        return h;
    }
    Node* cur = h;
    Node* prev = NULL;
    Node* nxt=h;
    //1->2->3
    while (nxt!=NULL)
    {
        cur=nxt;
        nxt=nxt->next;
        cur->next=prev;
        prev=cur;
    }
    return cur; 
}

int main()
{   
    Node* head = new Node(3);

    head = push(2, head);
    head = push(4, head);
    Node* ptr= head;
    printList(ptr);
    head = reverse(head);
    cout<<" LL after reverse";
    printList(head);

    return 0;
}