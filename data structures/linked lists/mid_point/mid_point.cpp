#include <iostream>
#include <cstdio>
#include "D:\Development\cpp_coding\linked lists\print_input_functions\print_input_functions.cpp"
using namespace std;

node *mid_point(node *head)
{
    //taking two pointers and updating first by one index while the other by two indices per iteration
    //when the second one reaches the end the first one will be pointing at the middle element of the LL
    node *temp = head;
    node *temp1 = temp->next;
    while (true)
    {
        if (temp1 == NULL)
        {
            return temp;
        }
        else if (temp1->next==NULL)
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

int main()
{
    node *head = input();
    print(head);
    node *mid = mid_point(head);

    cout << "mid-point of linked list is: " << mid->data << endl;
    delete head;
    return 0;
}