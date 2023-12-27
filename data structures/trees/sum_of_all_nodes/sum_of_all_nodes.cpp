#include<iostream>
#include<cstdio>
#include "D:\Development\cpp_coding\data structures\trees\trees1\trees1.h"
using namespace std;

int sum_nodes(tree_node<int> *root)
{
    int sum=root->data;
    for (int i=0; i<root->children.size();i++)
    {
        sum=sum+sum_nodes(root->children[i]);
    }
    return sum;

}

int main()
{
    tree_node<int>*root=tree_input1();
    cout<<sum_nodes(root)<<endl;
    return 0;
}