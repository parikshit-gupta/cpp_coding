#include<iostream>
#include<cstdio>

using namespace std;

int factorial(int n)
{
    if (n==0)
    {
        return 1;
    }
    
    return factorial(n-1)*n;

}

int main()
{
    int n;
    printf("enter the number to calculate factorial: ");
    cin >> n;
    int x=factorial(n);
    cout<<"factorial is: " << x;

    return 0;

}

