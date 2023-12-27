#include<iostream>
#include<cstdio>
#include "D:\Development\cpp_coding\data structures\binary_trees\binary_trees1\binary_trees1.h"
using namespace std;

bool is_node(binaryTree_node<int>*root, int node)
{
    if (root==NULL)
    {
        return false;
    }
    if (root->data==node)
    {
        return true;
    }


    bool left = is_node(root->left, node);
    bool right= is_node(root->right, node);

    return left||right;
 
}

int main()
{
    binaryTree_node<int>*root=input_binTree1();
    cout<<is_node(root, 7)<<endl;

    return 0;
}