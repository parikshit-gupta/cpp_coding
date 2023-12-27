#include <iostream>
#include <cstdio>
using namespace std;

int numofZeros(int n, int counter)
{
    int ques = n / 10;
    int rem = n % 10;

    if (rem == 0)
    {
        counter++;
    }

    if (ques < 10 && ques > 0)
    {
        return counter;
    }

    return numofZeros(ques, counter);

    return 0;
}

int main()
{
    int num;
    cout << "enter a number to count zeros in: ";
    cin >> num;
    cout << "number of zeros in the given number are: " << numofZeros(num, 0);

    return 0;
}
