#include<iostream>
#include<cstdio>
#include"D:\Development\cpp_coding\data structures\graphs\graphs_AL\graphs_AL.h"
using namespace std;

int main()
{
    graph<int> g1;
    int n;
    cout<<"enter the number of nodes: ";
    cin>>n;

    int m;
    cout<<"enter the number of edges: ";
    cin>>m;

    //creating the graph by inserting edges
    for (int i=0; i<m;i++)
    {
        int u;
        int v;
        cout<<"edge from: ";
        cin>>u;
        cout<<"edge to: ";
        cin>>v;
        //for simplicity creating an undirected graph right now
        g1.addEdge(u,v,0);
    }

    cout<<"graph is: "<<endl;
    g1.display();
}

