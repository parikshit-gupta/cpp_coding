#include <iostream>
#include <cstdio>
#include "D:\Development\cpp_coding\data structures\trees\trees1\trees1.h"
using namespace std;

void pre_order(tree_node<int> *root)
{
    cout << root->data << endl;
    for (int i = 0; i < root->children.size(); i++)
    {
        pre_order(root->children[i]);
    }
}

void post_order(tree_node<int> *root)
{
    for (int i = 0; i < root->children.size(); i++)
    {
        post_order(root->children[i]);
    }
    cout << root->data << endl;
}

int main()
{
    tree_node<int> *root = tree_input1();
    cout << "pre-order: " << endl;
    pre_order(root);
    cout << "post-order: " << endl;
    post_order(root);
    delete root;
    return 0;
}