#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data=data;
        left=NULL;
        right=NULL;
    }
};

Node *insert_node(Node *root,int val)
{
    Node *newNode=new Node(val);
    if(root==NULL)
    {
        root=newNode;
        return root;
    }
    if(root->data>val)
        root->left=insert_node(root->left,val);
    else
        root->right=insert_node(root->right,val);
    return root;
}

void print(Node *root)
{
    if(root==NULL)
        return ;
    cout<<root->data<<" ";
    print(root->left);
    print(root->right);
}

void swap(Node *curr)
{
    if(curr==NULL)
        return ;
    swap(curr->left);
    swap(curr->right);

    Node *temp;
    temp=curr->left;
    curr->left=curr->right;
    curr->right=temp;
}

Node *invert_tree(Node *root)
{
    swap(root);
    return root;
}

int main()
{
    Node *root=NULL;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        root=insert_node(root,a);
    }
    cout<<endl<<"Before invert tree : "<<endl;
    print(root);
    cout<<endl;
    cout<<endl<<"After invert tree : "<<endl;
    root=invert_tree(root);
    print(root);
    cout<<endl;
    return 0;
}

/**
7
4 2 7 1 3 6 9

*/
