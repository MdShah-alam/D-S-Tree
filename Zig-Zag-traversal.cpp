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

void zig_zag(Node *root)
{
    if(root==NULL)
        return ;
    stack<Node *>curr;
    stack<Node *>next;
    bool found=true;
    curr.push(root);
    while(!curr.empty())
    {
        Node *x=curr.top();
        curr.pop();
        cout<<x->data<<"  ";
        if(found)
        {
            if(x->left)
            next.push(x->left);
            if(x->right)
            next.push(x->right);
        }
        else
        {
            if(x->right)
            next.push(x->right);
            if(x->left)
            next.push(x->left);
        }
        if(curr.empty())
        {
            swap(curr,next);
            found=!found;
        }
    }
}

void print(Node *root)
{
    if(root==NULL)
        return ;
    cout<<root->data<<"  ";
    print(root->left);
    print(root->right);
}

int main()
{
    int n;
    cin>>n;
    Node *root=new Node(n);
    queue<Node*>q;
    q.push(root);

    while(!q.empty())
    {
        Node *present=q.front();
        q.pop();
        int x,y;
        cin>>x>>y;
        Node *n1=NULL;
        Node* n2=NULL;

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
    cout<<endl<<"Before zigzag traversal "<<endl<<endl;
    print(root);
    cout<<endl<<endl;
    cout<<"After zigzag traversal "<<endl<<endl;
    zig_zag(root);

    cout<<endl<<endl;

    return 0;
}

/**

3
9 20
-1 -1 15 7
-1 -1 -1 -1

*/
