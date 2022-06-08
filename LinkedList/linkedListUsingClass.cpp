#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int val;
    Node* next;

    Node()
    {
        val = INT_MIN;
        next = NULL;
    }
    Node(int data)
    {
        this->val= data;
        this->next=NULL;
    }

    Node* insertAtFirst(int data, Node* head)
    {
        Node* temp = new Node(data);

    }

    

}





int main()
{

    Node* head = new Node();

    return 0;
}