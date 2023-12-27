#include <iostream>
#include <cstdio>
using namespace std;

class queue
{
    int size;
    int max_size;
    int *arr;

public:
    queue(int max_size)
    {
        this->max_size = max_size;
        arr = new int[max_size+1];
        arr[0] = -1;
        size = 0;
    }

    void enqueue(int data)
    {
        if (size == max_size)
        {
            cout << "queue full." << endl;
            return;
        }
        size++;
        arr[size] = data;
    }

    int front()
    {
        if (size == 0)
        {
            cout << "queue empty." << endl;
            return -1;
        }
        return arr[1];
    }

    int curr_size()
    {
        return size;
    }

    bool is_empty()
    {
        return size == 0;
    }

    int dequeue()
    {
        if (size == 0)
        {
            cout << "queue empty." << endl;
            return -1;
        }
        int front = arr[1];
        for (int i = 1; i < size; i++)
        {
            arr[i]=arr[i+1];
        }
        size--;
        return front;
    }

    ~queue()
    {
        delete[] arr;
        cout<<"queue deleted."<<endl;
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
    return 0;
}