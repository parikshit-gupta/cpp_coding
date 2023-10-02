#include <iostream>
#include <cstdio>
#include "D:\Development\cpp_coding\linked lists\print_input_functions\print_input_functions.cpp"
using namespace std;

// eliminating duplicates from a LL
void eliminate_duplicates(node *head)
{
    node *temp = head;
    int c = 0;
    while (temp->next != NULL)
    {
        if ((temp->data == (temp->next)->data) && (temp->next)->next != NULL)
        {
            node *temp1 = temp->next;
            temp->next = temp->next->next;
            temp1->next = NULL;
            delete temp1;
        }

        if ((temp->data == (temp->next)->data) && (temp->next)->next == NULL)
        {
            delete temp->next;
            temp->next = NULL;
            break;
        }

        temp = temp->next;
        c++;
    }
    return;
}

int main()
{
    node *head = input();
    cout << "linked list before elimination: " << endl;
    print(head);
    eliminate_duplicates(head);
    cout << "linked list after elimination: " << endl;
    print(head);
    delete head;
    return 0;
}