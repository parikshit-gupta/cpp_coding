#include<iostream>
#include<cstdio>
#include "D:\Development\cpp_coding\data structures\binary_trees\binary_trees1\binary_trees1.h"
using namespace std;

int count_nodes(binaryTree_node<int>*root)
{
    if (root==NULL)
    {
        return 0;
    }
    int total_nodes;
    int left=count_nodes(root->left);
    int right=count_nodes(root->right);
    total_nodes=left +right+1;
    return total_nodes;
}

int main()
{

    binaryTree_node<int>*root=input_binTree1();
    cout<<"number of nodes: "<<count_nodes(root)<<endl;
    return 0;
}