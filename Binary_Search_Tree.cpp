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

Node *insertBST(Node *root,int val)
{
    Node *newNode=new Node(val);
    if(root==NULL)
    {
        root=newNode;
        return root;
    }

    if(val<root->data)
        root->left=insertBST(root->left,val);
    else if(val>root->data)
        root->right=insertBST(root->right,val);
    return root;
}

void pre_order(Node *root,string &chk)
{
    if(root==NULL) return ;

    pre_order(root->left,chk);
    chk+=(to_string(root->data)+" ");
    pre_order(root->right,chk);
    return ;
}

Node *searchBST(Node *root,int value,string &st)
{
    if(root==NULL) return NULL ;
    if(root->data==value)
    {
        cout<<root->data;
        st+=to_string(root->data);
        return root;
    }
    else if(root->data>value)
    {
        cout<<root->data<<"->";
        st+=to_string(root->data);
        searchBST(root->left,value,st);
    }
    else
    {
        cout<<root->data<<"->";
        st+=to_string(root->data);
        searchBST(root->right,value,st);
    }
}

Node *inordersucc(Node *root)
{
    Node *curr=root;
    while(curr->left!=NULL && curr!=NULL)
    {
       curr=curr->left;
    }
    return curr;
}

Node *treedeletion(Node *root,int value)
{
    if(root->data<value)
        root->right=treedeletion(root->right,value);
    else if(root->data>value)
        root->left=treedeletion(root->left,value);
    else
    {
        if(root->left==NULL)
        {
            Node *temp=root->right;
            delete root;
            return temp;
        }
        else if(root->right==NULL)
        {
            Node *temp=root->left;
            delete root;
            return temp;
        }
        else
        {
            Node *temp=inordersucc(root->right);
            root->data=temp->data;
            root->right=treedeletion(root->right,temp->data);
        }
        return root;
    }
}

int main()
{
    int n;
    cin>>n;
    Node *root=NULL;
    for(int i=0; i<n; i++)
    {
        int a;
        cin>>a;
        root=insertBST(root,a);
    }

    string chk="";
    pre_order(root,chk);
    cout<<endl<<chk<<endl;

    int k;
    cin>>k;
    string st;
    if(searchBST(root,k,st)!=NULL)
        cout<<endl<<"This value is exist "<<endl;
    else
        cout<<endl<<"This value is not exist "<<endl;

    cout<<st<<endl;

    root=treedeletion(root,k);

    string ch="";
    pre_order(root,ch);
    cout<<endl<<ch<<endl;
    return 0;
}
/**
11
11 5 9 43 34 1 2 7 8 6 21

11
10 40 20 8 99 16 15 17 11 14 1

Can We insert duplicate values in BST?

*/
