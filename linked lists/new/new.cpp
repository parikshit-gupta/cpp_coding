#include<iostream>
#include<cstdio>
using namespace std;

int *ret_arr()
{
    static int arr[]={1,2,3,4,5,6};
    return arr;
}

int main()
{
    int i=0;
    int *ptr=ret_arr();
    for (i=0;i<6;i++)
    {
        cout<<ptr[i]<<", ";
    }
    return 0;
}