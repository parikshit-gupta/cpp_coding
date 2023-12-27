#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int *K_smallest(int *arr, int size, int k)
{
    /*
    priority_queue<int, vector<int>, greater<int>> pq; // min priority queue
    for (int i = 0; i < k; i++)
    {
        pq.push(arr[i]);
    }
    // int *arr1 = new int[size];
    for (int i = 0; i < size; i++)
    {
        arr[i] = pq.top();
        pq.pop();
        if (i < size - k)
        {
            pq.push(arr[i + k]);
        }
    }*/

    priority_queue<int> pq;
    int *arr1 = new int[k];
    for (int i = 0; i <= size; i++)
    {
        if (i < k)
        {
            pq.push(arr[i]);
        }
        if (i >= k && i < size)
        {
            if (pq.top() > arr[i])
            {
                pq.pop(); // removing the max element from the priority queue
                pq.push(arr[i]);
            }
        }
        if (i == size)
        {
            int c = 0;
            while (pq.empty() != 1)
            {
                arr1[c] = pq.top();
                pq.pop();
                c++;
            }
        }
    }
    return arr1;
}

int main()
{
    int arr[] = {2, 12, 9, 16, 10, 5, 3, 20, 25, 0, 11, 1, 8, 6, 7};
    int size = 15;
    int k = 4;
    int *arr1 = K_smallest(arr, size, k);
    for (int i = 0; i < k; i++)
    {
        cout << arr1[i] << ',';
    }
    delete[] arr1;

    return 0;
}