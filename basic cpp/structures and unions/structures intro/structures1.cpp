#include <iostream>
#include <cstdio>
// #pragma pack(1) // switches off the padding feature in structures.
using namespace std;
typedef int INTEGER;


// declaring a global structure
typedef struct student
{
    char *name;
    char adress;
    INTEGER age;
}stu;

stu s1; // global structure variable

INTEGER main()
{
    char names[10] = "px";
    cout << names << endl;
    struct student s2; // structure variable local to main()
    // char *ptr ="abc";
    char str1[10] = "pz";
    char str2[10] = "vz";
    char str3[10] = "pzz";
    s1.name = str1;
    s1.age = 19;
    s2.name = str2;
    s2.age = 14;

    struct student s3 = {str3, 16}; // differnt way to initialise a structure.

    cout << "s1 name: " << s1.name << endl;
    cout << "s1 age: " << s1.age << endl;
    cout << "s2 name: " << s2.name << endl;
    cout << "s2 age: " << s2.age << endl;
    cout << "s3 name: " << s3.name << endl;
    cout << "s3 age: " << s3.age << endl;
    cout<< sizeof(s3)<< endl;


    return 0;
}