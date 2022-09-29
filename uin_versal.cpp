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

bool is_unival(Node* root)
{
    if(root==NULL)
        return false;

    queue<Node*>q;
    q.push(root);
    int k=root->data;
    q.push(NULL);

    while(!q.empty())
    {
        Node *present=q.front();
        q.pop();

        if(present!=NULL)
        {
            if(present->data!=k)
                return false;
            if(present->left!=NULL)
            {
                q.push(present->left);
            }
            if(present->right!=NULL)
            {
                q.push(present->right);
            }
        }
        else
        {
            if(!q.empty())
                q.push(NULL);
        }
    }
    return true;
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

        if(n1!=NULL)
            q.push(n1);
        if(n2!=NULL)
            q.push(n2);
    }
    cout<<endl;

    if(is_unival(root))
        cout<<"This is an uni-valued tree."<<endl;
    else
        cout<<"This is not an uni-valued tree."<<endl;

    return 0;
}
/**
1
1 1
1 1 1 2
-1 -1 -1 -1 -1 -1 -1 -1

*/
