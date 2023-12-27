#include<iostream>
#include<string>
#include<queue>
#include<unordered_map>
using namespace std;

int f()
{
    int a=10;
    return a;
}
int main()
{
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
}