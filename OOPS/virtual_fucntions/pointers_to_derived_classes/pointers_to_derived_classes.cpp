#include<iostream>
#include<cstdio>
using namespace std;

class A
{
    int a;
    public:
    A(int a)
    {
        this->a=a;
    }

    void show()
    {
        cout<<"a:"<<a<<endl;
    }
};

class B: public A
{
    int b;
    public:
    B(int a,int b): A(a)
    {
        this->b=b;
    }

    void show()
    {
        cout<<"b:"<<b<<endl;
    }

};

int main()
{
    A a(10);
    B b(20, 30);
    A *ptr=&a;
    ptr->show();
    ptr=&b;
    b.show();
    ptr->show();
    return 0;
}