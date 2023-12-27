#include<cstdio>
#include<iostream>
#include"D:\Development\cpp_coding\data structures\binary_trees\binary_trees1\binary_trees1.h"
using namespace std;

void mirror_BinTree(binaryTree_node<int>*root)
{
    if(root==NULL)
    {
        return;
    }

    binaryTree_node<int> *temp=root->left;
    root->left=root->right;
    root->right=temp;

    mirror_BinTree(root->left);
    mirror_BinTree(root->right);
    return;
}

int main()
{
    binaryTree_node<int>* root=input_binTree1();
    cout<<"before: "<<endl;
    print_binTree1(root);
    cout<<"after: "<<endl;
    mirror_BinTree(root);
    print_binTree1(root);
}