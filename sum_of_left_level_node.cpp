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
        left=NULL;
        right=NULL;
    }
};
int sum=0;
int printlevelnode(Node *root)
{
    if(root==NULL)
    {
        return 0;
    }
    if(root->left==NULL && root->right==NULL)
    {
        sum+=root->val;
        return sum;
    }

    if(root->left!=NULL)
    {
        printlevelnode(root->left);
    }
    if(root->right!=NULL)
    {
        printlevelnode(root->right);
    }
}

void printTree(Node *root)
{
    if(root==NULL)
        return ;

    queue<Node *>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        Node *present=q.front();
        q.pop();
        if(present!=NULL)
        {
            cout<<present->val<<"  ";
            if(present->left!=NULL)
                q.push(present->left);
            if(present->right!=NULL)
                q.push(present->right);
        }
        else
        {
            if(!q.empty())
                q.push(NULL);
        }
    }
}
bool check_leaf(Node *root)
{
    if(root->left==NULL && root->right==NULL)
        return true;
    else
        return false;
}
int sm=0;
void get_sum(Node *root)
{
    if(root==NULL)
        return ;
    if(root->left!=NULL)
    {
        if(check_leaf(root->left)) sm+=root->left->val;
        else get_sum(root->left);
    }
    if(root->right!=NULL)
    {
        get_sum(root->right);
    }
}
int sumOfLeftLeaves(Node* root)
{
    get_sum(root);
    return sm;
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
        Node *n1=NULL;
        Node *n2=NULL;

        if(x!=-1)
            n1=new Node(x);
        if(y!=-1)
            n2=new Node(y);
        present->left=n1;
        present->right=n2;

        if(n1!=NULL) q.push(n1);
        if(n2!=NULL) q.push(n2);
    }

    int k= printlevelnode(root);
    cout<<k;

    int h=sumOfLeftLeaves(root);
    cout<<endl<<h;

    cout<<endl<<endl;
    return 0;
}

/**

1
2 3
4 5 6 7
-1 -1 -1 -1 -1 -1 -1 -1

*/
