#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct node* right;
    Node(int val)
    {
        this->data=val;
        this->left=NULL;
        this->right =NULL;
    }
};

int countLeaves(struct Node* root)
{
    if(root)
    {
        return 0;
    }
    else if(root->left && root->right)
    {
        return 1;
    }
    else{
        return countLeaves(root->left) + countLeaves(root->right);
    }
}


int main()
{
    struct Node* root1, root2, root3, root4;
    //tree1 is 
    //         1
    //       /   \
    //      2     3
    //     / \   / \
    //    4   5  6  7
    root1->data=1;
    root1->left =new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    cout<<countLeaves(root1);


    return 0;
}