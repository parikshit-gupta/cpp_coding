#include<cstdio>
#include<iostream>

#include"D:\Development\cpp_coding\data structures\binary_trees\binary_trees1\binary_trees1.h"
using namespace std;

class pair1
{
    public:
    int dia;
    int ht;
    pair1()
    {
        dia=0;
        ht=0;
    }
};

pair1 diameter(binaryTree_node<int> *root)
{
    if(root==NULL)
    {
        pair1 p1;
        p1.dia=0;
        p1.ht=0;
        return p1;
    }

    pair1 left_p=diameter(root->left);
    pair1 right_p=diameter(root->right);

    pair1 p1;

    p1.ht=max(left_p.ht, right_p.ht)+1;
    p1.dia=max(left_p.dia, max(right_p.dia, left_p.ht+right_p.ht));
    return p1;
}

int main()
{
    binaryTree_node<int>*root=input_binTree1();
    print_binTree1(root);
    cout<<"diameter: "<<diameter(root).dia<<endl;
    cout<<"height: "<<diameter(root).ht<<endl;
    return 0;
}