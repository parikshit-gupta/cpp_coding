#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;

bool is_redundant(char *arr)
{
    stack<char> s;
    int c = 0;
    while (arr[c] != '\0')
    {
        //cout<<"hello"<<endl;
        if (arr[c] != '(' || arr[c] != ')' || arr[c] != '+')
        {
        }
        if (arr[c] == '(' || arr[c] == '+')
        {
            s.push(arr[c]);
        }
        if (arr[c] == ')')
        {
            if (s.top() == '+')
            {
                s.pop();
                s.pop();
            }
            else if (s.top() == '(')
            {
                return true;
            }
        }
        c++;
    }
    return false;
}

int main()
{
    char s1[] = "a+(b)+c";
    char s2[] = "(a+b)+c";
    char s3[] = "((a+(b)+c))";
    cout << is_redundant(s1) << endl;
    cout << is_redundant(s3) << endl;
    cout << is_redundant(s2) << endl;
    return 0;
}