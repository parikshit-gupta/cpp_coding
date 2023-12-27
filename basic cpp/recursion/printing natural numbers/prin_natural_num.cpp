#include <iostream>
#include <cstdio>
using namespace std;

int nat_num(int n)
{
    if (n == 1)
    {
        cout << 1 << endl;
        return 1;
    }

    int small_output=nat_num(n-1)+1;
    cout << small_output << endl;
    return small_output;
}

int main()
{
    int n;
    cout << "enter number of natural numbers to print: ";
    cin >> n;

    nat_num(n);
    return 0;
}