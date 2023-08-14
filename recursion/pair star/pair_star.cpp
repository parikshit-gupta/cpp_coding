#include <iostream>
#include <cstdio>
using namespace std;

char *star_str(char str[], int size, char *new_str, int counter)
{
    if (size == 0)
    {
        return new_str;
    }

    *(new_str + counter) = *(str);
    counter++;
    if (*(str) == *(str + 1))
    {
        *(new_str + counter) = '*';
        counter++;
    }

    return star_str(str + 1, size - 1, new_str, counter);
}

int main()
{
    char new_str[1000] = {0};
    char str[1000];
    cout<<"enter the string to be formatted: ";
    cin.getline(str, sizeof(str));
    int size = 0;
    while (str[size] != '\0')
    {
        size++;
    }

    char * potty = star_str(str, size, new_str, 0);
    int i = 0;
    cout << "the new string is: ";
    while (new_str[i] != '\0')
    {
        cout << new_str[i];
        i++;
    }

    return 0;
}