#include<iostream>
#include<cstdio>
using namespace std;

//doubt about the behaviour of ip1.
class A
{
    int m=10;
    public:
    int *ip=&m;
    int A::*ip1=&A::m;

    void display()
    {
        cout<<"m: "<<m<<endl;
        cout<<ip1<<endl;
        cout<<ip<<endl;
    }

    int triple(A a)
    {
        int A::*ip1=&A::m;
        return 3*(a.*ip1);
    }

};

int main()
{
    A a;
    cout<<*(a.ip)<<endl;
    cout<<a.triple(a)<<endl;
    cout<<(a.ip1)<<endl;
    a.display();
    return 0;
}