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
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};
Node *insert_node(Node *root, int val)
{
    if(root==nullptr) return root = new Node(val);
    else if(root->val > val) root->left = insert_node(root->left , val);
    else root->right = insert_node(root->right , val);
    return root;
}
void print(Node *root)
{
    if(root==nullptr) return ;
    cout<<root->val<<" ";
    print(root->left);
    print(root->right);
}
void levelOrder(Node *root)
{
    if(root==nullptr) return ;
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        int n = q.size();
        for(int i=0;i<n;i++){
            Node *present = q.front();
            q.pop();
            cout<<present->val<<" ";
            if(present->left!=nullptr) q.push(present->left);
            if(present->right!=nullptr) q.push(present->right);
        }
        cout<<endl;
    }
}
vector<int> rightView(Node *root)
{
    vector<int>v;
    if(root==nullptr) return v;
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        int n = q.size();
        Node *present = q.front();
        for(int i=0;i<n;i++){
            present = q.front();
            q.pop();
            if(present->left) q.push(present->left);
            if(present->right) q.push(present->right);
        }
        v.push_back(present->val);
    }
    return v;
}
vector<int>topView(Node *root)
{
    vector<int>v;
    if(root==nullptr) return v;
    map<int,int>topNodes;
    queue<pair<Node*,int>>q;
    q.push({root,0});
    while(!q.empty()){
        auto nodeHd = q.front();
        Node *node = nodeHd.first;
        int hd = nodeHd.second;
        q.pop();
        if(topNodes.find(hd)==topNodes.end())
            topNodes[hd] = node->val;
        if(node->left != nullptr)
            q.push({node->left,hd-1});
        if(node->right != nullptr)
            q.push({node->right,hd+1});
    }
    for(auto it : topNodes)
        v.push_back(it.second);
    return v;
}
int kthSmallestRecur(Node *root, int &cnt , int k)
{
    if(root == nullptr) return -1;

    int l = kthSmallestRecur(root->left, cnt, k);
    if(l != -1) return l;
    cnt++;
    if(cnt==k) return root->val;
    int r = kthSmallestRecur(root->right,cnt , k);
    return r;
}
int KthSmallest(Node *root, int k)
{
    int cnt = 0;
    return kthSmallestRecur(root, cnt, k);
}

int main()
{
    int n;
    cin>>n;
    Node *root = nullptr;
    while(n--){
        int x;
        cin>>x;
        root = insert_node(root, x);
    }
    print(root);
    cout<<endl;
    levelOrder(root);
    vector<int>v = rightView(root);
    for(int i=0;i<v.size(); i++)
        cout<<v[i]<<" ";
    cout<<endl;

    v = topView(root);
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";
    cout<<endl;
    int k;
    cout<<"Enter kth element : ";
    cin>>k;
    cout<<KthSmallest(root,k)<<endl;
    return 0;
}
/**

8
5 3 4 2 1 8 6 10

*/
