#include<iostream>
#include<cstdio>
#include<queue>
#include "D:\Development\cpp_coding\data structures\trees\trees1\trees1.h"
using namespace std;

void print_tree(tree_node<int>*root)
{
    queue<tree_node<int>*> q;
    q.push(root);
    while(!q.empty())
    {
        tree_node<int> *front=q.front();
        q.pop();
        cout<<front->data<<": ";
        for (int i=0; i<front->children.size();i++)
        {
            cout<<front->children[i]->data<<", ";
            q.push(front->children[i]);
        }
        cout<<endl;
    }
}

int  main()
{
    tree_node<int>*root=tree_input1();
    print_tree(root);
    return 0;
}