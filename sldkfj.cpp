#include<bits/stdc++.h>
using namespace std;

class treeNode
{
public:
    int data;
    treeNode *leftChild;
    treeNode *rightChild;

    //Constructor declare
    treeNode(int data)
    {
        this -> data = data;
        this -> leftChild = NULL;
        this -> rightChild = NULL;
    }
};

void sort(int size,int *arr)
{
    for(int pos = 1; pos<size; pos++)
    {
        int flag = 0;
        //cout<<"Iteration no : "<<pos<<endl;
        for(int check = 0; check<size-pos; check++)
        {
            if(arr[check] > arr[check+1])
            {
                swap(arr[check],arr[check+1]);
                flag = 1;
            }
            //printArray(size,arr);
        }
        if(flag == 0) break;
        cout<<endl;
    }
}
int second_minimum(treeNode *root)
{
    if(root == NULL)
    {
        return -1;
    }
    queue <treeNode*> que;

    que.push(root);
    que.push(NULL);
    int val = root->data;
    bool found = true;
    int idx = 0;
    int *arr = new int[10] {0};

    while(!que.empty())
    {
        treeNode *presentTree = que.front();
        que.pop();
        if(presentTree != NULL)
        {
            arr[idx] = presentTree->data;
            if(val != presentTree->data)
            {
                found = false;
            }
            if(presentTree->leftChild != NULL)
            {
                que.push(presentTree->leftChild);
            }
            if(presentTree->rightChild != NULL)
            {
                que.push(presentTree->rightChild);
            }
            idx++;

        }
        else
        {
            if(!que.empty())
            {
                que.push(NULL);

            }
        }


    }
    sort(idx,arr);
    int v = arr[0];
    int mini;
    for(int i = 1; i<idx; i++)
    {
        if(v != arr[i])
        {
            mini = arr[i];
            break;
        }
    }
    if(found == false)
    {
        return mini;
    }
    else return -1;

}

int main()
{
    int a;
    cin>>a;
    treeNode *root = new treeNode(a);
    queue <treeNode*> que;
    que.push(root);
    while(!que.empty())
    {
        treeNode *presentRoot = que.front();
        que.pop();
        int leftValue,rightValue;
        cin>>leftValue>>rightValue;

        treeNode *left = NULL;
        treeNode *right = NULL;
        if(leftValue != -1)
        {
            left = new treeNode(leftValue);
        }
        if(rightValue != -1)
        {
            right = new treeNode(rightValue);
        }
        presentRoot->leftChild = left;
        presentRoot->rightChild = right;
        if(left != NULL)
        {
            que.push(left);
        }
        if(right != NULL)
        {
            que.push(right);
        }

    }

    int secondMinimum = second_minimum(root);
    cout<<secondMinimum<<endl;


    return 0;
}
/*
2
2 2
-1 -1 -1 -1
*/
