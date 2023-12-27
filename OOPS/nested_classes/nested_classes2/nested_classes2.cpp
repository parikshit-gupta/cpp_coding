#include <iostream>
#include <cstdio>
using namespace std;

class A
{
    int a;

public:
    A(int a)
    {
        this->a = a;
    }
    int get_a()
    {
        return a;
    }
};

class B
{

    int b;

public:
    B(int b)
    {
        this->b = b;
    }
    int get_b()
    {
        return b;
    }
};

class C
{
    A a1;
    B b1;
    int c;

public:
    C(int a, int b) : a1(a), b1(b)
    {
        this->c = a1.get_a() + b1.get_b();
    }
    int get_c()
    {
        return c;
    }
};

int main()
{
    C c1(20, 200);
    cout << "hemlom" << endl;
    cout << c1.get_c() << endl;
    return 0;
}