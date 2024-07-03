#include <iostream>
#include <cstdio>
#include "D:\Development\cpp_coding\data structures\graphs\graphs_AL\graphs_AL.h"
using namespace std;

bool isCyclic_BFS(graph &g1, bool *arr)
{
    unordered_map<int, vector<int>> &map = g1.map;
    int n = g1.n;
    int start = 0;
    queue<pair<int, int>> q;
    // first element of the pair is the child element and the second element is its parent
    q.push({0, -1});
    bool c = 0;
    int last_inserted = 0;
    while (!q.empty())
    {
        pair<int, int> front = q.front();
        q.pop();
        int curr = front.first;
        int parent = front.second;
        vector<int> v = map[curr];
        // cout<<c<<',';
        vector<int>::iterator it = v.begin();
        while (it != v.end())
        {
            // checking for presence of cycle
            /*
            1)the node must have been visited once aldready
            2)it should be visited once again by some other node in BFS
            */

            if (arr[*it] == 1)
            {
                if (*it == last_inserted)
                {
                    c = 1;
                    break;
                }
            }
            if (arr[*it] == 0)
            {
                q.push({*it, curr});
                arr[*it] = 1;
                last_inserted = *it;
            }

            it++;
        }
        if (c == 1)
        {
            break;
        }
    }
    return c;
}

// helper function
bool isCyclic_BFS(graph &g1)
{
    int n = g1.n;
    bool *arr = new bool[n];
    arr[0] = 1;
    for (int i = 1; i < n; i++)
    {
        arr[i] = 0;
    }
    bool c = isCyclic_BFS(g1, arr);
    if (c == 1)
    {
        return c;
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            c = isCyclic_BFS(g1, arr);
            if (c == 1)
            {
                break;
            }
        }
    }
    return c;
}

bool isCyclic_DFS(int curr, int start,int parent, graph &g1, bool *arr)
{
    unordered_map<int, vector<int>>&map = g1.map;
    int n = g1.n;
    bool x = 0;
    vector<int> v = map[curr];
    vector<int>::iterator it = v.begin();
    cout<<curr<<',';
    while (it != v.end())
    {
        if(parent!=start && *it ==start)
        {
            x=1;
            break;
        }
        if (arr[*it] == 0)
        {
            arr[*it] = 1;
            x = isCyclic_DFS(*it, start, curr, g1, arr);
            if (x == 1)
            {
                break;
            }
        }
        it++;
    }
    return x;
}
// helper function
bool isCyclic_DFS(graph &g1)
{
    int n = g1.n;
    bool *arr = new bool[n];
    arr[0] = 1;
    for (int i = 1; i < n; i++)
    {
        arr[i] = 0;
    }
    bool c = isCyclic_DFS(0, 0, -1, g1, arr);
    if (c == 1)
    {
        return c;
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            c = isCyclic_DFS(i, i, -1, g1, arr);
            if (c == 1)
            {
                break;
            }
        }
    }
    return c;
}

int main()
{
    graph g1(8, 8);
    g1.display();
    bool x = isCyclic_DFS(g1);
    if (x == 1)
    {
        cout << "graph is cyclic" << endl;
    }
    if (x == 0)
    {
        cout << "graph is acyclic" << endl;
    }

    return 0;
}

// 1 0 0 1 0 0 0 1 1 0 0 0 0 0 0 1 1 0 0 0 0 0 0 1 0 0 0 1 1 0 0 0 1 1 0 0 0 0 0 1 0 0 0 0 0 0 1 0 0 0 0 0 1 0 0 1
/*
0 1 0
1 2 0
2 3 0
3 7 0
7 6 0
6 4 0
4 5 0
4 0 0
*/