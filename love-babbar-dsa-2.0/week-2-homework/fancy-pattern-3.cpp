#include <iostream>
using namespace std;

int main()
{

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int growingCount = 1;
        int shrinkingCount;
        for (int j = 0; j < (2 * i + 1); j++)
        {
            if (j == 0 || j == (2 * i))
            {
                cout << "*";
            }
            else if (growingCount <= i)
            {
                cout << growingCount;
                growingCount++;
                if (growingCount == i)
                {
                    shrinkingCount = growingCount - 1;
                }
            }
            else
            {
                cout << shrinkingCount;
                shrinkingCount--;
            }
        }
        cout << endl;
    }

    for (int i = 0; i < n - 1; i++)
    {
        int growingCount = 1;
        int shrinkingCount;
        for (int j = 0; j < (2 * n - 2 * i - 3); j++)
        {
            if (j == 0 || j == (2 * n - 2 * i - 4))
            {
                cout << "*";
            }
            else if (growingCount <= (n - 2 - i))
            {
                cout << growingCount;
                growingCount++;
                if (growingCount == (n - 2 - i))
                {
                    shrinkingCount = growingCount - 1;
                }
            }
            else
            {
                cout << shrinkingCount;
                shrinkingCount--;
            }
        }
        cout << endl;
    }
}