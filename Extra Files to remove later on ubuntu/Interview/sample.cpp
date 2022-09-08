#include<bits/stdc++.h>
using namespace std;


struct Node
{
    int data;
    struct Node* next;
};


void deleteNode(int x, struct Node* head)
{
    // 1->2->3->4->NULL
    //x=3, x=1, x=2, x=4

    if(head->data==x)
    {
        head= head->next;
    }

    struct Node* ptr = head;
    while(ptr->next->data!=x)
    {
        ptr=ptr->next;
    }
    
    struct Node* nxt = ptr->next->next;
    ptr->next = nxt;
}




int manin()
{
    vector<vector<int>> arr = {{1,2,3}, {0,2,1}, {0,0,2}};
    // 1  2  3
    // 0  2  1
    // 0  0  2

    //row =1 col=1

    //output
    // 1  1  3
    // 1  1  1
    // 1  1  1

    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(arr[i][j]==0)
            {
                for(int m=0; m<3; m++)
                {
                    arr[i][m]=1;
                    arr[m][j]=1;
                }
            }
        }
    }

    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            cout<<" "<<arr[i][j];
        }
        cout<<"\n";
    }






    return 0;
}