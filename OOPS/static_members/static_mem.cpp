#include <iostream>
#include <cstdio>
using namespace std;

class student
{

    int age;
    int roll_no;

    static int total_students; // declaring static member

public:
    student(int r, int age)
    {
        roll_no = r;
        this->age = age;
        total_students++;
    }

    void display()
    {
        cout << total_students << endl;
    }

    static int getTotalstudents()  // static member function
    {
        return total_students;
    }
};

int student::total_students = 1; // initalisation of static member

int main()
{

    student s1(101, 12);
    // cout<< student :: total_students<<endl; // accsessing static member (would have workde if it was public)

    s1.display();

    student s2(102, 13);
    s1.display();

    cout<< student :: getTotalstudents()<<endl;

    return 0;
}