#include<iostream>
#include<cstdio>
#include<queue>
#include "D:\Development\cpp_coding\data structures\trees\trees1\trees1.h"
using namespace std;

int num_nodes(tree_node<int>* root)
{
    int count=1;
    for (int i=0;i<(root->children).size();i++)
    {
        count=count+num_nodes(root->children[i]);
    }

    return count;
}

int num_nodes1(tree_node<int>*root)
{
    int count=1;
    queue<tree_node<int>*> q;
    q.push(root);
    while(!q.empty())
    {
        tree_node<int>* front=q.front();
        q.pop();
        count=count+front->children.size();
        for (int i=0; i<front->children.size();i++)
        {
            q.push(front->children[i]);
        }
    }
    return count;
}



int main()
{
    tree_node<int>*root=tree_input1();
    int nodes=num_nodes1(root);
    cout<<"number of nodes: "<<nodes<<endl;
    return 0;
}
