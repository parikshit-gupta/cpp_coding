#include<iostream>
#include<cstdio>
using namespace std;

float power(float base, int expo)
{
    float ans=1;
    for(int i=0; i<expo;i++)
    {
        ans = ans * base;
    }
    return ans;
}

double geometric_sum(float num ,int terms)
{
    if (terms==0)
    {
        return 1;
    }

    return geometric_sum(num, terms-1) + power(num, terms);
}


int main()
{

    float num;
    int terms;
    cout<< "enter the base of the geometric sum: ";
    cin>> num;
    cout << "enter the number of terms to sum: ";
    cin>> terms;

    cout << "the geometric sum is: "<< geometric_sum(num, terms-1);
    return 0;
}