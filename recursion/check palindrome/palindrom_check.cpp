#include <iostream>
#include <cstdio>
using namespace std;

bool isPalindrome(char str[], int size)
{
    if (size == 0 || size == 1)
    {
        return true;
    }

    if ((*str) != *(str + size-1))
    {
        return false;
    }


    return isPalindrome(str + 1, size - 2);
}

int main()
{
    char str[10];
    cout<< "enter a string to check palindrome: ";
    
    //cin.getline(str, sizeof(str));
    cin>> str;
    int i=0;
    while(str[i]!='\0')
    {
        i++;
    }
    cout<<i<< endl;
    cout<< sizeof(str)<<endl;

    cout<< isPalindrome(str, i);

    return 0;
}