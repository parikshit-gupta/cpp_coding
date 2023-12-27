#include <iostream>
#include <cstdio>
using namespace std;

class B
{
private:
    int B_data;

public:
    B(int data)
    {
        B_data=data;
        cout << "B: " << B_data << endl;
    }
};

class A
{
private:
    int &A_data;

public:
    int *A_ptr = &A_data;
    A(int dataA, int dataB) : A_data(dataA)
    {
        B b(dataB);
        cout << "A: " << A_data << endl;
    }

    int get_A()
    {
        return A_data;
    }
};

int main()
{
    int i = 10;
    int *i_ptr = &i;
    A a(i, 20);
    cout << a.get_A() << endl;
    // cout<<i_ptr<<endl;
    // cout<<a.A_ptr<<endl;
    return 0;
}