#include<iostream>
#include<cstdio>
#include<vector>
#include "D:\Development\cpp_coding\data structures\binary_trees\binary_trees1\binary_trees1.h"
using namespace std;

vector<binaryTree_node<int>*> search_node(vector<binaryTree_node<int>*> v, int node)
{
    int last=v.size()-1;
    binaryTree_node<int>*current=v[last];
    binaryTree_node<int>*left=v[last]->left;
    binaryTree_node<int>*right=v[last]->right;
    //leaf node
    if (current->data==node)
    {
        return v;
    }

    if (left==NULL&&right==NULL)
    {
        v.pop_back();
        return v;
    }

    v.push_back(left);
    v=search_node(v, node);
    if (v.back()->data==node)
    {
        return v;
    }
    v.push_back(right);
    v=search_node(v,node);
    if (v.back()->data==node)
    {
        return v;
    }
    v.pop_back();
    return v;
    
    /*
    //leaf node
    if (root->left==NULL&&root->right==NULL)
    {
        v.pop_back();
        return v;
    }

    if (root->data==node)
    {
        return v;
    }

    v=search_node(root->left, node);
    if (v[v.size()-1]->data==node)
    {
        return v;
    }
    v=search_node(root->right, node);
    if (v[v.size()-1]->data==node)
    {
        return v;
    }*/
}

int LCA(binaryTree_node<int>*root, int node1, int node2)
{
    vector<binaryTree_node<int>*> v1;
    vector<binaryTree_node<int>*> v2;
    v1.push_back(root);
    v2.push_back(root);
    v1=search_node(v1, node1);
    v2=search_node(v2, node2);
    for (int i=v1.size()-1; i>=0;i--)
    {
        for (int j=v2.size()-1; j>=0;j--)
        {
            if (v1[i]->data==v2[j]->data)
            {
                return v1[i]->data;
            }
        }
    }
    return 0;
}
int main()
{
    binaryTree_node<int>*root=input_binTree1();
    print_binTree1(root);
    //v=search_node(v, 5);
    cout<<"LCA: "<< LCA(root, 5, 4)<<endl;
    /*cout<<"search vctor is: ";
    for (int i =0; i<v.size(); i++)
    {
        cout<<v[i]->data<<", ";
    }
    cout<<endl;
    return 0;
    */
}

