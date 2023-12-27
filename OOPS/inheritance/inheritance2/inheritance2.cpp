#include<iostream>
#include<cstdio>
using namespace std;

//order of constructor and destructor call 
//accessing private data of parent class using functions of parent class thus inherited.
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
    int x=5;

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
    /*since display() is a function of the parent class it uses the x nearest to its scope, which is that 
    of the parent class.*/
    c.display();
    /*since there is a variable named 'x' aldready in the scope of the child class, that would be printed
    as when c.x is encountered, x is first searched for in the scope of the child class and then searched
    for in the data members inherited from the parent class.*/
    cout<<"x: "<<c.x<<endl;
    return 0;
}