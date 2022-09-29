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

void levelOrderTraversal(Node *root)
{
    if(root==NULL)
        return ;

    double sum=0;
    double c=0;

    queue<Node*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        Node *present=q.front();
        q.pop();

        if(present!=NULL)
        {
            sum+=present->data;
            c++;
           // cout<<present->data<<"  ";
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
            double k=sum/c;
            cout<<k<<"   ";
            sum=0;
            c=0;
            if(!q.empty())
                q.push(NULL);
        }
    }
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
    levelOrderTraversal(root);


    cout<<endl;

    return 0;
}
/**

4
2 7
1 5 6 9
-1 -1 -1 -1 -1 -1 -1 -1

3
9 20
-1 -1 15 7
-1 -1 -1 -1


*/
