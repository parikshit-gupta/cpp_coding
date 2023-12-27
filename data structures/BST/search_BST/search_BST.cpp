#include<iostream>
#include<cstdio>
#include"D:\Development\cpp_coding\data structures\binary_trees\binary_trees1\binary_trees1.h"
using namespace std;

bool search_BST(binaryTree_node<int>*root, int val)
{
    if (root==NULL)
    {
        return false;
    }
    if (root->data==val)
    {
        return true;
    }
    if(root->data>val)
    {
        return search_BST(root->left, val);
    }
    if (root->data<val)
    {
        return search_BST(root->right, val);
    }
}

int main()
{
    //code to test the function
    return 0;
}