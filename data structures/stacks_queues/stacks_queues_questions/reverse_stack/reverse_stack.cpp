#include<iostream>
#include<cstdio>
#include<stack>
using namespace std;

stack<int> rev_stack(stack<int> s, int max_size)
{
    stack<int> s2;
    int top=s.top();
    s.pop();
    if (s.empty())
    {
        s2.push(top);
        return s2;
    }
    s2=rev_stack(s, max_size);
    s2.push(top);
    if(s2.size()!=max_size)
    {
        return s2;
    }
    else if (s2.size()==max_size)
    {
        while(!s.empty())
        {
            s.pop();
        }
        
        while(!s2.empty())
        {
            int top1=s2.top();
            s2.pop();
            s.push(top1);
        }
        return s;
    }
}

int main()
{
    stack<int> s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.push(5);
    s1=rev_stack(s1,5);
    while(!s1.empty())
    {
        cout<<s1.top()<<endl;
        s1.pop();
    }
    return 0;
}