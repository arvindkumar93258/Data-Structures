// #include <bits/stdc++.h>
// using namespace std;

// struct node
// {
//     int data;
//     struct node *next;

//     node(int x)
//     {
//         data = x;
//         next = NULL;
//     }
// };

// /* Function to print linked list */
// void printList(struct node *node)
// {
//     while (node != NULL)
//     {
//         printf("%d ", node->data);
//         node = node->next;
//     }
//     printf("\n");
// }

// // } Driver Code Ends
// /*
//   Reverse a linked list
//   The input list will have at least one element
//   Return the node which points to the head of the new LinkedList
//   Node is defined as
//     struct node
//     {
//         int data;
//         struct node* next;

//         node(int x){
//             data = x;
//             next = NULL;
//         }

//     }*head;
// */

// class Solution
// {
// public:
//     struct node *reverse(struct node *head, int k)
//     {
//         // Complete this method
//         node *iterator1 = head;
//         node *iterator2 = head;

//         stack<int> st;

//         while (iterator1 != NULL)
//         {

//             int counter = k;

//             node *ptr = iterator2;
//             while (counter != 0 && ptr != NULL)
//             {
//                 st.push(ptr->data);
//                 counter--;
//                 ptr = ptr->next;
//             }
//             iterator1 = ptr;
//             ptr = iterator2;
//             while (!st.empty())
//             {
//                 ptr->data = st.top();
//                 st.pop();
//             }
//             iterator2 = iterator1;
//         }
//         struct node *mtr = head;
//         while (mtr)
//         {
//             cout << mtr->data << " ";
//             mtr = mtr->next;
//         }
//         return head;
//     }
// };

// //{ Driver Code Starts.

// /* Drier program to test above function*/
// int main(void)
// {
//     int t;
//     cin >> t;

//     while (t--)
//     {
//         struct node *head = NULL;
//         struct node *temp = NULL;
//         int n;
//         cin >> n;

//         for (int i = 0; i < n; i++)
//         {
//             int value;
//             cin >> value;
//             if (i == 0)
//             {
//                 head = new node(value);
//                 temp = head;
//             }
//             else
//             {
//                 temp->next = new node(value);
//                 temp = temp->next;
//             }
//         }

//         int k;
//         cin >> k;

//         Solution ob;
//         head = ob.reverse(head, k);
//         printList(head);
//     }

//     return (0);
// }

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

    void reverseKGroup(int k)
    {
        
    }
};

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
