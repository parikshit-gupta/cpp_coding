#include<iostream>
#include<cstdio>
#include "D:\Development\cpp_coding\data structures\trees\trees1\trees1.h"
using namespace std;

//this function does not give us a clear idea of the structure of the tree
void print_tree(tree_node<int> *root)
{
    cout<<root->data<<endl;
    for(int i=0; i<(root->children).size();i++)
    {
        print_tree(root->children[i]);
    }
}

void print_tree1(tree_node<int> *root)
{
    //defining an edge case
    if (root==NULL)
    {
        cout<<"NULL pointer passed."<<endl;
        return;
    }
    cout<<root->data<< ": ";
    for(int i=0; i<(root->children).size();i++)
    {
        cout<<((root->children)[i])->data<<", ";
    }
    cout<<endl;
    //no base case required as the loop itself handles that
    //(we are using root->children.size(), this ensures that when leaf nodes are reached no further calls are made)
    for(int i=0; i<(root->children).size();i++)
    {
        print_tree1(root->children[i]);
    }
}

int main()
{
    tree_node<int>* root=new tree_node<int>(1);

    tree_node<int> *child1=new tree_node<int>(2);
    (root->children).push_back(child1);

    tree_node<int>* child2=new tree_node<int>(3);
    (root->children).push_back(child2);

    print_tree1(NULL);

}