#include <iostream>
#include <cstdio>
#include "D:\Development\cpp_coding\linked lists\print_input_functions\print_input_functions.cpp"
using namespace std;

// lenght of a LL recursively
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

node *append_from_last(node *head, int N)
{
    node *temp = head;
    node *temp1;
    int len = len_ll(temp);
    cout<< len<<endl;
    int c = 0;
    while (c <= len)
    {
        if (c==len-1)
        {
            temp->next = head;
            temp=temp->next;
            c++;
        }

        if (c == len - N-1)
        {
            temp1 = temp->next;
            temp->next = NULL;
            temp=temp1;
            c++;
        }
        else
        {
            temp = temp->next;
            c++;
        }
    }

    return temp1;
}

int main()
{
    node *head =input();
    cout<<"before appending: "<<endl;
    print(head);
    node *new_head=append_from_last(head, 2);
    cout<<"after appending: "<< endl;
    print(new_head);

    delete new_head;
    
    return 0;
}