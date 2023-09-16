#include <iostream>
#include <cstdio>
using namespace std;

class fraction
{
    int num;
    int den;

public:
    fraction(int num, int den)
    {
        this->num = num;
        this->den = den;
    }

    void display()
    {
        cout << "fraction is: " << num << '/' << den << endl;
    }

    void simplify()
    {
        int gcd =1;
        int j= (num < den) ? num : den;
        for (int i=1;i<=j;i++)
        {
            if (num%i==0&&den%i==0)
            {
                gcd=i;
            }
        }

        den=den/gcd;
        num=num/gcd;
    }

    //void add(fraction f2) // here the object f2 created in main is copied into a new object created for the function fraction.
    // to avoid this we can pass the value of f2 by reference which would save up the time in copying and calling the copy constructor. 
    
    void add(const fraction &f2)
    {
        int lcm = den * f2.den;
        int x = f2.den;
        int y = den;
        num = num * x + ((f2.num) * y);
        den = lcm;
        this->simplify();
    }
};

int main()
{
    fraction f1(1,2);
    fraction f2(2,3);

    f1.add(f2);

    f1.display();
    f2.display();

    return 0;
}