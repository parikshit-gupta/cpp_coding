#include<iostream>
#include<cstdio>
#include<stack>
using namespace std;

int main()
{
    /*differences between built in stack and our stack:
    1) pop is void in built-in header file, while ours returned the value of the deleted element
    2)name of is_empty is empty
    all other functionalities are same.
    */
    stack<int> s1;
    cout<<s1.empty()<<endl;
    s1.push(10);
    s1.push(20);
    cout<<s1.size()<<endl;
    s1.push(30);
    s1.push(40);
    s1.pop();
    s1.push(50);
    cout<<s1.top()<<endl;
    
    stack<int> s2;
    cout<<s2.top()<<endl;
    
    return 0;
}