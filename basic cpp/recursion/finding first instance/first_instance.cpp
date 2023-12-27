#include<iostream>
#include<cstdio>
using namespace std;

int arr_size;

int first_instance(int arr[], int size , int num)
{
    if (size == 0)
    {
        return -1;
    }

    if(*arr==num)
    {
        int ans= arr_size-size;
        return ans;
    }

    if (*arr!=num)
    {
        return first_instance(arr+1, size-1 ,num);
    }
}

int main()
{
    int n;
    int arr1[10]={1,2,3,4,5,6,7,8,3,10};
    cout << "enter the number to be found: ";
    cin >>n;
    arr_size = 10;
    int ans=first_instance(arr1, 10, n);
    cout<< ans;

    return 0;
}