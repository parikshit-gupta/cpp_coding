#include<iostream>
#include<cstdio>
#include<unordered_map>
#include<string>
#include<typeinfo>
using namespace std;

int main()
{
    string apha="abc";
    cout<<apha[2]<<endl;
    unordered_map<char, int> ourmap;
    unordered_map<char, int>::iterator it;
    it=ourmap.begin();
    //cout<<typeid(*it).name()<<endl;
    //inputting elements in a hashmap using iterators
    char KEY;
    int VAL;
    while(VAL!=-1)
    {
        cout<<"enter key: ";
        cin>>KEY;
        cout<<"enter val: ";
        cin>>VAL;
        ourmap[KEY]=VAL;
    }

    /*note that it-- is not a valid operation not de ined in the STL defination*/
    for(it=ourmap.begin();it!=ourmap.end();it++)
    {
        if (it->second==-1)
        {
            continue;
        }
        cout<<"KEY: "<<it->first<<", VALUE: "<<it->second<<endl;
    }
    
    return 0;
}