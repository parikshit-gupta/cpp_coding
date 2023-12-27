#include<iostream>
#include<cstdio>
#include"D:\Development\cpp_coding\data structures\hashmaps\implementing_maps\maps1\maps1.h"
using namespace std;

int main()
{
    map<int> ourmap;
    ourmap.insert("abc0",0);
    ourmap.insert("abc1",1);
    ourmap.insert("abc2",2);
    ourmap.insert("abc3",3);
    ourmap.insert("abc4",4);
    ourmap.insert("abc5",5);
    ourmap.insert("abc6",6);
    ourmap.insert("abc7",7);
    ourmap.insert("abc8",8);
    ourmap.insert("abc9",9);
    ourmap.insert("abc1",10);

    cout<<ourmap.search("abc3")<<endl;
    cout<<ourmap.search("abc5")<<endl;

    ourmap.del("abc3");
    ourmap.del("abc5");
    ourmap.del("abc12");

    ourmap.insert("abc11",11);
    cout<<ourmap.search("abc5")<<endl;
    cout<<ourmap.search("abc4")<<endl;
    cout<<ourmap.search("abc3")<<endl;
    cout<<ourmap.search("abc2")<<endl;
    cout<<ourmap.search("abc1")<<endl;

    return 0;
}