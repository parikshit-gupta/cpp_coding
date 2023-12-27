#include <iostream>
#include <cstdio>
#include "D:\Development\cpp_coding\data structures\trees\trees1\trees1.h"
using namespace std;

int height_tree(tree_node<int> *root)
{
    int max_height = 0;
    for (int i = 0; i < root->children.size(); i++)
    {
        int child_height = height_tree(root->children[i]);
        if (child_height >= max_height)
        {
            max_height = child_height;
        }
        else
        {
            continue;
        }
    }
    return max_height + 1;
}

int main()
{
    tree_node<int>*root=tree_input1();
    print_tree(root);
    cout<<height_tree(root)<<endl;
    return 0;
}