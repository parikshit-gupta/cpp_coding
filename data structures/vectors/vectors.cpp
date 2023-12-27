#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;

int main()
{
    vector<int> v2;
    cout<<"hello"<<endl;
    //cout<<v2[0]<<endl; you cant print an empty vector
    v2.push_back(10);
    int data=v2.back();
    cout<< data<<endl;
    vector<int> v;
    /*v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);
    v.push_back(60);*/
    /*cout<<"size1: "<<v.size()<<endl;
    v[6]=70;
    v[7]=80;
    cout<<"size2: "<<v.size()<<endl;*/
    for (int i=0; i<10;i++)
    {
        cout<<"capacity: "<<v.capacity()<<endl;
        cout<<"size: "<<v.size()<<endl;
        v.push_back(i+1);
        cout<< v.at(i)<<endl;
    }
    vector<int> v1;
    v1.pop_back();
    v1.pop_back();
    cout<<"hello"<<endl;

    vector<int> v3;

    cout<<v3.size()<<endl;
    return 0;
}