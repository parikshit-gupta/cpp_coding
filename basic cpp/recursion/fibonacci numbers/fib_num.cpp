#include<iostream>
#include<cstdio>
using namespace std;

int fib_num(int n)
{
    if (n==0)
    {
        return 0;
    }
    if (n==1)
    {
        return 1;
    }

    return fib_num(n-1)+fib_num(n-2);
}

int main()
{
    int n;
    cout<< "enter which fibonacii number you want: ";
    cin>> n;
    int x=fib_num(n-1);
    printf("the %d fibonacii number is %d.", n, x);
    return 0;
}