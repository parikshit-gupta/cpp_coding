#include <iostream>
#include <cstdio>
#include <climits>
using namespace std;

//stack implementation using arrays 

class stack
{
private:
    int max_size;
    int *arr;
    int size = 0;

public:
    stack()
    {
        max_size=5;
        arr = new int[max_size+1];
        // just to initialise arr[0] so that it does not store garbage values
        arr[0] = INT_MIN;
    }

    void push(int data)
    {
        if (size == max_size)
        {
            int *arr1=new int[2*max_size+1];
            for (int i=0;i<max_size;i++)
            {
                arr1[i]=arr[i];
            }
            max_size=2*max_size;
            delete[] arr;
            arr=arr1;
        }
        arr[size+1] = data;
        size++;
        return;
    }

    int pop()
    {
        if (size == 0)
        {
            cout << "stack empty." << endl;
            return arr[size];
        }
        int top = arr[size];
        size--;
        return top;
    }

    int top()
    {
        if (size == 0)
        {
            cout << "stack empty." << endl;
            return arr[size];
        }
        return arr[size];
    }

    int curr_size()
    {
        return size;
    }

    bool is_empty()
    {
        if (size == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    ~stack()
    {
        delete[] arr;
        cout << "stack deleted." << endl;
    }
};

int main()
{
    stack s1;
    s1.push(10);
    cout<<s1.curr_size()<<endl;
    s1.push(20);
    cout<<s1.curr_size()<<endl;
    s1.push(30);
    cout<<s1.curr_size()<<endl;
    s1.push(40);
    cout<<s1.curr_size()<<endl;
    s1.push(50);
    cout<<s1.curr_size()<<endl;
    s1.push(70);
    cout<<s1.curr_size()<<endl;
    s1.push(60);
    cout<<s1.curr_size()<<endl;
    cout<<s1.pop()<<endl;
    cout<<s1.top()<<endl;
    return 0;
}