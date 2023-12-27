#include<iostream>
#include<cstdio>
#include<unordered_map>
#include<string>
using namespace std;

int main()
{
    unordered_map<string, int> ourmap;
    
    //inserting elements
    pair<string, int> p("abc", 10);
    ourmap.insert(p);
    cout<<"1"<<ourmap.at("abc")<<endl;

    pair<string, int> p1("abc",20);
    ourmap.insert(p1);
    cout<<"2"<<ourmap.at("abc")<<endl;


    ourmap["def"]++;
    
    cout<<ourmap["abc"]<<endl;

    //updating a key
    ourmap["abc"]=20;
    cout<<ourmap["abc"]<<endl;

    //accessing elements which are not present in the hashmap aldready
    cout<<ourmap["ghi"]<<endl;//this inserts the key "ghi" with deafult value 0.

    cout<< ourmap.at("ghi")<<endl;
    ourmap.at("ghi")++;//.at()function can also be used to update values in the hash table
    cout<< ourmap.at("ghi")<<endl;
    //cout<<ourmap.at("jkl")<<endl;//gives an error

    //count of a key can either be 0 or 1;
    if (ourmap.count("ghi")==1)
    {
        cout<<"\"ghi\" is present in our map"<<endl;
    }

    cout<<ourmap.size()<<endl;
    ourmap.erase("abc");
    cout<<ourmap.size()<<endl;
    return 0;
}