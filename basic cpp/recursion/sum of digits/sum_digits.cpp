#include<iostream>
#include<cstdio>
using namespace std;

int num_digits(int n, int counter)
{
    int ques = n/10;
    int rem = n%10;

    counter++;

    if (ques == 0)
    {
        return counter;
    }

    return num_digits(ques, counter);


}

int main()
{
    int num;
    cout<< "enter a number to count its digits: ";
    cin>> num;
    cout<<"the number of digits in this number are: "<< num_digits(num, 0);

    return 0;
}