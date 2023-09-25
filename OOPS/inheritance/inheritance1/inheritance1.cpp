#include<iostream>
#include<cstdio>
using namespace std;

class parent
{
    private:
    int x=1;

    protected:
    int z=3;

    public:
    int y=2;

    void set_val()
    {
        cout<<"enter x: ";
        cin>> x;
        cout<<"enter x: ";
        cin>> y;
        cout<<"enter z: ";
        cin>> z;
    }

    void display()
    {
        cout<< "x: "<< x<<" y: "<< y << " z: "<< z;
    }

    int get_pvt()
    {
        return x;
    }
};

class child : public parent
{
    private:
    int w;

    public:

    int get_pub()
    {
        return y;
    }

    int get_prot()
    {
        return z;
    }

    //creating a function to access the private members of parent class through the child.
    int get_pvt2()
    {
        return get_pvt();
    }



    void set_val1(int w)
    {
        set_val();
        this -> w=w;        
    }

    void display1()
    {
        //private data members of parent class are not accessible to child class functions although they are are inherited in the child class
        //cout<< "x: "<< x; 
        cout<< " w: "<< w<<endl;
        //although parent class functions inherited in the child class can access private data members of parent class
        display();
    }


};

int main()
{
    child c;
    cout<<"x: "<< c.get_pvt2()<<endl;
    cout<<"z: "<< c.get_prot()<<endl;
    cout<<"y: "<< c.get_pub()<<endl;

    cout<<"x: "<< c.get_pvt()<< endl;



}