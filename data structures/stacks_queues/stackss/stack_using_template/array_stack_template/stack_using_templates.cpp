#include<iostream>
#include <cstdio>
#include "stack_using_template.h"
using namespace std;

int main()
{
    stack<int> s1(10);
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    s1.push(50);
    s1.push(60);
    s1.push(70);
    int x=s1.pop();
    printf("%d\n", x);
    x=s1.pop();
    printf("%d\n", x);
    x=s1.pop();
    printf("%d\n", x);
    x=s1.top();
    printf("%d\n", x);
    stack<char> s2(10);

    return 0;
}