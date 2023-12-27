#include <iostream>
#include <cstdio>
#include<vector>
#include "D:\Development\cpp_coding\data structures\binary_trees\binary_trees1\binary_trees1.h"
using namespace std;

//the binary tree inputted will be a BST
void in_range(binaryTree_node<int> *root, int start, int end)
{
    if (root==NULL)
    {
        return;
    }

    //if the current root is in the given range
    if (root->data >= start && root->data <= end)
    {   
        in_range(root->left, start, end);
        cout<<root->data<<", ";
        in_range(root->right, start, end);
    }

    //if the current root is out of range
    /*if current node is smaller than the start of the range, then anything to the left of the current
    node will be smaller, thuse we need to call the function on root->right*/
    if (root->data<start)
    {
        in_range(root->right, start, end);
    }

    if (root->data>end)
    {
        in_range(root->left, start, end);
    }
    return;
}

int main()
{
    binaryTree_node<int>*root=input_binTree1();
    print_binTree1(root);
    int start=6;
    int end=10;
    cout<< "elements in the given range are: ";
    in_range(root, start, end);
    return 0;
}