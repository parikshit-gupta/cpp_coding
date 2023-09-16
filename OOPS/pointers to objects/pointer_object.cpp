#include<iostream>
#include<cstdio>

using namespace std;

class student 
{
    int age;
    int roll_no;

    public:
    student(int r, int a)
    {
        roll_no=r;
        age=a;
    }

    void display()
    {
        cout<< "roll_no: "<< roll_no <<"age: "<<age <<endl;
    }
};

int main()
{
    student s1(101, 20);
    student *ps=&s1;




    return 0;
}