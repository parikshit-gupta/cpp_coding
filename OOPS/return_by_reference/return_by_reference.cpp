#include<iostream>
#include<cstdio>
using namespace std;

/*any variable can be declared/initialised only once in a given scope, since scope of static variables 
is the program lifetime, the compiler ignores the redeclarations encountered during calls to "funct1" post
its first call*/

int & funct1()//funct1() returns the varibale "x" rather than just its data
{
    static int x=10;//this line is executed only once, during the first call

    return x;
}

int main()
{
    int y=funct1();/*the variable "x" thus returned is copied to "y"*/
    funct1()=2; /*since funct1() returns "x" the variable itself thus this line updates "x" to 2*/
    cout<<y<<endl;
    cout<<funct1()<<endl;
    return 0;
}