#include <iostream>
#include <cstdio>
using namespace std;

struct abc
{
    int x;
    int y;
};

int main()
{
    struct abc a = {0, 1};
    struct abc *ptr = &a;

    cout << ptr->x << endl;
    cout << ptr->y << endl;
    cout<<"cool";


    return 0;
}