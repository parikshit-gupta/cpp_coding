#include <iostream>
#include <cstdio>
#include <climits>
#include "D:\Development\cpp_coding\data structures\binary_trees\binary_trees1\binary_trees1.h"
using namespace std;

/*converting a BST to a sorted arr/vector using a single function increases the time complexity and
space complexity significantly*/
vector<int> inorder(binaryTree_node<int> *root) 
{
    vector<int> v;
    if(root==NULL)
    {
        return v;
    }
    v=inorder(root->left);
    v.push_back(root->data);
    vector<int> v1=inorder(root->right);
    int i=0;
    while(i<v1.size())
    {
        v.push_back(v1[i]);
        i++;
    }
    return v;
}

/*inorder1 and BSTtoVector combined provide a much more efficient solution to converting a BST in a sorted 
array/vector*/
void inorder1(binaryTree_node<int>*root, vector<int>&v)
{
    /*passing vector by reference eliminates the need to return a vector*/
    if (root==NULL)
    {
        return;
    }
    inorder1(root->left, v);
    v.push_back(root->data);
    inorder1(root->right, v);
}
vector<int> BSTtoVector(binaryTree_node<int>*root)
{
    vector<int> v;
    inorder1(root, v);
    return v;
}

//checking for BST using inorder approach
bool check_BST1(binaryTree_node<int>*root)
{
    if (root==NULL)
    {
        return true;
    }

    vector<int> v= BSTtoVector(root);
    for (int i=0; i<v.size()-1;i++)
    {
        if (v[i]>v[i+1])
        {
            return false;
        }
    }
    return true;
}

bool check_BST(binaryTree_node<int> *root, int *arr)
{
    //base case incase NULL is passed as root
    if (root == NULL)
    {
        return true;
    }

    //case for leaf node
    if (root->left == NULL && root->right == NULL)
    {
        //since min max for leaf nodes make no sense
        arr[0]=root->data;
        arr[1]=root->data;
        return true;
    }

    bool left_BST = check_BST(root->left, arr);
    int left_min = arr[0];
    int left_max = arr[1];

    if (!left_BST)
    {
        return false;
    }

    /*resetting the array before moving onto the right branch is important or else we would end up comparing
    the right branch with min and max of the left branch*/
    arr[0]=INT_MAX;
    arr[1]=INT_MIN;
    bool right_BST = check_BST(root->right, arr);
    int right_min = arr[0];
    int right_max = arr[1];

    if ((root->data >= left_max && root->data <= right_min) && right_BST && left_BST)
    {
        arr[0] = min(root->data, min(left_min, right_min));
        arr[1] = max(root->data, max(left_max, right_max));
        return true;
    }
    return false;

    // arr[0]: min element of left or right tree of root
    // arr[1]: max element of left or right tree of root
    /*also the root must be greater than all the elements of left tree, simultaneously the root must be less
    than all the elements of right tree.
    thus we need to keep track of the max element from the left tree and the min element from the right tree*/
    
    /*
    if (root == NULL)
    {
        return true;
    }
    if (root->left == NULL && root->right == NULL)
    {
        if (root->data < arr[0])
        {
            arr[0] = root->data;
        }
        if (root->data >= arr[1])
        {
            arr[1] = root->data;
        }
        return true;
    }

    if (root->data < arr[0])
    {
        arr[0] = root->data;
    }
    if (root->data >= arr[1])
    {
        arr[1] = root->data;
    }

    bool c = 0;
    bool left = check_BST(root->left, arr);
    /*arr[1] right now is the max element of the left branch of root*/
    /*
    if (root->data >= arr[1])
    {
        c = 1;
    }
    if (left == 0 || c == 0)
    {
        return false;
    }

    bool d = 0;

    bool right = check_BST(root->right, arr);
    /*arr[0] right now is the min element of the right branch of root*/
    /*
    if (root->data <= arr[0])
    {
        d = 1;
    }
    if (right == 0 || d == 0)
    {
        return false;
    }

    return true;
    */
}

int main()
{
    binaryTree_node<int> *root = new binaryTree_node<int>(2);
    root->left=new binaryTree_node<int>(2);
    root->right=new binaryTree_node<int>(2);
    int arr[2] = {INT_MAX, INT_MIN};
    cout << "is_BST: " << check_BST(root, arr) << endl;
    cout << "is_BST1: " << check_BST1(root) << endl;
    return 0;
}
// 3 1 5 -1 2 -1 -1 -1 -1
// 3 1 1 1 5 0 1 2 0 0 0 0