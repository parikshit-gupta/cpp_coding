#include<iostream>
using namespace std;

class A
{
    int x=10;
    public:
    void show()
    {
        cout<<x<<endl;
    }
};

class B:public A
{
    int y=20;
    public:
    void show()
    {
        cout<<y<<endl;
    }
};

int main()
{
    B b;
    b.show();
    b.A::show();
    return 0;
}