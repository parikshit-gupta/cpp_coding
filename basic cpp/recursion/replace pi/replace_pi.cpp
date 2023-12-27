#include <iostream>
#include <cstdio>
using namespace std;

char *replace_pi(char str[], int size, char new_str[], int counter)
{
    if (size == 0)
    {
        return new_str;
    }

    if ((*(str) == 'p' && *(str + 1) == 'i'))
    {
        *(new_str + counter) = '3';
        *(new_str + counter + 1) = '.';
        *(new_str + counter + 2) = '1';
        *(new_str + counter + 3) = '4';
        counter = counter + 4;
        return replace_pi(str + 2, size - 2, new_str, counter);
    }
    else
    {
        *(new_str + counter) = *(str);
        counter++;
        return replace_pi(str + 1, size - 1, new_str, counter);
    }
}

int main()
{
    int size = 0;
    char new_str[1000] = {0};
    char str[1000];
    cout << "enter the string to replace: ";
    cin.getline(str, sizeof(str));

    while (str[size] != '\0')
    {
        size++;
    }

    char *replaced_str = replace_pi(str, size, new_str, 0);

    int i = 0;
    cout << "the replaced string is: ";
    while (*(replaced_str + i) != '\0')
    {
        cout << *(replaced_str + i);
        i++;
    }

    return 0;
}