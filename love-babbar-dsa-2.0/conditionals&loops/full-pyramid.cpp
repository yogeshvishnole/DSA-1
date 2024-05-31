#include <iostream>
using namespace std;

int main()
{

    int n;
    cin >> n;

    int R = n;
    int C = 2 * n - 1;
    int gap = n - 1;
    int count = 1;

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (j >= gap && j <= (gap + count - 1))
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
        gap = gap - 1;
        count = count + 2;
    }
}