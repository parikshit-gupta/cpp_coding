#include<iostream>
#include<cstdio>
using namespace std;

int numof_digits(int n)
{
    if (n<10 && n>0)
    {
        return 1;
    }

    int small_output=numof_digits(n/10);
    return small_output+1;

}

int main()
{
    int n;
    cout<< "enter the number to find number of digits: ";
    cin>>n;
    int digits=numof_digits(n);
    printf("number of digits in %d is %d.", n, digits);

    return 0;
}