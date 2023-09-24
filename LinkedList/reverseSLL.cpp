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
    cout<<"\n Linked list is ";
    Node* p = h;
    while(p)
    {
        cout<<" "<<p->data;
        p=p->next;
    }
}

//reversing the linked list in connection ==>iterative approach
Node* reverseSLLIterative(Node* h)
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

void reverseSLLRecursively(Node* prev, Node* cur)
{
    if(cur!=NULL)
    {
        reverseSLLRecursively(cur, cur->next);
        cur->next = prev;
    }
    else
    {
        head = prev;
    }
}

//printing the linked list in reverse manner iterative approach, complexity==> space=O(n) and time = O(2n)
void printReverse(Node* h)
{
    vector<int> arr;
    Node* ptr = h;
    while(h)
    {
        arr.push_back(ptr->data);
        ptr = ptr->next;
    }
    cout<<"\nReversed linked list is ";
    for(int i=arr.size()-1; i>=0; i--)
    {
        cout<<" "<<arr[i];
    }

}

//printing the linked list in the reverse manner, recursive approach, complexity==> time = O(n) ans spcae = O(n)
void printReverseRecursively(Node* g)
{
    if(g!=NULL)
    {
        printReverseRecursively(g->next);
        cout<<" "<<g->data;
    }
}


Node* head = new Node(3);
int main()
{   

    head = push(2, head);
    head = push(4, head);
    Node* ptr= head;
    printList(ptr);
    // cout<<"\nReversed way LL is ";
    // printReverseRecursively(head);

    cout<<"\nNow reversing the linked list ";
    reverseSLLRecursively(NULL, head);
    printList(head);

   // head = reverseSLL(head);
    //cout<<" LL after reverse";
    //printList(head);

    return 0;
}
