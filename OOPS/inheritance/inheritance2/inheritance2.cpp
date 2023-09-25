#include<iostream>
#include<cstdio>
using namespace std;

//order of constructor and destructor call
class parent
{
    private:
    int x;

    protected:
    int y;

    public:
    int z;

    parent(int x)
    {
        this ->x=x;
        cout<<"parent class constructor"<<endl;
    }

    void display()
    {
        cout<<"x: "<<x;
    }


};

class child:public parent 
{
    private:
    int w;

    public:

    child(int x,int y, int z, int w):parent(x)
    {
        this->w=w;
        this->y=y;
        this->z=z;
        cout<< "child class constructor"<< endl;
    }

    void display1()
    {
        display();
        cout<<" y: "<<y<<" z: "<<z<<" w: "<<w<<endl;
    }

};

int main()
{
    child c(1,2, 3, 4);
    c.display1();
    return 0;
}