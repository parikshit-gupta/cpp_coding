#include<iostream>
#include<cstdio>
#include"D:\Development\cpp_coding\data structures\binary_trees\binary_trees1\binary_trees1.h"
using namespace std;

binaryTree_node<int>* construct(int *arr, int size)
{
    if(size==1)
    {
        binaryTree_node<int>*root=new binaryTree_node<int>(*arr);
        return root;
    }
    if (size==0)
    {
        return NULL;
    }

    int mid;//mid index
    int left_size;
    int right_size;
    if(size%2==0)
    {
        mid=(size-1)/2;
        left_size=size-(mid+2);
        right_size=size-left_size-1;
    }
    if(size%2!=0)
    {
        mid=(size)/2;
        left_size=size-(mid+1);
        right_size=size-left_size-1;
    }

    binaryTree_node<int>* root=new binaryTree_node<int>(arr[mid]);
    binaryTree_node<int>*left_node=construct(arr, left_size);
    binaryTree_node<int>*right_node=construct(arr+mid+1, right_size);
    root->left=left_node;
    root->right=right_node;
    return root;
}

int main()
{
    int arr[]={1,2,3,4,5,6,7,8,9,10};
    int arr1[]={1,2,3,4,5,6,7,8,9,10,11};
    int size=sizeof(arr)/4;
    int size1=sizeof(arr1)/4;
    //binaryTree_node<int>* root=construct(arr, size);
    binaryTree_node<int>* root1=construct(arr1, size1);
    print_binTree1(root1);

    return 0;
}