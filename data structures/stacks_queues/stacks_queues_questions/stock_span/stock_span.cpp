#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;

/*int *stock_span(int *arr, int size)
{
    static int *arr1 = new int[size];
    int c = 0;
    int i = 0;
    int span = 1;
    arr1[0]=span;
    for (i = 0; i < size-1; i++)
    {
        if (c == 0 && arr[i] <= arr[i + 1])
        {
            span++;
            arr1[i+1]=span;
        }

        else if (c == 0 && arr[i] >= arr[i + 1])
        {
            span=1;
            arr1[i+1]=span;
            c=1;
        }

        else if (c == 1 && arr[i] >= arr[i + 1])
        {
            arr1[i+1]=span;
            c=1;
        }

        else if (c == 1 && arr[i] <= arr[i + 1])
        {
            span++;
            arr1[i+1]=span;
            c=0;
        }
        cout<<c<<endl;
    }
    return arr1;
}*/

int *stock_span(int *arr, int size)
{
    stack<int> s;
    int *arr1 = new int[size];
    s.push(0);
    arr1[0] = 1;
    for (int i = 1; i < size; i++)
    {
        if (arr[i] >= arr[s.top()])
        {
            while (arr[s.top()] < arr[i])
            {
                s.pop();
            }
            arr1[i] = i - s.top();
            s.push(i);
        }

        if (arr[i] < arr[s.top()])
        {
            arr1[i] = 1;
            s.push(i);
        }
    }
    return arr1;
}

int main()
{
    int arr[] = {160, 60, 70, 70, 80, 100, 90, 75, 81, 120};
    int *arr1 = stock_span(arr, 10);
    for (int i = 0; i < 10; i++)
    {
        cout << arr1[i] << ", ";
    }

    delete[] arr1;
    return 0;
}