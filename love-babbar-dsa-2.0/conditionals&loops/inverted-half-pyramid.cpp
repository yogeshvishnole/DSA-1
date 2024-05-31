#include <iostream>
using namespace std;

int main()
{
    int ROW = 5;
    int COL = 5;
    for (int row = 0; row < ROW; row = row + 1)
    {
        for (int col = 0; col < (COL - row); col = col + 1)
        {
            cout << "* ";
        }
        cout << endl;
    }
}