#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    struct Node* next;
};

struct Node* insertAtBegining(struct Node* head, int data)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    if(temp!=NULL)
    {
        temp->val= data;
        temp->next = head;
        return temp;
    }
    else
    {
        cout<<"Memory eror";
        return head;
    }
}

struct Node* insertAtEnd(struct Node* head, int data)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    if(temp!=NULL)
    {
        temp->next=NULL;
        temp->val=data;
        struct Node* p = head;
        if(p==NULL)
        {
            return p;
        }
        else
        {
            while(p->next!=NULL )
            {
                p=p->next;
            }
            p->next=temp;
            return head;
        }
        
    
    }
    else{
        cout<<"Memory overflow\n";
        return head;
    }
}

void printLL(struct Node* head)
{
    struct Node* temp = head;
    while (temp)
    {
        cout<<temp->val<<"\t";
        temp=temp->next;
    }
    
}

int sizeOfLL(struct  Node * head)
{
    int size=0;
    struct Node* p = head;
    while(p)
    {
        size++;
    }
    return size;
}


int main()
{
    struct Node * head = NULL;
    head = insertAtBegining(head, 1);
    head = insertAtBegining(head, 2);
    head = insertAtBegining(head, 3);
    head = insertAtBegining(head, 4);
    head = insertAtBegining(head, 5);
    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 12);
    head = insertAtEnd(head, 100);
    cout<<"Linked List: "<<printLL(head);
    cout<<"Size of linked list = "<<sizeOfLL(head)<<endl;

}