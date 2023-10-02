#include <iostream>
#include <cstdio>
#include "D:\Development\cpp_coding\linked lists\print_input_functions\print_input_functions.cpp"
using namespace std;

// updates the original linked list and reverses it without creating a new linked list (iteratively)
node *rev_LL(node *head)
{
    node *temp = head;
    node *temp1 = temp->next;
    temp->next = NULL;
    while (true)
    {
        if (temp1->next != NULL)
        {
            node *temp2 = temp1->next;
            temp1->next = temp;
            temp = temp1;
            temp1 = temp2;
        }
        else if (temp1->next == NULL)
        {
            temp1->next = temp;
            temp = temp1;
            break;
        }
    }

    return temp;
}

// updates the original linked list and reverses it without creating a new linked list (recursively)
node *rev_LL1(node *head)
{
    node *temp = head;
    if (temp->next == NULL)
    {
        return temp;
    }

    // this function returns the head of the reversed linked list
    head = rev_LL1(temp->next);
    node *temp1 = head;
    while (temp1->next != NULL)
    {
        temp1 = temp1->next;
    }
    temp1->next = temp;
    temp->next = NULL;
    return head;
}

//reversing a linked list without creating a new linked list (recursively)
node **rev_LL3(node *head)
{
    node *temp = head;
    if (temp->next == NULL)
    {
        //array created to store head and tail of the reversed linked list
        static node *arr[2]={temp, temp};
        return arr;
    }

    // this function returns the head and tail of the reversed linked list in an array
    node **arr1 = rev_LL3(temp->next);
    //arr[0]: head
    //arr[1]: tail of the effective reversed list
    arr1[1]->next=temp;
    temp->next = NULL;
    arr1[1]=temp;
    return arr1;
}

//reverses the LL withour creating a new list (recursively) T.C=O(n), S.C=O(n)
node *rev_LL4(node *head)
{
    node *temp = head;
    if (temp->next == NULL)
    {
        return temp;
    }

    // this function returns the head of the reversed linked list
    head = rev_LL1(temp->next);
    temp->next->next=temp;
    temp->next = NULL;
    return head;
}

// reversing linked list into a new LL (recursively)
node **rev_LL2(node *head)
{
    node *temp = head;
    if (temp->next == NULL)
    {
        // node *arr1[2] = {NULL, NULL}; this is bad practice as scope of arr1 here is only the function rev_LL1
        // arr1 along with its elements will get deallocated as soon as the function ends

        static node *arr1[2] = {NULL, NULL};
        node *rev_head = new node(temp->data);
        arr1[0] = rev_head;
        arr1[1] = rev_head;
        return arr1;
    }

    node **arr = rev_LL2(temp->next);
    node *rev_head1 = arr[1];
    node *new_node = new node(temp->data);
    arr[1]->next = new_node;
    arr[1] = new_node;
    return arr;
}

// printing reverse of a given linked list recursively
void print_rev(node *head)
{
    node *temp = head;
    if (temp->next == NULL)
    {
        cout << temp->data << endl;
        return;
    }

    print_rev(temp->next);
    cout << temp->data << endl;
}

int main()
{   /*
    node *head = input();
    cout << "LL before reversal: " << endl;
    print(head);
    node **arr = rev_LL2(head);
    node *new_head=arr[0];
    cout << "LL after reversal: " << endl;
    print(new_head);
    delete new_head;
    delete head;
    */

   /*
   node *head=input();
   cout<<"linked list before reversal: "<<endl;
   print(head);
   node *new_head=rev_LL1(head);
   cout<<"linked list after reversal: "<<endl;
   print(new_head);
   delete new_head;
   */

  /*
   node * head = input();
   cout<<"linked list before reversal: "<<endl;
   print(head);
   node**arr=rev_LL3(head);
   cout<<"linked list after reversal: "<<endl;
   print(arr[0]);
   delete arr[0];
   */

   node * head = input();
   cout<<"linked list before reversal: "<<endl;
   print(head);
   node *rev_head=rev_LL4(head);
   cout<<"linked list after reversal: "<<endl;
   print(rev_head);
   delete rev_head;

   return 0;
}