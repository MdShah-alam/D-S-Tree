#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        this->data=val;
        this->left=NULL;
        this->right=NULL;
    }
};

void spaceprint(int level)
{
    for(int i=0; i<level; i++)
    {
        cout<<"    ";
    }
}

void printTree(Node* root,int level)
{
    if(root==NULL)
    {
        return ;
    }
    if(root->left==NULL && root->right==NULL)
    {
        cout<<root->data<<endl;
        return ;
    }
    else
    {
        cout<<endl;
        spaceprint(level);
        cout<<"Root: "<<root->data<<endl;
    }
    if(root->left!=NULL)
    {
        spaceprint(level);
        cout<<"Left : ";
        printTree(root->left,level+1);
    }
    if(root->right!=NULL)
    {
        spaceprint(level);
        cout<<"Right : ";
        printTree(root->right,level+1);
    }
}

void print(Node *root)
{
    if(root==NULL) return ;

    print(root->left);
    cout<<root->data<<" ";
    print(root->right);
}

int main()
{
    int a;
    cin>>a;
    Node *root=new Node(a);

    queue<Node *>q;
    q.push(root);

    while(!q.empty())
    {
        Node *present=q.front();
        q.pop();

        int x,y;
        cin>>x>>y;
        Node *n1=NULL;
        Node *n2=NULL;

        if(x!=-1) n1=new Node(x);
        if(y!=-1) n2=new Node(y);

        present->left=n1;
        present->right=n2;

        if(n1!=NULL) q.push(n1);
        if(n2!=NULL) q.push(n2);
    }

    printTree(root,0);

    cout<<endl;
    print(root);
    cout<<endl;

    return 0;
}

/**

1
2 3
4 -1 5 6
-1 8 -1 -1 -1 7
-1 -1 -1 -1

*/
