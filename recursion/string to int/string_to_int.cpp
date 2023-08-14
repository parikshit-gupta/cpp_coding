#include <iostream>
#include<typeinfo>
#include <cstdio>
using namespace std;

int power(int base, int expo)
{
    int answer = 1;
    int i;
    for (i = 0; i < expo; i++)
    {
        answer = answer * base;
    }
    return answer;
}

int string_to_int(char str[], int size, int integer)
{
    if (size == 0)
    {
        return integer;
    }
    int i = *(str)-48;
    integer = integer + (i*power(10, size-1));

    return string_to_int(str+1, size - 1, integer);
}

int main()
{
    char str[100];
    cout<< "enter the string to convert: ";
    cin.getline(str, sizeof(str));
    int size =0;
    while (str[size]!='\0')
    {
        size++;
    }
    int output=string_to_int(str, size, 0);
    cout<< "the original type is: "<< typeid(str).name()<<endl;
    cout<< "the converted integer is: "<< output << endl;
    cout<< "its type is: "<< typeid(output).name();


    return 0;
}