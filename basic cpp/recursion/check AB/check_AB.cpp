#include <iostream>
#include <cstdio>
using namespace std;

bool check_ab(char str[], int size, int n, bool a)
{
    bool b = false;

    if (size == 1)
    {
        return true;
    }

    if (size == n)
    {
        if (*(str) == 'a')
        {
            a = true;
        }
    }

    if (*(str) == 'a')
    {
        if (*(str + 1) == 'a' || ((*(str + 1)) == 'b' && (*(str + 2)) == 'b') || ((*(str + 1) == '\0')))
        {
            b = true;
        }
    }

    if (*(str) == 'b' && *(str + 1) == 'b')
    {
        if (*(str + 2) == 'a' || ((*(str + 2) == '\0')))
        {
            b = true;
        }
    }

    if ((a == false) || (b == false))
    {
        return false;
    }

    return check_ab(str + 1, size - 1, n, a);
}

int main()
{
    char str[100];
    cout << "enter the string to be checked: ";
    cin.getline(str, sizeof(str));

    int size = 0;
    while (str[size] != '\0')
    {
        size++;
    }

    bool checked = check_ab(str, size, size, false);
    if (checked == true)
    {
        cout << " the given conditions are satisfied.";
    }
    else if (checked == false)
    {
        cout << "the given conditions are not satisfied.";
    }

    return 0;
}