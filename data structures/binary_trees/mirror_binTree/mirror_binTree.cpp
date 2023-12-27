#include <iostream>
#include <cstdio>
#include <queue>
#include "D:\Development\cpp_coding\data structures\binary_trees\binary_trees1\binary_trees1.h"
using namespace std;

binaryTree_node<int> *mirror(binaryTree_node<int> *root)
{
    //root of the mirrored tree
    binaryTree_node<int> *mirRoot = new binaryTree_node<int>(root->data);

    //both queues have data in the exact same order
    queue<binaryTree_node<int> *> q;
    queue<binaryTree_node<int> *> mirq;
    q.push(root);
    mirq.push(mirRoot);
    
    while (!q.empty())
    {
        binaryTree_node<int> *front = q.front();
        binaryTree_node<int> *mirfront = mirq.front();
        q.pop();
        mirq.pop();
        if (front->left != NULL && front->right != NULL)
        {
            //creating and linking nodes for the new tree with exchanged data
            binaryTree_node<int> *left = new binaryTree_node<int>(front->right->data);
            binaryTree_node<int> *right = new binaryTree_node<int>(front->left->data);
            mirfront->left = left;
            mirfront->right = right;
            mirq.push(right);
            mirq.push(left);
            q.push(front->left);
            q.push(front->right);
        }
        if (front->left == NULL && front->right != NULL)
        {
            binaryTree_node<int> *left = new binaryTree_node<int>(front->right->data);
            mirfront->left = left;
            mirq.push(left);
            q.push(front->right);
        }
        if (front->left != NULL && front->right == NULL)
        {
            binaryTree_node<int> *right = new binaryTree_node<int>(front->left->data);
            mirfront->right = right;
            mirq.push(right);
            q.push(front->left);
        }
        if (front->left == NULL && front->right == NULL)
        {
            continue;
        }
    }
    return mirRoot;
}

int main()
{
    binaryTree_node<int> *root = input_binTree1();
    cout << "original tree: " << endl;
    print_binTree1(root);
    binaryTree_node<int> *mirRoot = mirror(root);
    cout << "mirrored tree: " << endl;
    print_binTree1(mirRoot);
    return 0;
}