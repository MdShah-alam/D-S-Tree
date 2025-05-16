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
        this->left=NULL;
        this->right=NULL;
    }
};

Node *insert_a_node(Node *&root, int val)
{
    if(root==NULL)
        return new Node(val);
    if(root->val==val)
        return root;
    else if(root->val<val)
        root->right=insert_a_node(root->right,val);
    else root->left=insert_a_node(root->left,val);
    return root;
}
Node *getSuccssor(Node *curr)
{
    curr=curr->right;
    while(curr!=NULL && curr->left!=NULL)
        curr=curr->left;
    return curr;
}

Node *deletion(Node *root, int val)
{
    if(root==NULL)
        return root;
    else if(root->val>val)
        root->left=deletion(root->left,val);
    else if(root->val<val)
        root->right = deletion(root->right,val);
    else{
        if(root->left==NULL){
            Node *temp = root->right;
            delete(root);
            return temp;
        }
        else if(root->right==NULL){
            Node *temp=root->left;
            delete(root);
            return temp;
        }
        else{
            Node *succ = getSuccssor(root);
            root->val = succ->val;
            root->right = deletion(root->right,succ->val);
        }
    }
    return root;
}

void print(Node *root)
{
    if(root==NULL) return ;
    cout<<root->val<<" ";
    print(root->left);
    print(root->right);
}

int main()
{
    int n;
    cin>>n;
    Node *root=NULL;
    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        root = insert_a_node(root,val);
    }
    print(root);
    cout<<endl;
    int x;
    cout<<"Enter the value of deletion node : ";
    cin>>x;
    root = deletion(root, x);
    print(root);
    cout<<endl;

    return 0;
}
/**

6
4 1 2 6 5 7

*/
