#include<iostream>
#include<cstdio>
#include "D:\Development\cpp_coding\data structures\binary_trees\binary_trees1\binary_trees1.h"
using namespace std;

void inorder(binaryTree_node<int>*root)
{
    if (root==NULL)
    {
        return;
    }

    inorder(root->left);
    cout<<root->data<<endl;
    inorder(root->right);
}

int main()
{
    binaryTree_node<int>*root=input_binTree1();
    inorder(root);
    return 0;
}