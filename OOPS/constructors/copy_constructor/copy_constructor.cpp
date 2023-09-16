#include<iostream>
#include<cstdio>
using namespace std;

class student
{
    int age;
    
    public:
    int roll_no;

    student(int a, int r)
    {
        cout<<"parameterised constructor."<< endl;
        age= a;
        roll_no=r;
    }

    void display()
    {
        cout<< "age: "<<age<< ' '<< "roll_no: "<<roll_no<<endl;
    }

    ~student()
    {
        cout<<"destructor called"<<endl;
    }



};


int main()
{
    student s1(10,102);

    //copy constructor is called to create s2
    student s2(s1);

    student *s3=new student(11,103);

    student s4(*s3);

    s1.display();
    s2.display();
    (*s3).display();
    s4.display();

    delete s3;//deallocates s3 objects memory from heap
    return 0;
}