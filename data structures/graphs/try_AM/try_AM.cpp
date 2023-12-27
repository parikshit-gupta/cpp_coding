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

    graph g1(3,3);
    g1.display_AM();

    g1.insert(3, {0});
    g1.display_AM();

    g1.delNode(2);
    g1.display_AM();

    g1.insert(4, {1,1,0,1,0});
    g1.display_AM();

    g1.insert(2, {0,1,0,1,0});
    g1.display_AM();


//1 0 0 1 1 0   
    return 0;
}