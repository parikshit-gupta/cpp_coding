#include<iostream>
#include<cstdio>
#include "D:\Development\cpp_coding\data structures\trees\trees1\trees1.h"
using namespace std;

int leaf_nodes(tree_node<int>*root)
{
    int num_leaf=0;
    if (root->children.size()==0)
    {
        num_leaf=1;
        return num_leaf;
    }

    for (int i=0; i<root->children.size(); i++)
    {
        num_leaf=num_leaf+leaf_nodes(root->children[i]);
    }
    return num_leaf;
}

int main()
{
    tree_node<int>*root=tree_input1();
    print_tree(root);
    cout<<"number of leaf nodes: "<<leaf_nodes(root)<<endl;
    return 0;
}