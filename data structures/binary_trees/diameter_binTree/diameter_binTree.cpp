#include<iostream>
#include<cstdio>
#include "D:\Development\cpp_coding\data structures\binary_trees\binary_trees1\binary_trees1.h"
using namespace std;

int height(binaryTree_node<int>*root)
{
    if (root==NULL)
    {
        return 0;
    }

    int left_height=height(root->left);
    int right_height=height(root->right);
    return 1+max(left_height,right_height);
}

int diameter(binaryTree_node<int>*root)
{
    if (root==NULL)
    {
        return 0;
    }

    int lhrh=height(root->left)+height(root->right);
    int ld=diameter(root->left);
    int rd=diameter(root->right);
    return max(lhrh,max(ld,rd));

}

int* better_diameter(binaryTree_node<int>*root)
{
    //arr[0]=height of current node
    //arr[1]=diameter of current node
    //arr_left: array containing height and dia of left tree
    //arr_right: array containing height and dia of right tree
    int *arr=new int[2];
    if (root==NULL)
    {
        arr[0]=0;
        arr[1]=0;
        return arr;
    }
    int*arr_left=better_diameter(root->left);
    int *arr_right=better_diameter(root->right);
    arr[0]=1+max(arr_left[0],arr_right[0]);
    arr[1]=max(arr_left[0]+arr_right[0], max(arr_left[1], arr_right[1]));
    delete []arr_left;
    delete []arr_right;
    return arr;
}
int main()
{
    binaryTree_node<int>*root=input_binTree1();
    cout<< endl <<"diameter: "<<diameter(root)<<endl;
    int *arr=better_diameter(root);
    cout<<"better diameter: "<<arr[1]<<endl;
    delete []arr;
    return 0;
}