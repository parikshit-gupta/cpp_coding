#include <iostream>
#include <cstdio>
#include "D:\Development\cpp_coding\data structures\binary_trees\binary_trees1\binary_trees1.h"
using namespace std;

void insert_BST(binaryTree_node<int> *root, int val)
{
    if (val > root->data)
    {
        if (root->right == NULL)
        {
            binaryTree_node<int> *node = new binaryTree_node<int>(val);
            root->right = node;
            return;
        }
        insert_BST(root->right, val);
    }

    if (val < root->data)
    {
        if (root->left == NULL)
        {
            binaryTree_node<int> *node = new binaryTree_node<int>(val);
            root->left = node;
            return;
        }
        insert_BST(root->left, val);
    }
    if (val = root->data)
    {
        cout << "BST cant have repeated nodes" << endl;
        return;
    }
}

int main()
{
    binaryTree_node<int>*root=input_binTree1();
    cout<<"before: "<<endl;
    print_binTree1(root);
    int val=10;
    insert_BST(root,val);
    cout<<"after: "<<endl;
    print_binTree1(root);
    return 0;
}