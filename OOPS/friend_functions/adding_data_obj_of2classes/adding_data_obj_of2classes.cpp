#include<iostream>
#include<cstdio>
using namespace std;

class B;

class A
{
    private: 
    int data;

    public:
    void set_val(int x)
    {
        data=x;
    }

    friend int add(A a, B b);
};

class B
{
    private:
    int data;

    public:
    void set_val(int x)
    {
        data=x;
    }

    friend int add(A a, B b);
};

int add(A a, B b)
{
    return a.data+b.data;
}

int main()
{
    A a;
    a.set_val(10);
    B b;
    b.set_val(100);
    int c=add(a,b);
    cout<< c<<endl;
    return 0;
}