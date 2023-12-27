#include <iostream>
#include <cstdio>
using namespace std;

class queue
{
    int size;
    int max_size;
    int next_index;
    int first_index;
    int *arr;

public:
    queue(int max_size)
    {
        this->max_size = max_size;
        arr = new int[max_size];
        size = 0;
        next_index = 0;
        first_index = -1;
    }

    void enqueue(int data)
    {
        if (size == max_size)
        {
            cout << "queue full." << endl;
            return;
        }
        /*
        if (next_index == max_size)
        {
            next_index = 0;
        }
        arr[next_index] = data;
        size++;
        if (size == 1)
        {
            first_index = next_index;
        }
        next_index++;*/

        //a better way to do the above is:
        arr[next_index]=data;
        size++;
        if (size==1)
        {
            first_index=next_index;
        }
        next_index=(next_index+1)%max_size;
    }

    int dequeue()
    {
        if (size == 0)
        {
            cout<<"queue empty."<<endl;
            return -1;
        }

        int front=arr[first_index];
        first_index=(first_index+1)%max_size;
        size --;
        return front;
    }

    int front()
    {
        if (size ==0)
        {
            cout<<"queue empty."<<endl;
            return -1;
        }
        return arr[first_index];
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
        delete []arr;
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