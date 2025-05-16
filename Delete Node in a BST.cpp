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

Node *insert_node_bst(Node *root, int val)
{
    if(root==NULL)
        return root = new Node(val);
    else if(root->val<val)
        root->right = insert_node_bst(root->right,val);
    else root->left= insert_node_bst(root->left, val);
    return root;
}

void print(Node *root)
{
    if(root==NULL)
         return ;
    cout<<root->val<<" ";
    print(root->left);
    print(root->right);
}
Node *getSuccssor(Node *curr)
{
    curr=curr->right;
    while(curr!=NULL && curr->left!=NULL)
        curr=curr->left;
    return curr;
}

Node *delNode(Node *root, int val)
{
    if(root==NULL) return root;
    else if(root->val<val) root->right=delNode(root->right, val);
    else if(root->val>val) root->left=delNode(root->left,val);
    else{
        if(root->left==NULL){
            Node *temp=root->right;
            delete(root);
            return temp;
        }
        else if(root->right==NULL){
            Node *temp = root->left;
            delete(root);
            return temp;
        }
        else{
            Node *succ = getSuccssor(root);
            root->val=succ->val;
            root->right = delNode(root->right,succ->val);
        }
    }
    return root;
}
Node *isFound(Node *root, int val)
{
    Node *curr = root;
    while(curr){
        if(curr->val==val) return curr;
        else if(curr->val<val) curr=curr->right;
        else curr=curr->left;
    }
    return curr;
}
int height(Node *root)
{
    if(root == NULL) return -1;
    int l = height(root->left)+1;
    int r = height(root->right)+1;
    return max(r,l);
}

void mirror(Node *&node)
{
    if(node == NULL) return ;
    mirror(node->left);
    mirror(node->right);
    swap(node->left,node->right);
}
int main()
{
    int n;
    cin>>n;
    Node *root = NULL;
    while(n--){
        int x;
        cin>>x;
        root = insert_node_bst(root,x);
    }
    print(root);
    cout<<endl;
    cout<<"Enter a node :";
    int a;
    cin>>a;
    int x;
    cout<<"Enter a node : ";
    cin>>x;
    root = delNode(root,x);
    print(root);
    cout<<endl;
    cout<<height(root)<<endl;
    mirror(root);
    root = isFound(root, a);
    print(root);
    cout<<endl;

    return 0;
}

/**

9
4 1 2 3 6 5 7 9 10
6
7

*/
