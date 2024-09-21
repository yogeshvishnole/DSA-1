#include <iostream>
#include <vector>
using namespace std;

// 2d arrays for low level design of games like Tic Tac Toe, chess etc

int main()
{
    // desclaration
    // int arr[row][col]
    int arr[3][4];

    // Taking row wise input in the 2d array
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> arr[i][j];
        }
    }

    // row wise printing the 2D array
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // column wise printing the 2D array
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << arr[j][i] << " ";
        }
        cout << endl;
    }
}