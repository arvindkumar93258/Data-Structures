// Give the head of the linked list and an integer val, rmeove all the nodes of the linked list
// that has Node.val == val, and return the new head

#include <iostream>
using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};
class LinkedList
{
public:
    Node *head;
    Node *length;
    LinkedList()
    {
        this->head = NULL;
        this->length = 0;
    }
    void addAtHead(int val)
    {
        Node *temp = new Node(val);
        if (head == NULL)
        {
            head = temp;
            this->length += 1;
            return;
        }
        temp->next = head;
        head = temp;
        this->length += 1;
    }
    void addAtTail(int val)
    {
        Node *ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        Node *temp = new Node(val);
        ptr->next = temp;
        this->length += 1;
    }
    void addAtIndex(int val, int position)
    {
        if (position < 0)
        {
            cout << "Not valid position!";
            return;
        }
        Node *ptr = head;
        if (position == 0)
        {
            Node *temp = new Node(val);
            temp->next = head;
            head = temp;
            this->length += 1;
        }
        while (ptr != NULL && position > 1)
        {
            position--;
            ptr = ptr->next;
        }
        Node *temp = new Node(val);
        temp->next = ptr->next;
        ptr->next = temp;
        this->length += 1;

        return;
    }
    void print()
    {
        Node *ptr = head;
        while (ptr != NULL)
        {
            cout << " " << ptr->val;
            ptr = ptr->next;
        }
    }
    //Solution
    Node* deleteAllOccurance(int val){
        Node* tempHead = this->head;

        Node* ptr = head;
        Node* prev = NULL;
        Node* cur = head;
        // 1 and val =1
        // 
    }
};

int main()
{
    LinkedList ll;
    //6,5,2,3,1,3
    ll.addAtHead(1);
    ll.addAtHead(2);
    ll.addAtTail(3);
    ll.addAtIndex(3, 1);
    ll.addAtHead(5);
    ll.addAtHead(6);
    ll.print();

    return 0;
}
