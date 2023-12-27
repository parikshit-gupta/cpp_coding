#include <iostream>
#include <cstdio>
#include <vector>
#include "D:\Development\cpp_coding\data structures\binary_trees\binary_trees1\binary_trees1.h"
using namespace std;

void search(binaryTree_node<int> *root, int k, vector<int> &v)
{
    if (root == NULL)
    {
        return;
    }
    if (root->data == k)
    {
        v.push_back(root->data);
        return;
    }
    v.push_back(root->data);
    search(root->left, k, v);
    search(root->right, k, v);
    int size = v.size();
    if (v[size - 1] != k)
    {
        v.pop_back();
        return;
    }
}

vector<int> pathBST(binaryTree_node<int> *root, int k)
{
    vector<int> v;
    search(root, k, v);
    return v;
}

vector<int> pathBST1(binaryTree_node<int> *root, int k, vector<int> v = {0})
{
    if (root == NULL)
    {
        return v;
    }
    if (root->data == k)
    {
        v.push_back(root->data);
        return v;
    }
    v.push_back(root->data);
    v = pathBST1(root->left, k, v);
    if (v[v.size() - 1] != k)
    {
        v = pathBST1(root->right, k, v);
    }

    if (v[v.size() - 1] != k)
    {
        v.pop_back();
    }
    return v;
}

vector<int> pathBST2(binaryTree_node<int> *root, int k)
{
    vector<int> v;
    if (root == NULL)
    {
        return v;
    }

    if (root->data == k)
    {
        v.push_back(root->data);
        return v;
    }

    v = pathBST2(root->left, k);
    if (!v.empty())
    {
        if (v[0] == k)
        {
            v.push_back(root->data);
            return v;
        }
    }
    v = pathBST2(root->right, k);
    if (!v.empty())
    {
        if (v[0] == k)
        {
            v.push_back(root->data);
            return v;
        }
    }
    return v;
}

int main()
{
    binaryTree_node<int> *root = input_binTree1();
    int k = 6;
    print_binTree1(root);
    vector<int> v = pathBST2(root, k);
    cout << "path to node: ";
    if (v.size() == 0)
    {
        cout << "node not present." << endl;
    }
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << ",";
    }
    delete root;
    return 0;
}