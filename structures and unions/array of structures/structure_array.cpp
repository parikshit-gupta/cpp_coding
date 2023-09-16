#include <iostream>
#include <cstdio>
using namespace std;

struct student
{
    int roll;
    int age;
};

int main()
{
    struct student arr1[5]; // creates an array which contains elements of type struct student
    int i;
    for (i = 0; i < 5; i++)
    {
        printf("enter the roll number of student%d: ", i + 1);
        cin >> arr1[i].roll;
        printf("enter the age of student%d: ", i + 1);
        cin >> arr1[i].age;
    }

    cout << "roll" << '\t' << "age"<< endl;
    for (i = 0; i < 5; i++)
    {
        cout << arr1[i].roll << '\t' << arr1[i].age<< endl;
    }

    return 0;
}