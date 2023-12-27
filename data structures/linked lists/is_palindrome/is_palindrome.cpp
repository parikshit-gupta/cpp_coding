#include<iostream>
#include<cstdio>
#include "D:\Development\cpp_coding\linked lists\print_input_functions\print_input_functions.cpp"
using namespace std;

// reversing linked list into a new LL
node **rev_LL1(node *head)
{
    node *temp = head;
    if (temp->next == NULL)
    {
        //node *arr1[2] = {NULL, NULL}; this is bad practice as scope of arr1 here is only the function rev_LL1
        //arr1 along with its elements will get deallocated as soon as the function ends

        static node *arr1[2] = {NULL, NULL};
        node *rev_head = new node(temp->data);
        arr1[0] = rev_head;
        arr1[1] = rev_head;
        return arr1;
    }

    node **arr = rev_LL1(temp->next);
    node *rev_head1 = arr[1];
    node *new_node = new node(temp->data);
    arr[1]->next = new_node;
    arr[1] = new_node;
    return arr;
}


// checking for palindrome

bool is_palindrome(node *head)
{
    node *temp = head;
    node **arr = rev_LL1(head);
    node *rev_head = arr[0];
    while (temp!= NULL)
    {
        if (temp->data != rev_head->data)
        {
            delete rev_head;
            return false;
        }
        temp=temp->next;
        rev_head=rev_head->next;
    }
    delete rev_head;
    return true;
}

int main()
{
    node *head =input();

    bool x=is_palindrome(head);
    if (x==true)
    {
        cout<<"the given LL is a palindrome."<<endl;
    }
    else
    {
        cout<<"the given LL is not a palindrome."<<endl;
    }

    delete head;
    return 0;
}