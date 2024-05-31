#include <iostream>
using namespace std;

int main()
{
    int ROW = 5;
    int COL = 5;

    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            cout << j + 1 << " ";
        }
        cout << endl;
    }
}