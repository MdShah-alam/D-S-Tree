#include<bits/stdc++.h>
using namespace std;

class NodeTree
{
public:
    int data;
    NodeTree *leftchild;
    NodeTree *rightchild;

    NodeTree(int val)
    {
        data=val;
        leftchild=NULL;
        rightchild=NULL;
    }
};

void spaceprint(int level)
{
    for(int i=0; i<level; i++)
    {
        cout<<"    ";
    }
}

void printTree(NodeTree* root,int level)
{
    if(root==NULL)
    {
        return ;
    }
    if(root->leftchild==NULL && root->rightchild==NULL)
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
    if(root->leftchild!=NULL)
    {
        spaceprint(level);
        cout<<"Left : ";
        printTree(root->leftchild,level+1);
    }
    if(root->rightchild!=NULL)
    {
        spaceprint(level);
        cout<<"Right : ";
        printTree(root->rightchild,level+1);
    }
}

void post_order(NodeTree *root,int k)
{
    if(root==NULL)
    {
        return ;
    }
    static int cont=0;
    if(cont<=k)
    {
        post_order(root->leftchild,k);
        cont++;
        post_order(root->rightchild,k);
        if(cont==k)
            cout<<root->data<<endl;

    }
}

int main()
{
    int n;
    cin>>n;
    NodeTree *allNode[n];

    for(int i=0; i<n; i++)
    {
        allNode[i]=new NodeTree(-1);
    }
    for(int i=0; i<n; i++)
    {
        int value,left,right;
        cin>>value>>left>>right;

        allNode[i]->data=value;

        if(left>n-1 || right>n-1)
        {
            cout<<"Invalid data ";
            break;
        }
        if(left!=-1)
        {
            allNode[i]->leftchild=allNode[left];
        }

        if(right!=-1)
        {
            allNode[i]->rightchild=allNode[right];
        }
    }

    printTree(allNode[0],0);

    return 0;
}

/**
5 4
1 2 3
2 3 3
3 -1 -1
3 -1 -1
3 -1 -1

*/

