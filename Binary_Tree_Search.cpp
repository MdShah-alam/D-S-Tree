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

void inorderprint(Node *root)
{
    if(root==NULL) return ;

    inorderprint(root->left);
    cout<<root->data<<" ";
    inorderprint(root->right);
    return ;
}

void preorderprint(Node *root)
{
    if(root==NULL) return ;

     cout<<root->data<<" ";
    inorderprint(root->left);
    inorderprint(root->right);
    return ;
}

void postorderprint(Node *root)
{
    if(root==NULL) return ;

    inorderprint(root->left);
    inorderprint(root->right);
    cout<<root->data<<" ";
    return ;
}

void levelOrderTraversal(Node *root)
{
    if(root==NULL)
        return ;

    int c=0;
    queue<Node *>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        Node * present =q.front();
        q.pop();
        if(present!=NULL)
        {
            if(c==2)
                cout<<present->data<<" ";
            if(present->left!=NULL)
                q.push(present->left);
            if(present->right!=NULL)
                q.push(present->right);
        }
        else
        {
            c++;
            if(!q.empty())
                q.push(NULL);
        }
    }
}

void pre_order(Node *root,string &chk)
{
    if(root==NULL) return ;
    chk+=to_string(root->data);
    pre_order(root->left,chk);
    pre_order(root->right,chk);
    return ;
}

int main()
{
    int a;
    cin>>a;
    Node *root=new Node(a);
    queue<Node*>q;
    q.push(root);

    while(!q.empty())
    {
        Node *present=q.front();
        q.pop();
        int x,y;
        cin>>x>>y;
        Node *a=NULL;
        Node *b=NULL;
        if(x>-1) a=new Node(x);
        if(y>-1) b=new Node(y);
        present->left=a;
        present->right=b;
        if(a!=NULL)
            q.push(a);
        if(b!=NULL)
            q.push(b);
    }

    cout<<endl<<"in_order_print"<<endl;
    inorderprint(root);
    cout<<endl;

    cout<<"pre_order_print"<<endl;
    preorderprint(root);
    cout<<endl;

    cout<<"post_order_print"<<endl;
    postorderprint(root);
    cout<<endl;

    levelOrderTraversal(root);
    cout<<endl;

    string chk="";
    pre_order(root,chk);
    cout<<chk<<endl;

    return 0;
}
/**
1
2 3
4 5 6 8
-1 -1 -1 -1 -1 -1 -1 -1

*/
