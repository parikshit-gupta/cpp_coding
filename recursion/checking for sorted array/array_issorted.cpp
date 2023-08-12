#include<iostream>
#include<cstdio>
using namespace std;

bool isSorted(int arr[], int size)
{
    if (size == 0 || size == 1)
    {
        return true;
    }

    if (arr[0]>arr[1])
    {
        return false;
    }
    return isSorted(arr + 1 , size -1 );
}

int main()
{
    int arr1[10]={1,2,3,4,5,100,7,8,9,10};
    bool sorted = isSorted(arr1, 10);
    cout<< sorted;
    return 0;
}