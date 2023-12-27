#include<iostream>
#include<cstdio>
using namespace std;

class A
{
    public:
    A()
    {

    }
    A(const A &a)
    {

    }
    public:
    ~A()
    {
        cout<<"A destroyed."<<endl;
    }

};

class B : public A
{
    public:
    ~B()
    {
        cout<<"B destroyed."<<endl;
    }

};

class A1
{
    public:
    virtual ~A1()
    {
        cout<<"A1 destroyed."<<endl;
    }

};

class B1 : public A1
{
    public:
    ~B1()
    {
        cout<<"B1 destroyed."<<endl;
    }

};


int main()
{
    A *ptr =new B();
    delete ptr;
    /*since a pointer to the base class is used to point to an object of derived class delete ptr, call the
    destructor of the base class as it happens with other functions.
    but if the destructor fo the base class is declared as virtual then a v-table will be created
    which would ensure that upon calling ptr destructor of B is called first.*/
    A1*ptr1=new B1();
    delete ptr1;
    return 0;
}