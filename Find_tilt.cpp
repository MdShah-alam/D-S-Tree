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

int traversal(Node *root, int *tilt)
{
    if(root==NULL)
        return 0;

    int left=traversal(root->left,tilt);
    int right=traversal(root->right,tilt);

    *tilt+=abs(left-right);

    return left+right+root->data;
}

int findTilt(Node *root)
{
    int tilt=0;
    traversal(root,&tilt);
    return tilt;
}

void printTree(Node *root)
{
    if(root==NULL)
        return ;

    cout<<root->data<<"  ";
    printTree(root->left);
    printTree(root->right);
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
//    cout<<endl;
//    printTree(root);
    cout<<endl;
    cout<<endl;


    cout<<"The sum is : "<<findTilt(root)<<endl;

    return 0;
}

/**

1
2 3
-1 -1 -1 -1


4
2 7
1 5 6 9
-1 -1 -1 -1 -1 -1 -1 -1

*/
