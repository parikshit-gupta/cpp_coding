#include <iostream>
#include <cstdio>
#include<string.h>
using namespace std;

class student
{
    int age;
    char *name;

public:
    student(int age, char *name)
    {
        this->age = age;
        // shallow copy
        // this ->name =name; // we are blindly just copyig the data of the value passed in name to our object member

        // deep copy
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }

    void display()
    {
        cout << "name: " << name << " "
             << "age: " << age << endl;
    }
};

int main()
{
    char name[5] ="abcd";
    student s1(20, name);
    s1.display();

    name[3]='e';
    student s2(24,name);
    s2.display();
    s1.display();

    return 0;
}