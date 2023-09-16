#include<iostream>
#include<cstdio>
using namespace std;

union data 
{
    int a;
    char b;
    double c;
};

int main()
{
    union data arr1[10];
    arr1[0].a=10;
    arr1[1].b='A';
    arr1[2].c= 123.375;
    // and so on
    // now arr1 is array with mixed data types.
    
    return 0;

}