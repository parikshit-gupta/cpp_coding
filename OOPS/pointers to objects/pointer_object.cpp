#include <iostream>
#include <cstdio>

using namespace std;

class student
{
    int age;
    int roll_no;

public:
    // age_ptr is a data member of the class A which points to another data member of the class
    int *age_ptr = &age;

    student(int r, int a)
    {
        roll_no = r;
        age = a;
    }

    void display()
    {
        cout << "roll_no: " << roll_no << "age: " << age << endl;
    }

    friend int func(student s);
};

int func(student s)
{
    // age_ptr1 is a pointer to the data member of the class A and itself isnt a data member of the class A
    int student::*age_ptr1 = &student::age;
    cout << (s.*age_ptr1) << endl;
    cout << *(s.age_ptr) << endl;
    cout << s.age << endl;
    cout<< s.age_ptr<<endl;
    cout<< age_ptr1<<endl;
}

int main()
{
    student s1(101, 20);
    student *ps = &s1;
    func(s1);

    return 0;
}