#include<iostream>
#include<cstdio>
using namespace std;

class A
{
    int a=10;
    public:
    virtual void show()
    {
        cout<<"A: "<<a<<endl;
    }

    void show1()
    {
        cout<<"A(show1()): "<<a<<endl;
    }

};

class B : public A
{
    int b=20;
    public:
    void show()
    {
        cout<<"B: "<<b<<endl;
    }

    void show1()
    {
        cout<<"B(show1()): "<<b<<endl;
    }

};

/*both show and show1 have been overridden(same prototype present in both parent and child classes)
show is virtual while show1 is not, thus show will be entered in the v-table and thus appropriate definations
are chosen corresponding to it.*/

int main()
{
    A a;
    B b;
    A*ptr1=&a;
    A*ptr2=&b;

    ptr1->show();
    ptr2->show();

    ptr1->show1();
    ptr2->show1();
    return 0;
}