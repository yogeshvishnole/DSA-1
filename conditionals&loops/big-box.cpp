#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int ROW = n / 2;
    int COL = n + 1;

    int gap = 1;
    int count = 2 * n;

    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            int gapStart = n / 2 - i;
            int gapCount = 2 * i + 1;

            if (j >= gapStart && j <= gapStart + gapCount - 1)
            {
                cout << " ";
            }
            else
            {
                cout << "*";
            }
        }
        cout << endl;
    }
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            int gapStart = i + 1;
            int gapCount = n - 2 * i - 1;

            if (j >= gapStart && j <= gapStart + gapCount - 1)
            {
                cout << " ";
            }
            else
            {
                cout << "*";
            }
        }
        cout << endl;
    }
}