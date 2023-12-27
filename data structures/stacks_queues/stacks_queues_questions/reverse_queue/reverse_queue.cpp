#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;

queue<int> rev_queue(queue<int> q)
{
    int front=q.front();
    q.pop();
    if(q.empty())
    {
        q.push(front);
        return q;
    }
    q=rev_queue(q);
    q.push(front);
    return q;
}

int main()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q=rev_queue(q);
    while(!q.empty())
    {
        cout<<q.front()<<endl;
        q.pop();
    }
    return 0;
}