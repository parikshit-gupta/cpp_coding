#include<iostream>
#include<cstdio>
using namespace std;

class A
{
    private: 
    int x;

    protected:
    int y;

    public:
    int z;

    A(int x, int y, int z)
    {
        this->x=x;
        this->y=y;
        this->z=z;
    }

    friend int add(A const &a);

};

int add(A const &a)
{
    return a.x+a.y+a.z;
}

int main()
{
    A a(1,2,3);
    cout<< add(a)<<endl;
    return 0;
}