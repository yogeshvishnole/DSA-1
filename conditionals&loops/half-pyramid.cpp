#include <iostream>
using namespace std;

int main()
{

    int ROWS = 5;
    int COLS = 5;

    for (int row = 0; row < ROWS; row = row + 1)
    {

        for (int col = 0; col < COLS; col = col + 1)
        {

            if (col <= row)
            {
                cout << "* ";
            }
            else
            {
                cout << "  ";
            }
        }
        cout << endl;
    }
}