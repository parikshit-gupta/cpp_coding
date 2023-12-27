#include <iostream>
#include <cstdio>
using namespace std;

int bin_search(int arr[], int x, int start, int end)
{
    int mid = (start + end) / 2;
    int size = end - start + 1;
    if (size == 2)
    {
        return -1;
    }
    if (arr[start] == x)
    {
        return start;
    }
    if (arr[end] == x)
    {
        return end;
    }

    if (arr[mid] > x)
    {
        return bin_search(arr, x, start, mid);
    }

    if (arr[mid] < x)
    {
        return bin_search(arr, x, mid, end);
    }

    if (arr[mid] == x)
    {
        return mid;
    }
}

int main()
{
    int arr[19] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 121, 132, 141, 152, 160, 170, 180, 1900};
    cout << "enter the element to be searched: ";
    int x;
    cin >> x;
    int index = bin_search(arr, x, 0, 18);
    cout << "the element was found at index: " << index;
    return 0;
}