#include<iostream>
#include<cstdio>
#include "D:\Development\cpp_coding\data structures\trees\trees1\trees1.h"

using namespace std;

//creating a simple tree
int main()
{
    //tree_node<int> * root=new tree_node<int>;
    //root->data=1;

    tree_node<int>* root=new tree_node<int>(1);
    
    //tree_node<int> * child1=new tree_node<int>;
    //(root->children).push_back(child1);
    //child1->data=2;

    tree_node<int> *child1=new tree_node<int>(2);
    (root->children).push_back(child1);
    
    //tree_node<int> * child2=new tree_node<int>;
    //child2->data=3;

    tree_node<int>* child2=new tree_node<int>(3);
    (root->children).push_back(child2);

    cout<<root->data<<endl;
    cout<<(root->children)[0]->data<<endl;
    cout<<(root->children)[1]->data<<endl;
    //cout<<child1->data<<endl;
    //cout<<child2->data<<endl;

}
