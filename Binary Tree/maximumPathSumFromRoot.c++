#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
    Node* newNode(int val)
    {

    }

    Node* buildTree(Node* root)
    {
        cout<<"\nEnter the root elememt ";
        int tempVar;
        cin>>tempVar;
        queue<int> q;
        q.push(tempVar);
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            // root = 
        }
    }

    public void printTree(Node* root)
    {
        Node* temp = root;
        queue<Node*> q;
        q.push(temp);
        while(!q.empty())
        {
            temp = q.front();
            q.pop();
            cout<<" "<<temp->data;
            if(!temp->left) { q.push(temp->left); }
            if(!temp->right) { q.push(temp->right); }
        }
    }

};

int maxPathSumFromRoot(Node* root){
    if(root==NULL) return 0;
    if(root->right==NULL && root->left==NULL)
    {
        return root->data;
    }
    return max(maxPathSumFromRoot(root->left), maxPathSumFromRoot(root->right));
}


int main()
{

    Node root = new Node(1);
    // root = Node(1);

    printTree(root);

    return 0;
}

