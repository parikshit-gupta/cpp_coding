#include<iostream>
using namespace std;
template <typename T>
class node
{
public:
    T data;
    node<T> *next;

    node(T data)
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

template <typename T>
class stack_LL
{
private:
    //node is a datatype
    //since the class node is a template we must pass the template parameter wherever we use 'node'
    /*here we are specifying the template parameter of node as the parameter passed to the stack_LL 
    template parameter*/
    node<T> *head;
    int size;

public:
    stack_LL()
    {
        head = NULL;
        size = 0;
    }

    stack_LL(T data)
    {
        head = new node<T>(data);
        size = 1;
    }

    void push(T data)
    {
        node<T> *temp = head;
        head = new node<T>(data);
        head->next = temp;
        size++;
    }

    T pop()
    {
        if (head == NULL)
        {
            cout<<"stack is empty"<<endl;
            return -1;
        }

        node<T> *temp = head->next;
        int data = head->data;
        head->next = NULL;
        delete head;
        head = temp;
        size--;
        return data;
    }

    T top()
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

    ~stack_LL()
    {
        delete head;
    }
};