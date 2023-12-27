#include<iostream>
#include<cstdio>
using namespace std;

int add(int a, int b)
{
    return a+b;
}

int sub(int a, int b)
{
    return a-b;
}


int main()
{
    /*funct_ptr is a pointer to a function with the prototype as mentioned with it
    later we point it to the function "add" which has the same prototype as metioned in the declaration of
    funct_ptr*/
    //the address of a function can be accessed by its name itself

    int (*funct_ptr)(int, int);
    //funct_ptr=&add; same thing
    funct_ptr=add;
    cout<<funct_ptr(10,20)<<endl;
    funct_ptr=sub;
    cout<<funct_ptr(10,20)<<endl;
    return 0;
}