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
    for(int i=0;i<level;i++)
    {
        cout<<"   ";
    }
}

void printtree(NodeTree *root,int level)
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
        cout<<"Root : "<<root->data<<endl;
    }

    if(root->leftchild!=NULL)
    {
        spaceprint(level);
        cout<<"Left : ";
        printtree(root->leftchild,level+1);
    }

    if(root->rightchild!=NULL)
    {
        spaceprint(level);
        cout<<"Right : ";
        printtree(root->rightchild,level+1);
    }
}

int cont;

void in_order(NodeTree *root,int k)
{
    if(root==NULL)
        return ;

    if(cont<=k)
    {
        cont++;

        in_order(root->leftchild,k);

        if(cont==k)
            cout<<root->data<<endl;

        cont++;

       in_order(root->rightchild,k);
    }
}

int main()
{
    int a;
    cin>>a;
    NodeTree *root=new NodeTree(a);

    queue<NodeTree *>q;
    q.push(root);

    while(!q.empty())
    {
        NodeTree *present=q.front();
        q.pop();

        int x,y;
        cin>>x>>y;
        NodeTree *n1=NULL;
        NodeTree *n2=NULL;

        if(x!=-1) n1=new NodeTree(x);
        if(y!=-1) n2=new NodeTree(y);

        present->leftchild=n1;
        present->rightchild=n2;

        if(n1!=NULL) q.push(n1);
        if(n2!=NULL) q.push(n2);
    }


    printtree(root,0);

    //string inorder="";
    cont=1;

    in_order(root,4);

    //cout<<"Inorder Traversal :"<<inorder<<endl;

    return 0;
}

/**
5 4
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

5
1 2 3
2 4 5
3 -1 -1
4 -1 -1
5 -1 -1

*/
