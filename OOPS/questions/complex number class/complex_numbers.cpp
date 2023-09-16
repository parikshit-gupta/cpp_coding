#include <iostream>
#include <cstdio>
#include<math.h>
using namespace std;

class complex
{
private:
    float a;
    float b;

public:
    complex(int real, int img)
    {
        a = real;
        b = img;
    }

    void display()
    {
        cout << "the complex number is: " << a << "+i" << b << endl;
    }

    void add(const complex &cn)
    {
        a=a+cn.a;
        b=b+cn.b;
    }

    void multiply(const complex &cn)
    {
        a = (a*cn.a-(b*cn.b));
        b = (a*cn.b+(b*cn.a));
    }

    void conj()
    {
        b=-1*(b);
    }

    float modulous()
    {
        float mod = sqrt(a*a+(b*b));
        return mod;
    }

    float argument()
    {
        float arg=atan2(b,a);
        return arg*180/3.14;
    }
};

int main()
{

    complex c1(1,2);
    complex c2(2,3);

    c1.multiply(c2);

    cout<< "modulous: "<<c1.modulous()<< " " <<"argument: "<< c1.argument()<< endl;
    cout<< "modulous: "<<c2.modulous()<< " " <<"argument: "<< c2.argument()<< endl;
    return 0;
}