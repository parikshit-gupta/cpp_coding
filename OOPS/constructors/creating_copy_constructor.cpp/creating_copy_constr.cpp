#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

class student
{
    int age;
    char *name;

public:
    student(int age, char *name)
    {
        this->age = age;
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }

    // copy constructor

    student(const student &sn)
    {
        age = sn.age;
        name = sn.name;
    }

void display()DDDKJF
    {
        cout << "name: " << name << " "
             << "age: " << age << endl;
    }
};

int main()
{
    char name[5] = "abcd";
    student s1(20, name);

    // the implicitly defined copy contructor uses shallow copy
    student s2(s1);
    s1.display();
    s2.display();

    return 0;
}