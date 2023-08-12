#include<iostream>
using namespace std;
/*void swap (char *x, char *y) 
{
  char *t = x;
  x = y;
  y = t;
}

int main()
{
   char *x = "geeksquiz";
   char *y = "geeksforgeeks";
   char *t;
   swap(x, y);
   cout<<x << " "<<y;
   t = x;
   x = y;
   y = t; 
   cout<<" "<<x<< " "<<y;
   return 0;
}*/

/*int main()
{
  int i=65;
  char c= i;

  int * p=&i;
  char * pc= (char *) p;
  cout<<p<<endl;
  cout<<pc<<endl;
  cout<<*p<<endl;
  cout<<*pc<<endl;
  cout<<*(pc+1)<<endl;
  cout<<*(pc+2)<<endl;
  cout<<*(pc+3)<<endl;



  return 0;
}*/

void updateValue(int *p){
    *p = 610 % 255;
}

int main(){
    char ch = 'A';
    updateValue((int*)&ch);
    cout << ch;
    return 0;

}