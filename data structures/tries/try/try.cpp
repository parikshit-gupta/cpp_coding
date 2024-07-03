#include<iostream>
#include<string>
#include<queue>
#include<unordered_map>
#include<vector>
using namespace std;

int f()
{
    int a=10;
    return a;
}
int main()
{

    //unordered_map<vector<vector<int>>, bool> map1;
    vector<vector<int>> v1={{0,0,1}, {1,0,1}, {0,1,0}};
    vector<int> v2={1,2,3,4,5};
    vector<int> v3={1,2,3,4,5};
    //bool x=(v2==v3); no operator overloading for == in vectors
    pair<int,int> p1={1,2};
    pair<int,int> p2={1,2};
    cout<<(v2==v3)<<endl;

    vector<int> v4;
    v4=v2;

    for (auto x: v4)
    {
        cout<< x;
    }


    /*
    pair<int,int> p1=pair<int,int>(1,2);
    cout<<p1.first;
    vector<int> v1;
    vector<int>v2={1,2,3,4,5};
    v1=v2;
    string s="abcds";
    string s1=s;
    string s2=s+s1;
    cout<<s2<<endl;
    s2.pop_back();
    s2.push_back('o');
    cout<<s2<<endl;
    for(int i=1;i<=s.length();i++)
    {
        s1[i-1]=s[i];
    }
    s1[s.length()-1]='\0';
    cout<<s<<endl;
    cout<<s1<<endl;
    cout<<s[0]-97<<endl;
    cout<<s.length()<<endl;
    cout<<s1.length()<<endl;
    int a=f();
    cout<<a<<endl;
    */
}