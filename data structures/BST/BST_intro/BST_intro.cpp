#include <iostream>
#include <cstdio>
#include "D:\Development\cpp_coding\data structures\binary_trees\binary_trees1\binary_trees1.h"
using namespace std;

// the binary tree inputted will be a BST
bool is_present(binaryTree_node<int> *root, int k)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->data == k)
    {
        return true;
    }
    if (root->data > k)
    {
        return is_present(root->left, k);
    }
    if (root->data < k)
    {
        return is_present(root->right, k);
    }
}

int main()
{
    binaryTree_node<int> *root = input_binTree1();
    print_binTree1(root);
    int k = 12;
    cout << "is_present: " << is_present(root, k) << endl;
    return 0;
}
// 8 1 5 1 10 1 2 1 6 0 0 0 0 0 1 7 0 0