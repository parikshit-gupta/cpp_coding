#include<iostream>
#include<cstdio>
#include "D:\Development\cpp_coding\data structures\BST\class_BST\BST1\BST1.h"
using namespace std;

int main()
{
    BST bst1;
    int k=10;
    //cout<<bst1.search_node(k)<<endl;
    cout<<"before: "<<endl;
    bst1.print_binTree1();
    bst1.delete_node(k);
    //bst1.insert(k);
    cout<<"after: "<<endl;
    bst1.print_binTree1();
    return 0;
}

//8 1 4 1 10 1 2 1 6 1 9 1 11 0 0 0 1 7 0 0 0 0 0 08 1 4 1 10 1 2 1 6 1 9 1 11 0 0 0 1 7 0 0 0 0 0 0
//8 0 1 10 1 9 1 11 0 0 0 0