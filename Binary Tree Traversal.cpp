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

void in_order(NodeTree *root,string &chk)
{
    if(root==NULL)
    {
        return ;
    }
    in_order(root->leftchild,chk);
    chk+=to_string(root->data);
    in_order(root->rightchild,chk);
}

void pre_order(NodeTree *root,string &chk)
{
    if(root==NULL)
    {
        return ;
    }
    chk+=to_string(root->data);
    pre_order(root->leftchild,chk);
    pre_order(root->rightchild,chk);
}

void post_order(NodeTree *root,string &chk)
{
    if(root==NULL)
    {
        return ;
    }
    post_order(root->leftchild,chk);
    post_order(root->rightchild,chk);
    chk+=to_string(root->data);
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

    cout<<endl;

    string inorder="";
    string preorder="";
    string postorder="";

    in_order(allNode[0],inorder);
    pre_order(allNode[0],preorder);
    post_order(allNode[0],postorder);

    cout<<" In_order Traversal : "<<inorder<<endl;
    cout<<" Pre_order Traversal : "<<preorder<<endl;
    cout<<" Post_order Traversal : "<<postorder<<endl;

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
