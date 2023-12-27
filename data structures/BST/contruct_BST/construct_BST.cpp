#include<iostream>
#include<cstdio>
#include "D:\Development\cpp_coding\data structures\binary_trees\binary_trees1\binary_trees1.h"
using namespace std;

binaryTree_node<int>* construct_BST(int*arr,int size)
{
    if (size==0)
    {
        return NULL;
    }
    if(size==1)
    {
        binaryTree_node<int>*root=new binaryTree_node<int>(arr[0]);
        return root;
    }

    binaryTree_node<int>*root=new binaryTree_node<int>();
    //size is even
    if (size%2==0)
    {
        int mid=(size/2)-1;
        root->data=arr[mid];
        binaryTree_node<int>*left = construct_BST(arr, size-mid-2);
        binaryTree_node<int>*right = construct_BST(arr+mid+1,mid+1);
        root->left=left;
        root->right=right;
    }

    //size is odd
    else 
    {
        int mid=(size/2);
        root->data=arr[mid];
        binaryTree_node<int>*left = construct_BST(arr, size-mid-1);
        binaryTree_node<int>*right = construct_BST(arr+mid+1,mid);
        root->left=left;
        root->right=right;
    }
    return root;

}

int main()
{
    int arr[]={1, 2, 3, 4, 5, 6, 7};
    int size=7;
    binaryTree_node<int>* root=construct_BST(arr, size);
    print_binTree1(root);
    delete root;
    return 0;
}