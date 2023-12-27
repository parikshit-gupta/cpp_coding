#include <iostream>
#include <cstdio>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> remove_duplicates(int *arr, int size)
{
    unordered_map<int, bool> tab;
    vector<int> v;
    for (int i = 0; i < size; i++)
    {
        if (tab.count(arr[i]) == 0)
        {
            tab[arr[i]] = 1;
            v.push_back(arr[i]);
        }
        if (tab.count(arr[i]) == 1)
        {
            continue;
        }
    }
    return v;
}

int main()
{
    int arr[] = {1, 2, 3, 2, 1, 5, 4, 10, 10, 3, 2, 6, 11, 12,11};
    vector<int> v = remove_duplicates(arr, sizeof(arr)/4);
    cout << "after removing duplicates: " << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v.at(i) << ", ";
    }
    return 0;
}