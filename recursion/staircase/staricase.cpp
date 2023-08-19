#include <iostream>
#include <cstdio>
using namespace std;

int staircase(int n)
{
    if (n == 1)
    {
        return 1;
    }
    if (n == 2)
    {
        return 2;
    }

    if (n == 3)
    {
        return 4;
    }

    int ways = staircase(n - 1);
    return ways
}

int main()
{
    return 0;
}