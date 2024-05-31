#include <iostream>
using namespace std;

int main()
{

    int ROWS = 40;
    int COLS = 41;

    for (int row = 0; row < ROWS; row++)
    {
        for (int col = 0; col < COLS; col++)
        {
            if (row == 0 || col == 0 || col == ROWS - row - 1)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }
}