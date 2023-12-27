#include<iostream>
#include<cstdio>
using namespace std;

class node
{
    public:
    int data;
    node *next;

    node ()
    {
        data=-1;
        next=NULL;
    }
    node(int data)
    {
        this->data=data;
        next=NULL;
    }

    ~node()
    {
        if(next!=NULL)
        {
            delete next;
        }
        cout<<data<<" : object destroyed."<<endl;
    }



};

class queue
{
    node *head;
    node *tail;
    int size;

    public:

    queue()
    {
        size =0;
        head =new node;
        tail=head;
    }

    queue(int data)
    {
        head=new node(data);
        tail=head;
        size=1;

    }

    void enqueue(int data)
    {
        node *temp=new node(data);
        tail->next=temp;
        tail=temp;
        size++;
    }

    int dequeue()
    {
        node*temp=head->next;
        int data=head ->data;
        head->next=NULL;
        delete head;
        head=temp;
        size--;
        return data;
    }

    int front()
    {
        return head->data;
    }

    int curr_size()
    {
        return size;
    }

    bool is_empty()
    {
        return size==0;
    }

    ~queue()
    {
        delete head;
    }

};

int main()
{
    queue q1(5);
    q1.enqueue(1);
    q1.enqueue(2);
    q1.enqueue(3);
    q1.enqueue(4);
    q1.enqueue(5);
    q1.enqueue(6);
    cout << q1.curr_size() << endl;
    cout << q1.dequeue() << endl;
    cout << q1.front() << endl;
    cout << q1.curr_size() << endl;
    cout << q1.is_empty() << endl;
    q1.enqueue(7);
    cout<<q1.front()<<endl;
    q1.enqueue(8);
    cout<<q1.dequeue()<<endl;
    cout<<q1.front()<<endl;
    cout << q1.curr_size() << endl;
    return 0;
}
