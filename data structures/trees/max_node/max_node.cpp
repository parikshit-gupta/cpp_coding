#include<iostream>
#include<cstdio>
#include "D:\Development\cpp_coding\data structures\trees\trees1\trees1.h"
using namespace std;

//code to find the node with the max data in a integer tree
int max_node(tree_node<int>*root)
{
    int max_node1 = root->data;

    for (int i=0; i<root->children.size();i++)
    {
        int max_node_child= max_node(root->children[i]);
        if (max_node1<=max_node_child)
        {
            max_node1=max_node_child;
        }
        else 
        {
            continue;
        }
    }
    return max_node1;
}

int main()
{
    tree_node<int>* root=tree_input1();
    print_tree(root);
    cout<<max_node(root);
    return 0;

}