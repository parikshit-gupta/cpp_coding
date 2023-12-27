#include <iostream>
#include <cstdio>
using namespace std;
class A;
class B
{
    int y=10;

public:
    int add(A a);
    friend int add_2(B b, A a);
};

class A
{
    int x=20;

public:
    /*add is a function of class B and it has been friended in class A, this means that add can access
    all private and protected properties of class A and class B. */
    friend int B ::add(A a);
    
    friend int add_2(B b, A a);
};

int B:: add(A a)
    {
        return this->y + a.x;
    }

int add_2(B b, A a)
{
    return b.y + a.x;
}

int main()
{
    B b;
    A a;

    cout<<b.add(a)<<endl;
    return 0;
}