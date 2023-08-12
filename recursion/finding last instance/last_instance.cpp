#include <iostream>
#include <cstdio>
using namespace std;

int last_instance(int arr[], int size, int num)
{
    if (size == 0)
    {
        return -1;
    }

    if (*arr == num)
    {
        int Lastindex_found = size - 1;
        return Lastindex_found;
    }
    if (*arr != num)
    {
        return last_instance(arr - 1, size - 1, num);
    }
}
int main()
{
    int n;
    cout << "enter the number to be found: ";
    cin >> n;
    int arr[15] = {1, 3, 3, 4, 5, 3, 4, 8, 9, 3, 4, 5, 3, 7, 3};
    int ans = last_instance(arr + 14, 15, n);
    cout << ans;
    return 0;
}