#include<iostream>
#include<cstdio>
using namespace std;

int sum_array(int arr[], int size)
{
    if (size == 1)
    {
        return * arr;
    }

    int sum = sum_array(arr+1, size-1) + *arr;
    return sum;

}

int main()
{
    int arr1[10]={1,2,3,4,5,600,7,8,9,10};
    int sum = sum_array(arr1, 10);
    cout<< "sum is: "<< sum;

    return 0;
}