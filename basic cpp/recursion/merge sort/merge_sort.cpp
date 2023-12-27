#include <iostream>
#include <cstdio>
using namespace std;

int *merge_sort(int arr[], int size)
{
    if (size == 2)
    {
        // compare
        int l;
        if (arr[0] > arr[1])
        {
            // swap
            l = arr[1];
            arr[1] = arr[0];
            arr[0] = l;
        }
        return arr;
    }

    int mid = size / 2;

    // break array in 2 parts
    int arr1[100] = {0};
    int i = 0;
    for (i = 0; i < mid; i++)
    {
        arr1[i] = arr[i];
    }

    int arr2[100] = {0};
    for (i = mid; i < size; i++)
    {
        arr2[i - mid] = arr[i];
    }

    // sort the 2 parts
    merge_sort(arr1, mid);
    merge_sort(arr2, size - mid);

    // merging the sorted arrays

    int arr3[100] = {0};
    i = 0;
    int j = 0;
    int k = 0;
    while (true)
    {
         if (k == size)
        {
            break;
        }
        if (i < mid && j < size - mid)
        {

            if (arr1[i] <= arr2[j])
            {
                arr3[k] = arr1[i];
                i++;
                k++;
            }

            if (arr2[j] < arr1[i])
            {
                arr3[k] = arr2[j];
                j++;
                k++;
            }
        }
        else if (i >= mid && i < size)
        {
            arr3[k] = arr2[j];
            j++;
            k++;
        }

        else if (j >= size - mid && j < size)
        {
            arr3[k] = arr1[i];
            i++;
            k++;
        }

    }

    // copying into original array
    for (i = 0; i < size; i++)
    {
        arr[i] = arr3[i];
    }

    return arr;
}

int main()
{
    int n;
    cout << "enter the size of the required array: ";
    cin >> n;

    int arr[100] = {0};
    int i = 0;
    for (i = 0; i < n; i++)
    {
        cout << "enter element number " << i + 1 << " of the array: ";
        cin >> arr[i];
    }

    cout << "the original array is: {";
    for (i = 0; i < n; i++)
    {
        cout << arr[i] << ", ";
    }
    cout << "}" << endl;

    merge_sort(arr, n);

    cout << "the sorted array is: {";
    for (i = 0; i < n; i++)
    {
        cout << arr[i] << ", ";
    }
    cout << "}";

    return 0;
}