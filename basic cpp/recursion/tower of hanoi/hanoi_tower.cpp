#include <iostream>
#include <cstdio>
using namespace std;

int hanoi_tower(int n, char source, char auxi, char dest)
{
    if (n == 1)
    {
        cout << source<<"\t"<< dest<<endl;
        return 0;
    }

    hanoi_tower(n-1, source, dest, auxi);
    cout<< source<<"\t"<< dest<<endl;
    hanoi_tower(n-1, auxi, source, dest );
}

int main()
{
    int n;
    char a = 'a';
    char b = 'b';
    char c = 'c';

    cout << "enter the number of discs: ";
    cin >> n;
    cout << "source"
         << "\t"
         << "destination" << endl;
    hanoi_tower(n, a, b, c);

    return 0;
}
