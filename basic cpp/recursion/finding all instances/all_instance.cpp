#include <iostream>
#include <cstdio>
using namespace std;

int arr_size;
int * all_instances(int arr[], int size, int num, int current_index, int index_arr[])
{
    if (size == 0)
    {
        return index_arr;
    }
    if (*arr == num)
    {
        index_arr[current_index] = arr_size - size;
        current_index++;
    }

    return all_instances(arr + 1, size - 1, num, current_index, index_arr);
}

int main()
{
    int n;
    cout << " enter the number to be found: ";
    cin >> n;
    int arr[15] = {1, 2, 3, 4, 5, 6, 7, 8, 3, 10, 11, 3, 13, 14, 15};
    int index_arr[15] = {0};
    arr_size = 15;
    all_instances(arr, 15, n, 0, index_arr);

    cout << "array of indices is: {";
    for (int i = 0; i < 15; i++)
    {
        cout << index_arr[i] << ", ";
    }

    cout << "}";
    return 0;
}