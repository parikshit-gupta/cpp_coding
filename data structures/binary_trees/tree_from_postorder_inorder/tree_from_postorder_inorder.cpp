#include <iostream>
#include <cstdio>
#include "D:\Development\cpp_coding\data structures\binary_trees\binary_trees1\binary_trees1.h"
using namespace std;

binaryTree_node<int> *tree_construct(int *post, int *in, int size)
{
    if (size==0)
    {
        return NULL;
    }
    if (size==1)
    {
        binaryTree_node<int>* root= new binaryTree_node<int>(post[0]);
        return root;
    }
    binaryTree_node<int> *root = new binaryTree_node<int>(post[size - 1]);
    int left_post[10] = {0};
    int left_in[10] = {0};
    int right_post[10] = {0};
    int right_in[10] = {0};
    int left_size = 0;
    int right_size = 0;
    // creating the inorder arrays for left and right tree nodes
    for (int i = 0; i < size; i++)
    {
        if (in[i] == post[size - 1])
        {
            left_size = i;
            i++;
            for (i; i < size; i++)
            {
                right_in[i - left_size - 1] = in[i];
            }
            right_size = size - left_size - 1;
            break;
        }
        left_in[i] = in[i];
    }

    // creating the postorder arrays for left and right nodes of current node
    for (int i = 0; i < size - 1; i++)
    {
        if (i >= 0 && i < left_size)
        {
            left_post[i] = post[i];
        }
        if (i >= left_size)
        {
            right_post[i-left_size] = post[i];
        }
    }

    binaryTree_node<int> *left = tree_construct(left_post, left_in, left_size);
    binaryTree_node<int> *right = tree_construct(right_post, right_in, right_size);
    root->left = left;
    root->right = right;
    return root;
}

int main()
{
    int arr1[]={4, 5, 2, 6, 7, 3, 1};
    int arr2[]={4, 2, 5, 1, 6, 3, 7};
    binaryTree_node<int>*root=tree_construct(arr1, arr2, 7);
    print_binTree1(root);
    return 0;
}