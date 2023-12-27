#include <iostream>
#include <cstdio>
using namespace std;

int staircase(int n)
{
    int step=1;
    int x=0;
    int y=0;
    int z=0;
    if (n==1)
    {
        return 1;
    }
    if (n==2)
    {
        return 2;
    }
    if (n==3)
    {
        return 4;
    }

    

    if (step==1)
    {
        x = staircase(n-1);
        step = 2;
    }
    if (step==2)
    {
        y = staircase(n-2);
        step = 3;
    }
    if (step==3)
    {
        z = staircase(n-3);
        step = 4;
    }
    
    return x+y+z;

}

int main()
{
    int n;
    cout<<"enter the number of stairs to climb: ";
    cin>> n;
    int ways=staircase(n);
    cout<< "the number of ways to climb are: "<< ways;

    return 0;
}