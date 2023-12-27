#include <iostream>
#include <cstdio>
using namespace std;

bool find_num(int arr[], int size, int num)
{
    if (size == 1)
    {
        if (*arr == num)
        {
            return true;
        }
        if (*arr != num)
        {
            return false;
        }
    }
    else
    {
        if (*arr == num)
        {
            return true;
        }
        if (*arr != num)
        {
            return find_num(arr + 1, size - 1, num);
        }
    }
}

int main()
{
    int arr1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n;
    cout << "enter the number to be found: ";
    cin >> n;

    cout << find_num(arr1, 10, n);
    return 0;
}