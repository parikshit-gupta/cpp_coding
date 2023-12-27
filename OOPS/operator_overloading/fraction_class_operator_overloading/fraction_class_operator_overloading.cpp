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
        int gcd = 1;
        int j = (num < den) ? num : den;
        for (int i = 1; i <= j; i++)
        {
            if (num % i == 0 && den % i == 0)
            {
                gcd = i;
            }
        }

        den = den / gcd;
        num = num / gcd;
    }

    void add(const fraction &f2)
    {
        int lcm = den * f2.den;
        int x = f2.den;
        int y = den;
        num = num * x + ((f2.num) * y);
        den = lcm;
        this->simplify();
    }

    // operator overloading
    fraction operator+(const fraction &f2)
    {
        int lcm = den * f2.den;
        int x = f2.den;
        int y = den;
        int num1 = num * x + ((f2.num) * y);
        int den1 = lcm;

        fraction f3(num1, den1);
        f3.simplify();
        return f3;
    }

    bool operator==(fraction &f2)
    {
        if ((num == f2.num) && (num == f2.num))
        {
            return true;
        }
        return false;
    }

    // pre-increament operator

    /*void operator++()
    {
        num = num + den;
        this->simplify();
    }*/

    /*
    fraction operator++()
    {
        num=num+den;
        this->simplify();
        return *this;
    }*/

    fraction & operator++()
    {
        num=num+den;
        this->simplify();
        return *this;
    }

    //post increment
    //since no nesting is allowed in post increament no need to return by reference 
    fraction operator++(int)    // the "int" keyword seperates the pre and post increment operators
    {
        fraction fnew(num,den);
        num=num+den;
        fnew.simplify();
        this->simplify();
        return fnew;
    }

    // add updation operator
    // nesting is allowed in case of this operator thus returning by reference becomes imperitive

    fraction& operator+=(fraction const &f2)
    {
        num=(num*f2.den)+(f2.num*den);
        den = den*f2.den;
        this->simplify();
        return *this;
    }

    friend fraction operator+ (int i, fraction const &f1);
};

fraction operator+ (int i, fraction const &f1)
{
    int num=(i*f1.den)+f1.num;
    int den=f1.den;
    fraction f3(num, den);
    f3.simplify();
    return f3;
}

int main()
{
    /*
    fraction f1(1, 2);
    fraction f2(2, 3);

    ((f1+=f2)+=f2)+=f2;
    f1.display();
    int i=5;
    int x= ++(++i);
    i=5;
    int y=(i++);
    cout<< x<<endl;
    cout<< y<<endl;

    // fraction f3 = f1.add(f2);
    fraction f3 = f1 + f2;

    f1.display();
    f2.display();
    f3.display();

    ++(++f1);
    fraction f5=f2++;

    f1.display();
    f2.display();
    f5.display();


    bool c = (f1 == f2);
    cout << c << endl;
    */

   fraction f1(11,2);
   f1=2+f1;
   f1.display();

    return 0;
}