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

void printlevelnode(Node* root,int level)
{
    if(root==NULL)
    {
        return ;
    }
    if(root->left==NULL && root->right==NULL)
    {
        cout<<root->data<<" ";
        return ;
    }

    if(root->left!=NULL)
    {
        printlevelnode(root->left,level+1);
    }
    if(root->right!=NULL)
    {
        printlevelnode(root->right,level+1);
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

int cont=0;

void levelOrderTraversal(Node *root,string &chk,int k)
{
    if(root==NULL)
        return ;

    queue<Node *>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        Node * present =q.front();
        q.pop();
        if(present!=NULL)
        {
            cout<<present->data<<" ";
            chk+=to_string(present->data);
            if(present->left!=NULL)
                q.push(present->left);
            if(present->right!=NULL)
                q.push(present->right);
        }
        else
        {
            if(!q.empty())
                q.push(NULL);
                cont++;
                cout<<endl;
        }
    }
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

    cout<<endl;

  //  printTree(root,0);

    printlevelnode(root,0);

    cout<<endl;

   string levelordertraversal="";

   levelOrderTraversal(root,levelordertraversal,2);

//    cout<<endl;
//    print(root);
    cout<<endl;

    return 0;
}

/**

1
2 3
4 -1 5 6
-1 8 -1 -1 -1 7
-1 -1 -1 -1

1
2 3
4 5 6 7
-1 -1 -1 -1 -1 -1 -1 -1


100
90 150
80 -1 -1 200
70 -1 -1 -1
60 75
-1 -1 -1 -1

1
2 3
4 5 -1 -1
-1 -1 -1 -1

1
2 3
-1 -1 8 5
-1 -1 -1 -1

0
1 2
3 4 5 6
-1 -1 -1 -1 7 8 -1 -1
-1 -1 -1 -1

1
2 3
4 5 -1 -1
-1 -1 -1 -1
*/

