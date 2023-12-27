#include<iostream>
#include<cstdio>
#include<fstream>
#include<string>
using namespace std;
//the file which is to be read/written must be present in the same directory as the program file
int main()
{
    ofstream writer("pg.txt");//creates a writer object which opens the file "pg.txt" and can be used to write to it
    writer<<"hemlom, this is pg."<<endl;//writes a single line to the file corresponding to writer
    //endl move the file counter to new line
    //the next line written will be in a new line
    writer<<"byee, pg was here."<<endl;

    string st;
    ifstream reader("pg.txt");//creates a reader object which is used to read from a file
    //reader>>st;//the string from the start is copied to st till space or new line or tab is encountered
    // to read a string containing newlines and spaces we use the getline function
    //getline stops reading when it encounters a new line charecter
    getline(reader, st);//reads a single line from the text file and copies it to st
    cout<< st<<endl;
    getline(reader, st);
    cout<<st;
    
    return 0;
}