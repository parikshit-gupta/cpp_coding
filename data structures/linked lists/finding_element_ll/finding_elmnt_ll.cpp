#include<iostream>
#include<cstdio>
#include "D:\Development\cpp_coding\linked lists\print_input_functions\print_input_functions.cpp"
using namespace std;

// finding a element in a linked list given its value and returning its index
int find_elmnt(node*head, int elmnt, int c)
{
    node*temp=head;
    if (temp->data==elmnt)
    {
        return c;
    }

    if (temp==NULL)
    {
        return -1;
    }

    return find_elmnt(temp->next, elmnt, ++c);
}

int main()
{
    node *head =input();
    if (find_elmnt(head, 40, 0)==-1)
    {
        cout<< "element not found."<<endl;
    }

    else
    {
        cout<< "element found at index: "<< find_elmnt(head, 40, 0)<<endl;
    }

    delete head;
}