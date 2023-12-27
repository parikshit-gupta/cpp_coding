#include<iostream>
#include<cstdio>
using namespace std;

class test
{
    int i;
    int y;
public:
    test(int i, int y): i(i), y(y)
    {
        try
        {
            cout<<"throwing test exception."<<endl;
            throw(404);
        }
        catch(int m)
        {
            cout<<"test exception caught in constructor."<<endl;
            //deleting data members of the current object
            delete &i;
            delete &y;
            delete this;//this calls the destructor of the current object 
            /*if the exception is rethrown the object will never go out of scope as the try block of main
            will be omitted which makes it nessacary to delete the object in the constructor's catch block
            itself*/
            throw;
        }
    }   

    ~test()
    {
        cout<<"object destroyed"<<endl;
    } 
};

int main()
{
    try
    {
        test t1(1,2);
    }
    catch(int i)
    {
        cout<<"test exception caught in main."<<endl;
    }

    //test t1(10,20);

    return 0;
}