#include<iostream>
#include<cstdio>
using namespace std;
template <typename T> class stack
{
    private:
    T *arr;
    int size;
    int max_size;
    
    public: 
    stack(int max_size)
    {
        this->max_size = max_size + 1;
        arr = new T[max_size];
        arr[0]=0;
        printf("hello\n");
        // just to initialise arr[0] so that it does not store garbage values
        //arr[0] = INT_MIN;
    }

    void push(T data)
    {
        if (size == max_size)
        {
            printf("stack full\n");
            return;
        }
        arr[size+1] = data;
        size++;
        return;
    }

    T pop()
    {
        if (size == 0)
        {
            printf("stack empty\n");
            return arr[size];
        }
        T top = arr[size];
        size--;
        return top;
    }

    T top()
    {
        if (size == 0)
        {
            printf("stack empty\n");
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
        printf("stack deleted\n");
    }

};