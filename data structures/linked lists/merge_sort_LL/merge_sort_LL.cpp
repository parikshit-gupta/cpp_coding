#include <iostream>
#include <cstdio>
#include "D:\Development\cpp_coding\linked lists\print_input_functions\print_input_functions.cpp"
using namespace std;

//sorting a linked list using merge sort and returning the new head

// merging 2 sorted linked lists into a third linked list
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
            //deleting head1 and head2 helps in deleting the interim linked lists formed in the merge sort funcition
            //although this may not be required for every function
            delete head1;
            delete head2;
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
            //deleting head1 and head2 helps in deleting the interim linked lists formed in the merge sort funcition
            //although this may not be required for every function
            delete head1;
            delete head2;
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

//finding mid-point of a linked list
node *mid_point(node *head)
{
    node *temp = head;
    node *temp1 = temp->next;
    while (true)
    {
        if (temp1 == NULL)
        {
            return temp;
        }
        else if (temp1->next == NULL)
        {
            return temp;
        }
        else
        {
            temp = temp->next;
            temp1 = temp1->next->next;
        }
    }
}

//sorting a linked list using merge sort, returns the sorted list, while destroys the original one
node *merge_sort(node *head)
{
    node *temp = head;
    if (temp->next == NULL)
    {
        return temp;
    }

    node *mid = mid_point(temp);
    node *mid_next = mid->next;
    mid->next = NULL;
    temp = merge_sort(temp);
    mid_next = merge_sort(mid_next);

    //merge_LL creates a new sorted linked list
    temp = merge_ll(temp, mid_next);

    return temp;
}

int main()
{
    node *head=input();
    cout<<"original list before calling merge sort: "<<endl;
    print(head);
    node *sorted=merge_sort(head);
    //cout<<"original list after calling merge sort: "<<endl;
    cout<<"sorted list: "<<endl;
    print(sorted);

    delete sorted;
    return 0;
}