#include <iostream>
#include <cstdio>
#include "D:\Development\cpp_coding\linked lists\print_input_functions\print_input_functions.cpp"
using namespace std;

node *merge_ll(node *head1, node *head2)
{
    node *head3 = new node(0);
    node *temp1 = head1;
    node *temp2 = head2;
    node *temp3 = head3;

    while (true)
    {
        //if the first linked list is shorte than the other
        if (temp1 == NULL)
        {
            while (temp2 != NULL)
            {
                temp3->data = temp2->data;
                if (temp2->next != NULL)
                {
                    node *new_node = new node(0);
                    temp3->next = new_node;
                    temp3 = new_node;
                }
                temp2 = temp2->next;
            }

            return head3;
        }

        //if the second linked list is shorter than the first.
        else if (temp2 == NULL)
        {
            while (temp1 != NULL)
            {
                //temp3 updates to the "data"member of a pre-existing node
                temp3->data = temp1->data;
                //if next of temp1 is NULL the no need to create a new node as temp 1 has come to an end.
                if (temp1->next != NULL)
                {
                    node *new_node = new node(0);
                    temp3->next = new_node;
                    temp3 = new_node;
                }
                temp1 = temp1->next;
            }

            return head3;
        }
        else
        {
            //comparing the elements of the 2 linked lists and creating a new linked list accordingly
            if (temp1->data > temp2->data)
            {
                temp3->data = temp2->data;
                temp2 = temp2->next;
                node *new_node = new node(0);
                temp3->next = new_node;
                temp3 = new_node;
            }

            else if (temp1->data < temp2->data)
            {
                temp3->data = temp1->data;
                temp1 = temp1->next;
                node *new_node = new node(0);
                temp3->next = new_node;
                temp3 = new_node;
            }

            else if (temp1->data == temp2->data)
            {
                temp3->data = temp1->data;
                temp1 = temp1->next;
                temp2 = temp2->next;
                node *new_node = new node(0);
                temp3->next = new_node;
                temp3 = new_node;
            }
        }
    }
}

int main()
{
    cout << "first linked list: " << endl;
    node *head1 = input();

    cout << "second linked list: " << endl;
    node *head2 = input();

    node *merged_head = merge_ll(head1, head2);
    cout << "merged linked list: " << endl;
    print(merged_head);

    delete head1;
    delete head2;
    delete merged_head;

    return 0;
}