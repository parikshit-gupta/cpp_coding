#include<iostream>
#include "LL_stack_template.h"
using namespace std;

int main()
{
    stack_LL<int> s1;
    cout<<s1.is_empty()<<endl;
    cout<<s1.curr_size()<<endl;
    stack_LL<int> s2(10);
    s2.push(20);
    cout<<s2.pop()<<endl;
    s2.push(30);
    cout<<s2.curr_size()<<endl;
    return 0;
}