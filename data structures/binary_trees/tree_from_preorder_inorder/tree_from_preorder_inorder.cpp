#include <iostream>
#include <cstdio>
#include "D:\Development\cpp_coding\data structures\binary_trees\binary_trees1\binary_trees1.h"
using namespace std;

binaryTree_node<int> *tree_construct(int *pre, int *in, int size)
{
    if (size == 0)
    {
        return NULL;
    }
    if (size==1)
    {
        binaryTree_node<int>*root=new binaryTree_node<int>(pre[0]);
        return root;
    }
    binaryTree_node<int>* root=new binaryTree_node<int>(pre[0]);
    int left_pre[10]={0};
    int left_in[10]={0};
    int right_pre[10]={0};
    int right_in[10]={0};
    int left_size=0;
    int right_size=0;
    //creating the inorder array for left and right nodes of root;
    for (int i=0;i<size;i++)
    {
        if (in[i]==pre[0])
        {
            left_size=i;
            i++;
            for (i;i<size;i++)
            {
                right_in[i-left_size-1]=in[i];
            }
            right_size=size-left_size-1;
            break;
        }
        left_in[i]=in[i];
    }
    for (int i=1; i<size;i++)
    {
        if (i>=1 && i<=left_size)
        {
            left_pre[i-1]=pre[i];
        }
        if (i>left_size&& i<size)
        {
            right_pre[i-left_size-1]=pre[i];
        }
    }
    binaryTree_node<int>*left=tree_construct(left_pre, left_in, left_size);
    binaryTree_node<int>*right=tree_construct(right_pre, right_in, right_size);
    root->left=left;
    root->right=right;
    return root;
}

int main()
{
    int arr1[]={5, 6, 2, 3, 9, 10};
    int arr2[]={5, 6, 2, 3, 9, 10};
    binaryTree_node<int>*root=tree_construct(arr1, arr2, 6);
    print_binTree1(root);
    return 0;
}
