#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
};

Node* push();

int middleElement(Node* head)
{
    //if list is null or having one element
    if(head==NULL)
    {
        return -1;
    }
    if(head->next==NULL)
    {
        return head->data;
    }

    //1->2->3->NULL
    //1, 2, 3, 4
    
    int size=0;
    Node* slow = head;
    Node* fast = head;

    while(fast!=NULL && fast->next!=NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow->data;

    // while(ptr!=NULL)
    // {
    //     size++;
    //     ptr = ptr->next;
    // }
    // //size =3, 4
    // int middle = (size+1)/2;//1, 3
}




int main()
{




    return 0;
}



//2 tbale employee(id, name, deptid) and dept(deptid, dname)
//selct e.name, d.dname from employee as e, dept as d where d.deptid=e.deptid
//select e.name, d.dname from employee as e, dept as d e.deptid left join d.deptid