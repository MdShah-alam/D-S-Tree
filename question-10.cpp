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

void print(Node *root)
{
    if(root==NULL)
        return ;
    cout<<root->data<<" ";
    print(root->left);
    print(root->right);
}

Node *mirror(Node *root)
{
    if(root==NULL)
        return NULL;
    mirror(root->left);
    mirror(root->right);

    Node *temp;
    temp=root->left;
    root->left=root->right;
    root->right=temp;
    return root;
}

int second_minimum(Node *root)
{
    if(root==NULL)
        return -1;
    if(root->left==NULL && root->right==NULL)
        return -1;

    int a=root->left->data;
    int b=root->right->data;
    if(root->left->data==root->data)
        a=second_minimum(root->left);
    if(root->left->data==root->data)
        b=second_minimum(root->right);
    if(a!=-1 && b!=-1)
        return min(a,b);
     if(a!=-1)
        return a;
     else
        return b;
}

int main()
{
    int n;
    cin>>n;
    Node *root=new Node(n);

    queue<Node*>q;
    q.push(root);

    while(!q.empty())
    {
        Node *present=q.front();
        q.pop();
        int x,y;
        cin>>x>>y;
        Node *n1=NULL;
        Node *n2=NULL;

        if(x!=-1)
            n1=new Node(x);
        if(y!=-1)
            n2=new Node(y);

        present->left=n1;
        present->right=n2;

        if(n1!=NULL)
            q.push(n1);
        if(n2!=NULL)
            q.push(n2);
    }

    print(root);
    cout<<endl;

    cout<<second_minimum(root);
    cout<<endl;

    //int k=get_second_max(root);
}

/**

5
6 3
-1 4 -1 1
-1 -1 -1 -1


2
2 5
-1 -1 5 7
-1 -1 -1 -1

*/
