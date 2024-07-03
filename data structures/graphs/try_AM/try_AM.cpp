#include<cstdio>
#include<iostream>
#include<vector>
#include"D:\Development\cpp_coding\data structures\graphs\graphs_AM\graphs_AM.h"
using namespace std;

int main()
{
    /*
    vector<vector<int>> v;
    for (int i=0;i<3;i++)
    {
        vector<int> v1;
        for(int j=0; j<3;j++)
        {
            v1.push_back(i+j);
        }
        v.push_back(v1);
    }
    for (int i=0;i<3;i++)
    {
        for(int j=0; j<3;j++)
        {

            cout<<v[i][j]<<',';
        }
        cout<<endl;
    }*/

    /*graph g1(3,3);
    g1.display_AM();

    g1.insert(3, {0});
    g1.display_AM();

    g1.delNode(2);
    g1.display_AM();

    g1.insert(4, {1,1,0,1,0});
    g1.display_AM();

    g1.insert(2, {0,1,0,1,0});
    g1.display_AM();*/

    /*
    graph g2(6,5);
    g2.display_AM();
    g2.DFS_traversal(0);
    cout<<endl;
    g2.BFS_traversal(0);
    cout<<endl;
    cout<<g2.has_path_BFS(1,4)<<endl;
    graph g3(6,6);
    g3.has_path_BFS(6,1);
    */

    for(int i=0; i<10;i=i+9)
    {
        cout<<i<<endl;
    }
    graph g4(8,9);
    cout<<endl;
    g4.get_path_DFS(0,4);
    cout<<endl;
    g4.get_path_DFS(1,7);
    cout<<endl;
    g4.get_path_BFS(1,7);
    return 0;



//1 1 0 1 1 0 1 0 1 0 1 1 0 1 1 1 1 0 1 1
//1 0 1 0 0 1 1 0 0 0 0 1 1 0 0 1 0 1 0 0 0 0 0 0 1 0 0 0 0 1 
//1 0 1 0 0 0 1 1 0 0 0 1 0 1 1 0 0 0 1 0 1 0 0 0 0 0 0 0 1 0 0 0 0 0 1 0 0 1 0 0 0 0
//1 0 0 1 0 0 0 1 1 0 0 1 0 0 0 1 1 1 0 0 0 0 0 1 0 0 1 0 1 0 1 0 1 0 0 0 1 0 0 1 1 0 0 0 0 1 0 1 1 0 0 0 0 0 0 1
}