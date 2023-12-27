#include <iostream>
#include <cstdio>
#include <vector>
#include <unordered_map>
using namespace std;

int pair_sum(int *arr, int size)
{
    unordered_map<int, int> map; // key: elements of array, value: their number of occurences
    int c = 0;
    for (int i = 0; i < size; i++)
    {
        map[arr[i]]++;
        if (map.count(-arr[i]) == 0)
        {
            continue;
        }
        else if (map.count(-arr[i]) == 1)
        {
            c = c + map[-arr[i]];
        }
    }
    return c;
}

int main()
{
    int arr[] = {2, 1, -2, -2, 2, 2, -2, -2, 2, -2, -1};
    int arr1[] = {1, 2, 3, -1, -2, 2, 6};
    cout << "number of pairs are: " << pair_sum(arr1, 7) << endl;
    return 0;
}