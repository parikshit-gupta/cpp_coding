#include <iostream>
#include <cstdio>
#include "D:\Development\cpp_coding\data structures\trees\trees1\trees1.h"
using namespace std;

//inputing a tree branchwise
tree_node<int> *input_tree()
{
    // create a root node
    int data;
    cout << "input data of current node: ";
    cin >> data;
    tree_node<int> *root = new tree_node<int>(data);

    // asking user if the want children of current node
    int x;
    cout << "do you want children of this node [1/0]: ";
    cin >> x;
    if (x == 0)
    {
        return root;
    }
    if (x == 1)
    {
    }

    int c = 1;
    while (c == 1)
    {
        // creating child node
        tree_node<int> *child = input_tree();

        // linking child node
        (root->children).push_back(child);

        // asking user if they want more children of this node
        cout << root->data << " : do you want more children of this node[1/0]: ";
        cin >> c;
    }
    return root;
}

void tree_input1(tree_node<int>* root)
{
    int n;
    cout<< root->data <<" : enter the number of children of this node: ";
    cin>>n;
    for (int i=0;i<n;i++)
    {
        int data;
        cout<<"enter the data for child"<<i+1<<": ";
        cin>>data;
        tree_node<int>*child=new tree_node<int>(data);
        root->children.push_back(child);
    }
    for (int i=0;i<n;i++)
    {
        tree_input1(root->children[i]);
    }
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
    tree_node<int> *root = input_tree();
    print_tree1(root);
    return 0;
}