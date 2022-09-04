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

void spacelevel(int level)
{
    for(int i=0; i<level; i++)
    {
        cout<<"  ";
    }
}

void printTree(Node *root,int level)
{
    if(root==NULL)
        return ;
    if(root->left==NULL && root->right==NULL)
    {
        cout<<root->val<<endl;
        return ;
    }
    else
    {
        cout<<endl;
        spacelevel(level);
        cout<<"Root : "<<root->val<<endl;
    }
    if(root->left!=NULL)
    {
        spacelevel(level);
        cout<<"Left : ";
        printTree(root->left,level+1);
    }
    if(root->right!=NULL)
    {
        spacelevel(level);
        cout<<"Right : ";
        printTree(root->right,level+1);
    }
}

int search_position(int ino[],int current, int start,int last)
{
    for(int i=start;i<=last;i++)
    {
        if(ino[i]==current)
            return i;
    }
    return -1;
}

Node *buildtree(int pre[],int ino[],int start, int last)
{
    static int id =0;
    int current=pre[id];
    id++;

    Node *currentNode=new Node(current);

    if(start==last)
    {
        return currentNode;
    }
    int pos=search_position(ino,current,start,last);
    currentNode->left=buildtree(pre,ino,start,pos-1);
    currentNode->right=buildtree(pre,ino,pos+1,last);
}

void pre_order(Node *root,string &chk)
{
    if(root==NULL)
    {
        return ;
    }
    chk+=to_string(root->val);
    pre_order(root->left,chk);
    pre_order(root->right,chk);
}

int main()
{
    int n;
    cin>>n;
    int pre[n];
    int ino[n];
    for(int i=0;i<n;i++)
    {
        cin>>pre[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>ino[i];
    }
    Node * root=buildtree(pre,ino,0,n-1);
    //printTree(root[0],0);

    string chk="";
    pre_order(root,chk);

    cout<<chk<<endl;

    return 0;
}
/**

9
0 1 3 4 2 5 7 8 6
3 1 4 0 7 5 8 2 6

*/
