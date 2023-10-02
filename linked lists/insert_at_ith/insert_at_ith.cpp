#include <iostream>
#include <cstdio>
#include "D:\Development\cpp_coding\linked lists\print_input_functions\print_input_functions.cpp"
using namespace std;

// lenght of a node recursively
int len_ll(node *head)
{
    node *temp = head;
    if (temp->next == NULL)
    {
        return 1;
    }

    temp = temp->next;
    return 1 + len_ll(temp);
}

// inserting a node recursively
void insert_elmnt(node *head, int index, int input, int c)
{

    node *temp = head;
    if (c == index - 1 && temp != NULL)
    {
        node *n = new node(input);
        node *temp1 = temp->next;
        temp->next = n;
        n->next = temp1;
        return;
    }

    else if (temp == NULL)
    {
        return;
    }
    insert_elmnt(temp->next, index, input, ++c);
}

// deleting a node recursively
void del_elmnt(node *head, int index, int c)
{
    node *temp = head;
    if (c == index - 1 && temp->next != NULL)
    {
        // temp1 points to the node with index 'index'
        node *temp1 = (temp->next);
        // putting adress of index+1 node in next of index-1 node
        temp->next = temp1->next;
        // making next of node to be deleted(index node) NULL to call its destructor without deleting the whole LL
        temp1->next = NULL;
        delete temp1;
        return;
    }
    else if (temp->next == NULL)
    {
        return;
    }

    del_elmnt(temp->next, index, ++c);
}

int main()
{
    node *head = input();
    /*
    cout<<"linked list before insertion:"<< endl;
    print(head);
    cout << "lenght of the linked list before insertion is: " << len_ll(head) << endl;
    insert_elmnt(head, 3, 100, 0);
    cout<<"linked list after insertion:"<< endl;
    print(head);
    cout << "lenght of the linked list after insertion is: " << len_ll(head) << endl;
    */

    cout << "linked list before deletion:" << endl;
    print(head);
    del_elmnt(head, 10, 0);
    cout << "linked list after deletion:" << endl;
    print(head);

    delete head;
    return 0;
}