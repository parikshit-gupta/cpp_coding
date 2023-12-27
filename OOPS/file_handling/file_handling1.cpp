#include<cstdio>
#include<iostream>
#include<fstream>
#include<string>
using namespace std;


int main()
{
    ifstream reader;
    reader.open("pg.txt");
    string st;
    reader>> st;
    cout<<st<<endl;
    getline(reader, st);
    cout<<st<<endl;
    getline(reader, st);
    cout<<st<<endl;
    reader.close();

    ofstream writer;
    writer.open("pg.txt");
    writer<<"hemlom this is vzzz."<<endl;
    writer<<"hemlom this is pg";
    writer.close();

    //reader object has an inbuilt member function eof(), this returns 1 if end of file is reached
    //else it returns 0;
    //this function can be used to read the whole file, using a loop
    return 0;
}