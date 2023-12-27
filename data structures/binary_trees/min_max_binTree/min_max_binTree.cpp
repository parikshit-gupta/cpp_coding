#include<iostream>
#include<cstdio>
#include<climits>
#include<queue>
#include "D:\Development\cpp_coding\data structures\binary_trees\binary_trees1\binary_trees1.h"
using namespace std;

void min_max(binaryTree_node<int>*root, int *arr)
{
    //arr[0]=min of tree
    //arr[1]=max of tree
    if (root==NULL)
    {
        return;
    }

    //compare root->data with arr[0] and arr[1]
    if (root->data<=arr[0])
    {
        arr[0]=root->data;
    }

    if (root->data>=arr[1])
    {
        arr[1]=root->data;
    }
    min_max(root->left, arr);
    min_max(root->right, arr);
    return;

}

int * min_max1(binaryTree_node<int>*root)
{
    int *arr=new int[2];
    arr[0]=INT_MAX;
    arr[1]=INT_MIN;
    queue<binaryTree_node<int>*> q;
    q.push(root);
    while(!q.empty())
    {

        binaryTree_node<int>*front=q.front();
        q.pop();
        if (front==NULL)
        {
            continue;
        }
        if (front->data<=arr[0])
        {
            arr[0]=front->data;
        }

        if (front->data>=arr[1])
        {
            arr[1]=front->data;
        }
        q.push(front->left);
        q.push(front->right);
    }
    return arr;

    /*
    //the below approach is wrong as everytime NULL is reached a new array is returned. 
    int *arr=new int[2];
    if (root==NULL)
    {
        arr[0]=INT_MAX;
        arr[1]=INT_MIN;
        return arr;
    }
    arr=min_max1(root->left);
    arr=min_max1(root->right);
    if (root->data<=arr[0])
    {
        arr[0]=root->data;
    }

    if (root->data>=arr[1])
    {
        arr[1]=root->data;
    }
    return arr;*/

}
int main()
{
    binaryTree_node<int>*root=input_binTree1();
    print_binTree1(root);
    int *arr;
    arr=min_max1(root);
    cout<<"min: "<<arr[0]<<endl;
    cout<<"max: "<<arr[1]<<endl;
    return 0;
}