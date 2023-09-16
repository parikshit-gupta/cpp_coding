#include<iostream>
#include<cstdio>
using namespace std;

class dynamicArray
{
    int *data;
    int next_index;
    int capacity;

    public:
    //default constructor
    dynamicArray()
    {
        data = new int [5];
        next_index=0;
        capacity=5;
    }

    //copy constructor
    //initalising wiht  another object involves shallow copy with the in-built copy constructor
    //thus we need to give our own copy constructor to implement deep copy
    dynamicArray(const dynamicArray &arr)
    {
        next_index=arr.next_index;
        capacity=arr.capacity;

        data = new int[arr.capacity];
        for (int i=0; i<arr.next_index;i++)
        {
            data[i]=arr.data[i];
        }
    }

    //copy assignment operator
    //this also implements shallow copy by default so we need to fix it
    void operator=(dynamicArray const &arr)
    {
        next_index=arr.next_index;
        capacity=arr.capacity;

        data = new int[arr.capacity];
        for (int i=0; i<arr.next_index;i++)
        {
            data[i]=arr.data[i];
        }
    }
    // adding element at the last

    void add(int element)
    {
        if (next_index==capacity)
        {
            int *new_data=new int[2*capacity];
            for (int i=0; i<next_index;i++)
            {
                new_data[i]=data[i];
            }
            delete [] data;
            data=new_data;
            capacity*=2;
        }
        data[next_index]=element;
        next_index++;
    }

    int getElement(int index)
    {
        return data[index];
    }

    void add(int index, int element)
    {
        if (index< next_index)
        {
            data[index]=element;
        }
        else if (index==next_index)
        {
            add(element);
        }

        else 
        {
            cout<< "index out of range."<< endl;
            return;
        }
    }

    //display function

    void display()
    {
        for (int i=0; i<next_index;i++)
        {
            cout<< data[i]<< ' ';
        }
        cout<<endl;
    }

    //destructor
    ~dynamicArray()
    {
        delete []data;
    }

};

int main()
{
    dynamicArray arr;

    arr.add(10);
    arr.add(20);
    arr.add(30);
    arr.add(40);
    arr.add(50);
    arr.add(60);

    arr.display();
    arr.add(3, 100);

    dynamicArray arr2(arr);
    dynamicArray arr3;
    arr3=arr2;

    arr.display();
    arr2.display();
    arr3.display();
    return 0;
}