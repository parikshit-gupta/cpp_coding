#include <iostream>
#include <cstdio>
using namespace std;
class fraction
{
    public:
    int num;
    int den;

    fraction(int num, int den) : num(num), den(den) {}

    // type conversion from user defined type to built-in type
    operator int()
    {
        int f = num / den;
        return f;
    }

    operator double()
    {
        double f = (double)num / den;
        return f;
    }
    /*
    //single conversion cannot have two methods(a constructor aldready created in class time1)
    operator time1()
    {
        time1 t1(num, den);
        return t1;
    }
    */
};

class time1
{
public:
    int hrs;
    int min;

    time1()
    {
        hrs = 0;
        min = 0;
    }
    time1(int hrs, int min): hrs(hrs), min(min)
    {

    }
    // basic type to user defined type conversion
    time1(int t)
    {
        hrs = t / 60;
        min = t % 60;
    }

    //conversion of fraction type to time1 type
    time1(fraction f1)
    {
        hrs=f1.num;
        min=f1.den;
    }
};

int main()
{
    time1 t;
    int duration = 85;
    // here "duration" will be converted to type "t"
    t = duration;
    cout << t.hrs << ':' << t.min << endl;

    fraction f1(11, 2);
    // f1 is converted to integer type
    duration = f1;
    cout << duration << endl;

    double d;
    d = f1;
    cout << d << endl;


    t=f1;
    cout << t.hrs << ':' << t.min << endl;
    return 0;
}