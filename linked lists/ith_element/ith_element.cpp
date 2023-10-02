#include <iostream>
#include <cstdio>
#include "D:\Development\cpp_coding\linked lists\print_input_functions\print_input_functions.cpp"
using namespace std;

//finding the ith element in a linked list
int find_index(node * head, int index)
{
    int c=0;
    node *temp =head;
    while(c!=index)
    {
        c++;
        temp = temp ->next;
        if (temp==NULL)
        {
            cout<< "index out of range"<<endl;
            return -1;
        }

    }
    return temp->data;
}

int main()
{
    node * head=input();
    print(head);
    cout<< "the required data: "<<find_index(head, 3)<<endl;

    delete head;
    return 0;
}