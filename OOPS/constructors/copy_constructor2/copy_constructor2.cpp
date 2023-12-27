#include<iostream>
#include<cstdio>
using namespace std;

class A
{
    int x;
    public:
    A(int x)
    {
        this->x=x;
    }

    A (const A&a)
    {
        /* here since a.x is accesisible to the copy contructor, this means that inside the class private 
        data members of as object with the same class can be accessed.*/
        this ->x=a.x;
    }

    int get_x()
    {
        return x;
    }


};

int main()
{
    A a1(10);
    A a2(a1);
    cout<<a2.get_x()<<endl;
    return 0;
}