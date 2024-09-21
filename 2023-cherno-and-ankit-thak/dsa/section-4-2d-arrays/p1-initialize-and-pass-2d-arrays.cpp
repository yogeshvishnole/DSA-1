/*

Key points -

1. While initilizing a 2D arrays giving number of rows is optional but giving number of columns is mandatory (due to internal storage of 2d arrays)
2. Smae applies when passing 2D arrays to functions


 */

#include <iostream>
using namespace std;

void printArray(int arr[][4], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{

    /*    // initialize a 2D array

       int arr[][4] = {
           {1, 2, 3, 4},
           {5, 6, 7, 8}};

       printArray(arr, 2, 4); */
    /*
        // initilize the complete 2D array with 0's

        int arr[4][4] = {{0}};

        printArray(arr, 4, 4); */
}