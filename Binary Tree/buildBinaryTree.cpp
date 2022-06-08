#include <bits/stdc++.h>
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

node *buildTree(node *root)
{
    cout << "Enter the data : ";
    int data;
    cin >> data;
    root = new node(data);

    if (data == -1)
    {
        return NULL;
    }

    cout << "\n Enter data to insert in the left of " << data << " : ";
    root->left = buildTree(root->left);
    cout << "\nEnter data to insert in the right " << data << " : ";
    root->right = buildTree(root->right);

    return root;
}

// inorder traversal of the tree
void inorderTraversal(node *root)
{
    node* temp=root;
    if (temp == NULL)
    {
        return;
    }
    inorderTraversal(temp->left);
    cout << " " << temp->val << " ";
    inorderTraversal(temp->right);
}

// pre-order traversal of the tree
void preorderTraversal(node *root)
{
    node* temp=root;
    if (temp)
        return;
    cout << " " << temp->val << " ";
    preorderTraversal(temp->left);
    preorderTraversal(temp->right);
}

// post order traversal of the tree
void postorderTraversal(node *root)
{
    node* temp=root;
    if (temp)
        return;
    postorderTraversal(temp->left);
    postorderTraversal(temp->right);
    cout << " " << temp->val << " ";
}

// lever order traversal
void leverorderTraversal(node *root)
{
    cout << "\nLevel order traversal is : ";
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (q.empty()==false)
    {
        node *temp = q.front();
        q.pop();
     
        if (temp == NULL)
        {
            cout<<endl;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->val << " ";
            if (temp->left != NULL)
            {
                q.push(temp->left);
            }
            if (temp->right != NULL)
            {
                q.push(temp->right);
            }
        }
    }
}

void buildFromLevelOrder(node* &root)
{
    cout<<"Enter data for root : ";
    int data;
    cin>>data;
    root= new node(data);


    queue<node*> q;
    q.push(root);

    while (!q.empty())
    {
        node* temp = q.front();
        q.pop();

        cout<<"Enter data for left node of "<<temp->val;
        int leftdData;
        cin>>leftdData;
        if(leftdData!=-1)
        {
            temp->left= new node(leftdData);
            q.push(temp->left);
        }

        cout<<"Enter data for right node of "<<temp->val;
        int rightData;
        cin>>rightData;
        if(rightData!=-1)
        {
            temp->right= new node(rightData);
            q.push(temp->right);
        }        
    }
    
}






int main()
{
    // creating root node
    node *root = NULL;

    //root = buildTree(root);
    //node* tptr=root;
    buildFromLevelOrder(root);
    // lever order traversal of the tree
    leverorderTraversal(root);
    // printing inoreder traversal of the tree
    //cout << "Inorder Traversal is : ";
    //inorderTraversal(tptr);
    //cout << "\nPreorder Traversal is : ";
    //preorderTraversal(tptr);
    //cout << "\nPostorder traversal is : ";
    //postorderTraversal(tptr);

    return 0;
}