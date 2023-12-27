// #include<iostream>
/*iostream contains some alternate defination/prototype of a template, thats why upon including iostream 
an ambiguity error was displayed*/

using namespace std;
#include "templates_cpp.cpp"
#include <cstdio>

int main()
{
    pair<int> p1;
    p1.set_val(10, 20);
    int x = p1.get_x();
    int y = p1.get_y();
    printf("%d\n", x);
    printf("%d\n", y);

    pair<char> p2;
    p2.set_val('p', 'g');
    char a = p2.get_x();
    char b = p2.get_y();
    printf("%c", a);
    printf("%c\n", b);

    triple<int, char> t1;
    t1.set_val(100,200,'p');
    x=t1.get_x();
    y=t1.get_y();
    a=t1.get_z();
    printf("%d\n", x);
    printf("%d\n", y);
    printf("%c\n", a);

    pair1<pair1<int,int>, int> p11;
    pair1<int,int> p12;
    p12.set_val(2,3);
    p11.set_val(p12,4);
    printf("%d\n", p11.get_x().get_x());
    printf("%d\n", p11.get_x().get_y());
    printf("%d\n", p11.get_y());
    
    return 0;
}