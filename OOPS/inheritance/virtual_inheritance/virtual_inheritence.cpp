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
    B(int x):A(x)
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

    D(int x, int y):A(x),B(y)
    {
        cout << "constructor of D" << endl;
    }

    void print()
    {
        cout << "D" << endl;
    }

    /*
    this would give an error as constructor of D calls the constructor of A itself, and default constructor of A doesnt exist.
    and neither one of the constructors of  B and C calls the constructor of A
    D(int y):B(y)
    {
        cout << "constructor of D" << endl;
    }

    void print()
    {
        cout << "D" << endl;
    }*/
};

int main()
{
    B b(100);
    D d(5,10);
    d.A::print();
    d.B::print();
    d.C::print();
    d.print();
    return 0;
}