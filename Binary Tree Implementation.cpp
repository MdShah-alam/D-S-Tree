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

int main()
{
    int n;
    cin>>n;
    NodeTree *allNode[n];

    for(int i=0; i<n; i++)
    {
        allNode[i]=new NodeTree(-1);
    }
    for(int i=0;i<n;i++)
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
5
0 1 2
1 3 -1
2 -1 4
3 -1 -1
4 -1 -1


9
0   1  2
1   3  4
2   5  6
3  -1 -1
4  -1 -1
5   7  8
6  -1 -1
7  -1 -1
8  -1 -1

*/
