#include <iostream>
#include <cstdio>
using namespace std;

int power(int base, int expo)
{
    if (expo == 0)
    {
        return 1;
    }

    return power(base, expo-1) * base;
}

int main()
{
    int base;
    cout << "enter base: ";
    cin >> base;

    int expo;
    cout << "enter exponent: ";
    cin >> expo;

    int answer = power(base, expo);
    printf("%d to the power %d is %d.", base, expo, answer);

    return 0;
}