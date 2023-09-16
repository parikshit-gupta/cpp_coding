#include <iostream>
#include <cstdio>
using namespace std;

class employee
{
    char name[30];
    int age;

public:
    void getData()
    {
        cout << "enter name: ";
        cin >> name;

        cout << "enter age: ";
        cin >> age;
    }

    char * get_name()
    {
        return name;
    }

    int get_age()
    {
        return age;
    }
};

int main()
{
    employee manager[5]; // array of objects
    employee clerk[10];

    int i = 0;
    for (i = 0; i < 5; i++)
    {
        manager[i].getData();
    }

    cout<< "name"<< "\t"<< "age"<<endl;

    for (i = 0; i < 5; i++)
    {
        cout << manager[i].get_name()<< "\t"<< manager[i].get_age()<< endl;
    }

    return 0;
}