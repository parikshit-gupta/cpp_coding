#include <iostream>
#include <cstdio>
#include "D:\Development\cpp_coding\data structures\binary_trees\binary_trees1\binary_trees1.h"
using namespace std;

int height_binTree(binaryTree_node<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int left = height_binTree(root->left);
    int right = height_binTree(root->right);

    if (left >= right)
    {
        return left + 1;
    }
    else
    {
        return right + 1;
    }
}

int main()
{
    binaryTree_node<int> *root = input_binTree1();
    cout << "height: " << height_binTree(root);
    return 0;
}
