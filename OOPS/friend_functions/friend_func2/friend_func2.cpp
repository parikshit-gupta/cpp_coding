#include <iostream>
using namespace std;
class A;
class B
{
    int b;

public:
    B(int b)
    {
        this->b = b;
    }

    int add(A a1);
};

class A
{
    int a;

public:
    A(int a)
    {
        this->a = a;
    }
    friend int B::add(A a);
};

int B::add(A a1)
{
    int c = a1.a + this->b;
    return c;
}

int main()
{

    return 0;
}