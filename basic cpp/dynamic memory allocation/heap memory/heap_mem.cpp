#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int *p = new int; // allocates 4 bytes in heap memory and the assignd that address to pointer p
    *p = 10;
    cout << *p << endl;
    delete p;

    // array of variable lenght
    int n;
    cout << "enter the number of elements required in the array: ";
    cin >> n;
    int *arr1 = new int[n];
    delete[] arr1;

    // 2-D array in heap
    int x, y;
    int i, j;
    cout << "enter the number of rows: ";
    cin >> x;
    cout << "enter the number of columns: ";
    cin >> y;
    int **arr_2D = new int *[x];
    for (i = 0; i < x; i++)
    {
        arr_2D[i] = new int[y];
        for (j = 0; j < y; j++)
        {
            printf("enter the (%d,%d) element: ", i, j);
            cin >> arr_2D[i][j];
        }
    }

    for (i = 0; i < x; i++)
    {
        for (j = 0; j < y; j++)
        {
            printf("(%d,%d) element is: ", i, j);
            cout << arr_2D[i][j] << endl;
        }
    }

    for (i = 0; i < x; i++)
    {
        delete[] arr_2D[i];
    }
    delete[] arr_2D;

    
    return 0;
}