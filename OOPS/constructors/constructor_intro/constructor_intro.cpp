#include <iostream>
#include <cstdio>
using namespace std;

class student
{
    int age;

public:
    int roll_no;

    // default constuctor, gets called imlicitly at the time of object initialisation.
    student()
    {
        cout << "Constructor0: hemlom, student object created." << endl;
    }

    // patrameterised constructor
    /*student(int r)
    {
        cout<<"Constructor1: hemlom, student object created."<<endl;
        roll_no=r;
    }*/

    /*student(int a, int r)
    {
        cout<<"Constructor2: hemlom, student object created."<<endl;
        roll_no=r;
        age=a;
    }*/

    // using 'this' keyword
    student(int roll_no)
    {
        // roll_no=roll_no;    // uses the roll_no in the scope of this constructo and roll_no of the class remains unassgned
        cout << "Constructor1: hemlom, student object created." << endl;
        (*this).roll_no = roll_no; // these statements assign roll_no of current object with the value passed to the function
        this->roll_no = roll_no;
    }

    student(int a, int r);

    // member functions
    void display()
    {
        cout << "age: " << age << " "
             << "roll_no: " << roll_no << endl;
    }

    int getAge()
    {
        return age;
    }

    void setAge(int a);
};

// defining functions and constructors outside the class
void student::setAge(int a)
{
    age = a;
}

student::student(int a, int r)
{
    cout << "Constructor(outside): hemlom, student object created." << endl;
    age = a;
    roll_no = r;
}

int main()
{

    student s1;
    s1.display();

    student *s2 = new student(101);
    s2->display();

    student s3(10,102);
    s3.display();
    return 0;
}