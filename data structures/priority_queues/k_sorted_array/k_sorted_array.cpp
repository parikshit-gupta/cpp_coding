#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

int *K_sorted(int *arr, int size, int k)
{
    priority_queue<int> pq;
    for (int i = 0; i < k; i++)
    {
        pq.push(arr[i]);
    }
    int *arr1 = new int[size];
    for (int i = 0; i < size; i++)
    {
        arr1[i] = pq.top();
        pq.pop();
        if (i < size - k)
        {
            pq.push(arr[i + k]);
        }
    }
    for (int i = 0; i < size; i++)
    {
        arr[i] = arr1[i];
    }
    delete arr1;
}

int main()
{
    int arr[]={12,15,7,4,9};
    int size=5;
    K_sorted(arr, size, 3);
    for (int i=0; i< size;i++)
    {
        cout<<arr[i]<<',';
    }

    return 0;
}