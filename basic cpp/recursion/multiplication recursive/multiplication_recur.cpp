#include<iostream>
#include<cstdio>
using namespace std;

int multiply(int n, int m)
{
    if (m==1)
    {
        return n;
    }

    return multiply(n, m-1)+n;
}

int main()
{
    int n,m;
    cout<<"enter 1st number for multiplication: ";
    cin>> n;
    cout<<"enter 2nd number for multiplication: ";
    cin>> m;

    cout<< multiply(n,m);

    return 0;

}