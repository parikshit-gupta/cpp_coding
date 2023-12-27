#include <iostream>
#include <cstdio>
#include <queue>
#include "D:\Development\cpp_coding\data structures\binary_trees\binary_trees1\binary_trees1.h"
using namespace std;

// printing a bin_tree branchwise
void print_binTree(binaryTree_node<int> *root)
{
    // base case for the print bin_tree function
    if (root == NULL)
    {
        return;
    }
    cout << root->data << ": ";
    if (root->left != NULL)
    {
        cout << "L:" << root->left->data << " ";
    }
    if (root->right != NULL)
    {
        cout << "R:" << root->right->data;
    }
    cout << endl;
    print_binTree(root->left);
    print_binTree(root->right);
}

// printing a binary tree levelwise
void print_binTree1(binaryTree_node<int> *root)
{
    if (root == NULL)
    {
        return;
    }

    queue<binaryTree_node<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        binaryTree_node<int> *front = q.front();
        q.pop();
        cout << front->data << ": ";
        if (front->left != NULL)
        {
            cout << "L: " << front->left->data << " ";
            q.push(front->left);
        }
        if (front->right != NULL)
        {
            cout << "R: " << front->right->data;
            q.push(front->right);
        }
        cout << endl;
    }
}

// taking input to binary tree branchwise
binaryTree_node<int> *input_binTree()
{
    int data;
    cout << "enter data for current node: ";
    cin >> data;
    binaryTree_node<int> *root = new binaryTree_node<int>(data);
    int c;
    cout << root->data << ": do you want a left branch of this node[1/0]: ";
    cin >> c;
    if (c == 1)
    {
        binaryTree_node<int> *left_node = input_binTree();
        root->left = left_node;
    }
    cout << root->data << ": do you want a right branch of this node[1/0]: ";
    cin >> c;
    if (c == 1)
    {
        binaryTree_node<int> *right_node = input_binTree();
        root->right = right_node;
    }
    return root;
}

// taking input to a binay tree levelwise
binaryTree_node<int> *input_binTree1()
{
    int rootData;
    cout << "enter root data: ";
    cin >> rootData;
    binaryTree_node<int> *root = new binaryTree_node<int>(rootData);
    queue<binaryTree_node<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        binaryTree_node<int> *front = q.front();
        q.pop();
        int c;
        cout << front->data << ": do you want a left branch of this node[1/0]: ";
        cin >> c;
        if (c == 1)
        {
            int leftData;
            cout << "enter data for left node: ";
            cin >> leftData;
            binaryTree_node<int> *left_node = new binaryTree_node<int>(leftData);
            front->left = left_node;
            q.push(left_node);
        }
        cout << front->data << ": do you want a right branch of this node[1/0]: ";
        cin >> c;
        if (c == 1)
        {
            int rightData;
            cout << "enter data for right node: ";
            cin >> rightData;
            binaryTree_node<int> *right_node = new binaryTree_node<int>(rightData);
            front->right = right_node;
            q.push(right_node);
        }
    }
    return root;
}

int main()
{
    /*
    binaryTree_node<int> *root = new binaryTree_node<int>(1);
    binaryTree_node<int> *node1 = new binaryTree_node<int>(2);
    binaryTree_node<int> *node2 = new binaryTree_node<int>(3);

    root->left = node1;
    root->right = node2;
    */
    binaryTree_node<int> *root = input_binTree1();
    print_binTree1(root);
    delete root;
    return 0;
}
