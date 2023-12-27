#include <iostream>
#include <cstdio>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int data)
    {
        this->data = data;
        next = NULL;
    }

    ~node()
    {
        if (next!=NULL)
        {
            delete next;
        }
        cout<<data<<" : object destroyed."<<endl;
    }
};

class stack_LL
{
private:
    node *head;
    int size;

public:
    stack_LL()
    {
        head = NULL;
        size = 0;
    }

    stack_LL(int data)
    {
        head = new node(data);
        size = 1;
    }

    void push(int data)
    {
        node *temp = head;
        head = new node(data);
        head->next = temp;
        size++;
    }

    int pop()
    {
        if (head == NULL)
        {
            cout<<"stack is empty"<<endl;
            return -1;
        }

        node *temp = head->next;
        int data = head->data;
        head->next = NULL;
        delete head;
        head = temp;
        size--;
        return data;
    }

    int top()
    {
        return head->data;
    }

    int curr_size()
    {
        return size;
    }

    bool is_empty()
    {
        return head == NULL;
    }

    /*when the destructor of a stack_LL object is called 'delete head' will act as a 
    recursive call to the destructor of the nodes created in heap memory and will delete the whole stack*/
    
    /*no explicit delete command has to be mentioned to delete the stack because the stack object is 
    created in stack memory and its destructor is called implicitly by the compiler 
    as soon as it goes out of scope*/

    /*unlike in linked lists, there was no object in linked lists created on stack memory, thus the need 
    to explicitly use the delete command on the head pointer*/
    ~stack_LL()
    {
        delete head;
    }
};

int main()
{
    stack_LL s1;
    cout<<s1.is_empty()<<endl;
    cout<<s1.curr_size()<<endl;
    stack_LL s2(10);
    s2.push(20);
    cout<<s2.pop()<<endl;
    s2.push(30);
    cout<<s2.curr_size()<<endl;
    return 0;
}