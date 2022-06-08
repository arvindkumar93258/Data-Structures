#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <queue>

using namespace std;
class node
{
public:
    int val;
    node *left;
    node *right;

    node(int data)
    {
        this->val = data;
        this->left = NULL;
        this->right = NULL;
    }
};

node *buildTreeFromLevelOrder(node *root)
{
    cout << "Enter data for root : ";
    int data;
    cin >> data;
    root = new node(data);

    queue<node*> q;
    q.push(root);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        cout << "Enter data for left of " << temp->val << ": ";
        int leftData;
        cin >> leftData;
        if (leftData != -1)
        {
            temp->left = new node(leftData);
            q.push(temp->left);
        }

        cout << "Enter data for right of " << temp->val << ": ";
        int rightData;
        cin>>rightData;
        if (rightData != -1)
        {
            temp->right = new node(rightData);
            q.push(temp->right);
        }
    }
    return root;
}

void lavelOrderTraversal(node *root)
{
    queue<node *> q;
    q.push(root);
    // pushing null because we want to change the line
    q.push(NULL);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << " " << temp->val;
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

int main()
{
    node *root = NULL;
    root = buildTreeFromLevelOrder(root);

    lavelOrderTraversal(root);

    return 0;
}