#include <iostream>
#include <cstdio>
using namespace std;

class A
{
public:
    A(int a)
    {
        cout << "constructor of A: " << a <<endl;
    }

    void print()
    {
        cout << "A" << endl;
    }
};

//B and C share a single copy of thew base class A, prevents data redundancy
class B : virtual public A
{
public:
    B():A(3)
    {
        cout << "constructor of B" << endl;
    }

    void print()
    {
        cout << "B" << endl;
    }
};

//declaring A as a virtual base class of C does not create a seperate copy of A when constructor of C is called.
class C : public virtual A
{
public:
    C():A(4)
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
    D(int x):A(x)
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
    D d(5);
    d.A::print();
    d.B::print();
    d.C::print();
    d.print();
    return 0;
}