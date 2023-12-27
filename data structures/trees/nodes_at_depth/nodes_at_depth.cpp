#include<iostream>
#include<cstdio>
#include "D:\Development\cpp_coding\data structures\trees\trees1\trees1.h"
using namespace std;

//printing all nodes at a given depth of a tree
void node_at_depth(tree_node<int>*root, int depth)
{
    //edge case
    if (root==NULL)
    {
        return;
    }

    if (depth==0)
    {
        cout<<root->data<<", ";
        return;
    }
    for (int i=0; i<root->children.size();i++)
    {
        node_at_depth(root->children[i], depth -1);
    }
}

int main()
{
    tree_node<int>*root =tree_input1();
    node_at_depth(root, 2);
    return 0;
}