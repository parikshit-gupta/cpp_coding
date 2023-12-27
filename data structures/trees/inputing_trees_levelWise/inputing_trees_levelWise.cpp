#include <iostream>
#include <cstdio>
#include "D:\Development\cpp_coding\data structures\trees\trees1\trees1.h"
#include <queue>
using namespace std;

// inputting a tree levelwise
void tree_input(queue<tree_node<int> *> q)
{
    int n;
    cout << (q.front())->data << " : enter the number of children of this node: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int data;
        cout << "enter data for child" << i + 1 << ": ";
        cin >> data;

        tree_node<int> *child = new tree_node<int>(data);
        q.front()->children.push_back(child);
        q.push(child);
    }
    q.pop();
    if (!q.empty())
    {
        tree_input(q);
    }
}

//a better code with the same approach and algo as above
tree_node<int>* tree_input1()
{
    int rootData;
    cout<<"enter root data: ";
    cin>>rootData;

    tree_node<int>*root=new tree_node<int>(rootData);

    queue <tree_node<int>*> q;
    q.push(root);
    while(!q.empty())
    {
        tree_node<int>*front=q.front();
        q.pop();
        int numChild;
        cout<<"enter the number of children for node "<<front->data<<": ";
        cin>>numChild;
        for (int i=0; i<numChild;i++)
        {
            int data;
            cout<<"enter the data of child"<<i+1<<" of node "<<front->data<<": ";
            cin>>data;
            tree_node<int>*child=new tree_node<int>(data);
            front->children.push_back(child);
            q.push(child);
        }
    }
    return root;
}



void print_tree1(tree_node<int> *root)
{
    // defining an edge case
    if (root == NULL)
    {
        cout << "NULL pointer passed." << endl;
        return;
    }
    cout << root->data << ": ";
    for (int i = 0; i < (root->children).size(); i++)
    {
        cout << ((root->children)[i])->data << ", ";
    }
    cout << endl;
    // no base case required as the loop itself handles that
    //(we are using root->children.size(), this ensures that when leaf nodes are reached no further calls are made)
    for (int i = 0; i < (root->children).size(); i++)
    {
        print_tree1(root->children[i]);
    }
}

int main()
{
    /*tree_node<int> *root = new tree_node<int>(1);
    queue<tree_node<int> *> q;
    q.push(root);
    tree_input(q);*/
    tree_node<int>*root=tree_input1();
    print_tree1(root);

    return 0;
}