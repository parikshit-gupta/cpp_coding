#include<iostream>
#include<cstdio>
#include<vector>
#include<unordered_map>
using namespace std;

void arr_intersection(int *arr1, int *arr2, int size1, int size2)
{
    unordered_map<int,bool> map;
    for (int i=0; i<size1;i++)
    {
        map[arr1[i]]=1;
    }
    for(int i=0;i<size2;i++)
    {
        if(map[arr2[i]]==1)
        {
            cout<<arr2[i]<<", ";
        }
    }
    return;
}

int main()
{
    int arr1[]={1, 2, 3, 4, 2};
    int arr2[]={2, 6, 1, 2};
    arr_intersection(arr1,arr2,6,4);
    
    return 0;
}