#include <iostream>
#include <cstdio>
using namespace std;

class student
{

private:
    int age;

public:
    int roll_no;
    // functions of a class can acsess all other members of a class
    void display()
    {
        cout << "age: " << age << ' ' << "roll: " << roll_no << endl;
    }

    // public functions in a clss can be used to access all(public and private) members of a class from outside
    // getter function
    int getAge()
    {
        return age;
    }

    // setter function, sets value of a private member of class as passed to the function
    int setAge(int a)
    {
        age = a;
    }
};

int main()
{
    // creating obejcts in static memory
    //  s1 is object of class student

    student s1;
    // s1.age=10;  //age is a private property of the class student, cant be accessed outside it
    int s1age;
    cout << "enter age of s1: " << endl;
    cin >> s1age;
    s1.roll_no = 101; // rol_no is a public property of the class student, can be accessed even outside it
    s1.setAge(s1age);
    s1.display();
    // creating objects dynamically
    student *s2 = new student;

    // accsesing members of a object created in heap
    int s2age;
    cout << "enter age of s2: " << endl;
    cin >> s2age;
    (*s2).roll_no = 102;
    s2->roll_no = 102;
    s2->setAge(s2age);
    s2->display();

    delete s2;

    return 0;
}