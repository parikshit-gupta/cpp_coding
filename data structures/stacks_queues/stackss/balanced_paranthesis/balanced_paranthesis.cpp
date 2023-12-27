#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;

bool is_balanced(char *arr)
{
    char *cpy = arr;
    stack<char> s1;
    while (*cpy != '\0')
    {
        if (*cpy == '(' || *cpy == '{' || *cpy == '[')
        {
            s1.push(*cpy);
            cout << s1.top();
        }

        else if (*cpy == ')')
        {
            if (!s1.empty())
            {
                if (s1.top() == '(')
                {
                    s1.pop();
                }
                else if (s1.top() != '(')
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
        else if (*cpy == ']')
        {
            if (!s1.empty())
            {
                if (s1.top() == '[')
                {
                    s1.pop();
                }
                else if (s1.top() != '[')
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
        else if (*cpy == '}')
        {
            if (!s1.empty())
            {
                if (s1.top() == '{')
                {

                    s1.pop();
                }
                else if (s1.top() != '{')
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
        cpy = cpy + 1;
    }
    if (*cpy == '\0' && s1.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    char arr[] = "{{}}[({}){}";
    bool x = is_balanced(arr);
    cout << x << endl;
    return 0;
}