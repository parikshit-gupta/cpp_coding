#include <iostream>
#include <cstdio>
#include "D:\Development\cpp_coding\linked lists\print_input_functions\print_input_functions.cpp"
using namespace std;



// deallocating memory from heap
void del_LinkList(node *head)
{
    node *temp = head;
    if (temp->next == NULL)
    {
        delete temp;
        cout << "linked list deleted." << endl;
        return;
    }

    temp = temp->next;
    // delete calls the destructor of the object;
    delete head;
    head = temp;
    del_LinkList(head);
    return;
}

int main()
{
    /*
    node n1(10);
    node n2(20);
    n1.next=&n2;
    //n1.~node();
    //cout<<n1.data<<endl;

    node * n3=new node(30);
    node *n4=new node (40);
    n3->next=n4;
    delete n3;
    //delete n4;*/

    node *head = input();
    print(head);
    delete head;
    return 0;
}