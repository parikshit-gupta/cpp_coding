#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

// sorting using heap sort in descending order, using min_heap
void insert(int *arr, int size)
{
    // arr to arr+size : effective array(after increase in size)
    // creating min heap
    // no issue of size here as min value of size passed will be one
    size++;
    int ci = size - 1;//index of the element to be inserted
    int pi = (ci - 1) / 2;//index of the parent of the above element
    while (arr[ci] < arr[pi])
    {
        int temp = arr[pi];
        arr[pi] = arr[ci];
        arr[ci] = temp;
        ci = pi;
        pi = (ci - 1) / 2;
    }
}

void rem_min(int *arr, int size)
{
    // exchanging the min(first) element of the heap and the last element
    // down-heapification on the new first element of the heap
    int temp = arr[size - 1];
    arr[size - 1] = arr[0];
    arr[0] = temp;
    size--;

    int pi = 0;
    int ci = 0;

    // down-heapification
    while (true)
    {
        int ci1 = (2 * pi + 1); // child index 1
        int ci2 = (2 * pi + 2); // child index 2
        if (ci1 < size && ci2 >= size)
        {
            ci = ci1;
        }
        if (ci2 < size && ci1 >= size)
        {
            ci = ci2;
        }
        if (ci1 < size && ci2 < size)
        {
            if (arr[ci1] > arr[ci2])
            {
                ci = ci2;
            }
            else
            {
                ci = ci1;
            }
        }
        if (ci1 >= size && ci2 >= size)
        {
            return;
        }
        if (arr[pi] >= arr[ci])
        {
            int temp1 = arr[ci];
            arr[ci] = arr[pi];
            arr[pi] = temp1;
            pi = ci;
        }
        else
        {
            return;
        }
    }
}

int *heap_sort(int *arr, int size)
{
    // effective array of the heap aldreay created
    // element to be inserted
    // insert function
    // increase size
    // partition
    // remove_min one by one from the array
    // this will involve exchanging the first and the last element, but this time we wont pop after exchanging

    int c = 1; // partiton counter
    while (c < size)
    {
        insert(arr, c);
        c++;
    }
    c=size;
    while(c>1)
    {
        rem_min(arr, c);
        c--;
    }
    return arr;
}

int main()
{
    int arr[]={2, 6, 8, 5, 4, 3, 10 , 7, 9, 1, 2};
    int size=11;
    cout<<"before heap sort: ";
    for (int i=0; i<size;i++)
    {
        cout<<arr[i]<<", ";
    }
    cout<<endl;

    int *arr1=heap_sort(arr, size);
    cout<<"after heap sort: ";
    for (int i=0; i<size;i++)
    {
        cout<<arr1[i]<<", ";
    }

    return 0;
}