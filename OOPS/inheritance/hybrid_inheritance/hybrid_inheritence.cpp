#include <iostream>
#include <cstdio>
using namespace std;

class A
{
public:
    A()
    {
        cout << "constructor of A" << endl;
    }

    void print()
    {
        cout << "A" << endl;
    }
};

class B : public A
{
public:
    B()
    {
        cout << "constructor of B" << endl;
    }

    void print()
    {
        cout << "B" << endl;
    }
};

class C : public A
{
public:
    C()
    {
        cout << "constructor of C" << endl;
    }

    void print()
    {
        cout << "C" << endl;
    }
};

class D : public B, public C
{
public:
    D()
    {
        cout << "constructor of D" << endl;
    }

    void print()
    {
        cout << "D" << endl;
    }
};

int main()
{
    D d;
    d.B::print();
    d.C::print();
    d.print();
    return 0;
}