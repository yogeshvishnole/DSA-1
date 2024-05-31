#include <iostream>
using namespace std;

int main()
{
    int n;
    if (cin >> n)
    {
        cout << "Yogesh" << endl;
    }
    if (cout << n)
    {
        cout << "Yogesh" << endl;
    }
    int ROW = 5;
    int COL = 5;
    for (int row = 0; row < ROW; row = row + 1)
    {
        for (int col = 0; col < COL - row; col = col + 1)
        {
            cout << col + 1;
        }
        cout << endl;
    }
}