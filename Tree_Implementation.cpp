#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node(int val)
    {
        this->val=val;
        this->left=NULL;
        this->right=NULL;
    }
};

void preorder(Node *root)
{
    if(root==NULL) return ;
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(Node *root)
{
    if(root==NULL) return ;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}
void postorder(Node *root)
{
    if(root==NULL) return ;
    postorder(root->left);
    postorder(root->right);
    cout<<root->val<<" ";
}

int main()
{
    int n;
    cin>>n;
    Node *root = new Node(n);
    queue<Node*>q;
    q.push(root);

    while(!q.empty()){
        Node *present = q.front();
        q.pop();
        int x,y;
        cin>>x>>y;
        Node *n1 = NULL , *n2 = NULL;
        if(x!=-1) n1 = new Node(x);
        if(y!=-1) n2 = new Node(y);
        present->left=n1;
        present->right=n2;
        if(n1!=NULL) q.push(n1);
        if(n2!=NULL) q.push(n2);
    }
    cout<<endl<<"Preorder traversal : ";
    preorder(root);
    cout<<endl<<"inorder traversal : ";
    inorder(root);
    cout<<endl<<"Preorder traversal : ";
    postorder(root);
}

/**

4
2 3
5 1 7 6
-1 -1 10 11 -1 5 -1 -1
-1 -1 -1 -1 -1 -1

*/
