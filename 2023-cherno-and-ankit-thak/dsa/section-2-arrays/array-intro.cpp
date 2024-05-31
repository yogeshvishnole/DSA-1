// In c++ an array is a linear data structure which stores data of same type in contagious blocks on memory.
/*
If I have to store marks of 100 students of a class. with variable I have to declare 100 variables as-
int marks1,marks2,marks3...,marks100;
instead I can declare an array.

And int variable is a memory space or box of 4 bytes.
An array of size 100 is 100 contagious blocks of memory space each of size 4 bytes in cpp.
Blocks of array are numbered from 0 to n-1 (n is number of elements in array)
*/
#include <iostream>
using namespace std;

int main()
{
    // declaration of array of size 100
    int a[100];

    // adding data/values in array
    a[0] = 1;
    a[1] = 2;
    // printing arrays data / normal way
    cout << a[0] << endl
         << a[1] << endl
         << a[2] << endl;

    // if we give values to array in above way the remaining blocks of array which does not have any value got gibrish values.

    // Now declartion and intialization of array together

    int b[4] = {1, 2, 3};
    cout << "Array b values" << endl;
    cout << b[0] << " " << b[1] << " " << b[2] << " " << b[3] << endl;

    // if we initalize array in above way the blocks of array which does not get any values assigned will be initialized to zero.

    // Now above way of printing array value is not efficient as we have to write each of them so
    // efficient way is looping as -

    int c[10] = {99, 100};
    int cLen = 10;

    cout << "Printing array c" << endl;

    for (int i = 0; i < cLen; i++)
    {
        cout << c[i] << " ";
    }

    // If we not initialize array , array values will be initialized with garbage values , just like a single variabke

    int d[10];
    int dLen = 10;

    cout << "Printing array d" << endl;
    for (int i = 0; i < dLen; i++)
    {
        cout << d[i] << " ";
    }

    // lets fill and then print the array

    int e[10];

    int eLen = 10;
    cout << endl
         << "Printing array e" << endl;

    for (int i = 0; i < eLen; i++)
    {
        e[i] = i * i;
        cout << e[i] << " ";
    }

    /// size of a variable vs an array

    int testSizeVar = 10;
    cout << endl
         << "SIze of testSizeVar " << sizeof(testSizeVar) << endl;

    int f[10] = {1};

    cout << endl
         << "SIze of f array " << sizeof(f) << endl;
}