#include <iostream>
#include <cstdio>
using namespace std;

char *removeX(char str[], int size, char new_str[], int counter)
{
    if (size == 0)
    {
        return new_str;
    }

    if (*(str) != 'x')
    {
        *(new_str + counter) = *(str);
        counter++;
        return removeX(str + 1, size - 1, new_str, counter);
    }

    if (*(str) == 'x')
    {
        return removeX(str + 1, size - 1, new_str, counter);
    }
}

int main()
{
    char str[1000];
    char new_str[1000] = {0};
    cout << "enter the string to remove x: ";
    cin.getline(str, sizeof(str));

    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }

    char *returned_str = removeX(str, i, new_str, 0);

    i = 0;
    cout << "the returned string is: ";
    while (returned_str[i] != '\0')
    {
        cout << returned_str[i];
        i++;
    }

    return 0;
}