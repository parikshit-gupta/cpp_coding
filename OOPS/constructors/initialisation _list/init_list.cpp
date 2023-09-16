#include <iostream>
#include <cstdio>
using namespace std;

class student
{
    int age;
    const int roll_no;
    int &x = age;

    public:
    student(int r, int age) : roll_no(r), age(age)
    {
        x++;
        cout << "initialisation list." << endl;
    }

    void display()
    {
        cout << roll_no << " " << age << " " << x << endl;
    }
};

int main()
{
    student s1(101, 20);

    s1.display();

    return 0;
}
