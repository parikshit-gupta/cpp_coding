#include <iostream>
#include <cstdio>
#include "D:\Development\cpp_coding\data structures\priority_queues\heaps\heaps.h"
using namespace std;

int main()
{
    /*
    try
    {
        vector<int> v1;
        cout << v1.at(2) << endl;
    }
    catch (std::out_of_range)
    {
        cout << "hemlom" << endl;
    }*/

    min_heap mh1;
    while (1 == 1)
    {
        int n = 0;
        cout << "enter the number to insert in heap: ";
        cin >> n;
        if (n == -1)
        {
            break;
        }

        mh1.insert(n);
    }
    cout << "heap initially: ";
    for (int i = 0; i < mh1.v.size(); i++)
    {
        cout << mh1.v[i] << ", ";
    }

    cout << endl
         << mh1.delete_min() << endl;

    cout << "heap after: ";
    for (int i = 0; i < mh1.v.size(); i++)
    {
        cout << mh1.v[i] << ", ";
    }
    return 0;
}