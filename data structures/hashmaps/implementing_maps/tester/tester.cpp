#include<cstdio>
#include<iostream>
#include<string>
#include<math.h>
using namespace std;

class pair1
{
    public:
    int a;
    int b;
    float c;
    pair1()
    {
        a=10;
        b=8;
        c=(float)a/b;
    }

};
int main()
{
    string key="abc";
    cout<< key.length()<<endl;
    cout<<pow(10,2)<<endl;
    //here garbage is assigned to all values if atleast one index is not initialised
    int arr[10];
    cout<<arr[9]<<endl;
    pair1 p;
    p.a=10;
    //but here even though no index has been initialised all indices get the values assigned by the constructor
    pair1 arr1[10];
    cout<<arr1[0].a<<endl;
    cout<<arr1[1].a<<endl;

    //string x=0;
    //cout<<x<<endl;

    int a=10;
    int b=9;
    float c= (float)a/b;
    cout<< c<<endl;

    pair1 p4;
    cout<<p4.c<<endl;

}