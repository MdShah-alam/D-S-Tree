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

Node *insert_a_node(Node *root,int val)
{
    Node *newNode=new Node(val);
    if(root==NULL)
    {
        root=newNode;
        return root;
    }

    if(val<root->data)
        root->left=insert_a_node(root->left,val);
    else if(val>root->data)
        root->right=insert_a_node(root->right,val);
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

bool search_the_key(Node *root,int key)
{
    if(root==NULL)
        return false;
    if(root->data==key)
        return true;
    else if(root->data>key)
        search_the_key(root->left,key);
    else if(root->data<key)
        search_the_key(root->right,key);
    else
        return false;
}

bool isbinarytree(Node *root)
{
    if(root==NULL)
        return false;
    bool found=true;
    if(root->data<root->left->data)
        return false;
    else if(root->data>root->right->data)
        return false;
    else
    {
       isbinarytree(root->left);
      isbinarytree(root->right);
    }
    return true;
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

Node *deletion_value(Node *root,int val)
{
    if(root==NULL) return NULL;
    if(root->data>val)
        root=deletion_value(root->left,val);
    else if(root->data<val)
        root=deletion_value(root->right,val);
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
            root->right=deletion_value(root->right,temp->data);
        }
        return root;
    }
}

void zigzagtravelsal(Node *root)
{
    stack<Node*>curr;
    stack<Node*>next;
    bool lefttoright=true;
    curr.push(root);

    while(!curr.empty())
    {
        Node *temp=curr.top();
        curr.pop();
        cout<<temp->data<<" ";
        if(lefttoright)
        {
            if(temp->left)
            next.push(temp->left);
            if(temp->right)
            next.push(temp->right);
        }
        else
        {
            if(temp->left)
            next.push(temp->right);
            if(temp->right)
            next.push(temp->left);
        }
        if(curr.empty())
        {
            swap(curr,next);
            lefttoright=!lefttoright;
        }
    }
}

void printleaf(Node *root)
{
    if(root==NULL)
        return ;
    if(root->left == NULL && root->right == NULL)
    {
        cout<<root->data<<"  ";
    }
    printleaf(root->left);
    printleaf(root->right);
}

void printleftNonLeaves(Node *root)
{
    if(root==NULL)
        return ;
    if(root->left!=NULL)
    {
        cout<<root->data<<" ";
        printleftNonLeaves(root->left);
    }
    else if(root->right!=NULL)
    {
        cout<<root->data<<"  ";
        printleftNonLeaves(root->right);
    }
}

void printrightNonLeaves(Node *root)
{
    if(root==NULL)
        return ;
    if(root->right!=NULL)
    {
        cout<<root->data<<" ";
        printleftNonLeaves(root->right);
    }
    else if(root->left!=NULL)
    {
        cout<<root->data<<"  ";
        printleftNonLeaves(root->left);
    }
}

void printboundary(Node *root)
{
    if(root==NULL)
        return ;
    cout<<root->data<<" ";
    printleftNonLeaves(root->left);
    printleaf(root->left);
    printleaf(root->right);
    printrightNonLeaves(root->right);
}

int main()
{
    int n;
    cin>>n;
    Node *root=NULL;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        root=insert_a_node(root,a);
    }
//    int k;
//    cin>>k;
//    root=insert_a_node(root,k);
//
//    string chk="";
//    pre_order(root,chk);
//    cout<<endl<<chk<<endl;

    printboundary(root);
//
//
//    int m;
//    cin>>m;
//    if(search_the_key(root,m))
//        cout<<"exist "<<endl;
//    else
//        cout<<"not exist "<<endl;

    //zigzagtravelsal(root);
//    int q;
//    cin>>q;
//    root=deletion_value(root,q);
//
//    string ch="";
//    pre_order(root,ch);
//    cout<<endl<<ch<<endl;

    return 0;
}
/**

6
15 10 20 8 12 25

16

20
20 10 30 6 15 25 35 3 12 18 22 28 33 40 2 4 11 14 17 19
*/
