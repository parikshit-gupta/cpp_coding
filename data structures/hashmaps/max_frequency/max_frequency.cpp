#include<iostream>
#include<cstdio>
#include<vector>
#include<unordered_map>
using namespace std;

int max_frequency(int *arr, int size)
{
    unordered_map<int, int> frequency;
    int max=0;
    int k=0;
    for (int i=0; i<size; i++)
    {
        frequency[arr[i]]++;
        if (max<=frequency.at(arr[i]))
        {
            max=frequency.at(arr[i]);
            k=arr[i];
        }
    }
    return k;
}

int main()
{
    int arr[]={2, 12, 2, 11, 12, 2, 1, 2, 2, 11, 12, 2, 7};
    int x=max_frequency(arr, 13);
    cout<<"max frequency number: "<<x<<endl;
    return 0;
}