#include <iostream>
using namespace std;

int main()
{
    int row = 5;
    int col = 17;

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < ((col - 1) / 2) - i; j++)
        {
            cout << "*";
        }
        for (int j = 0; j < 2 * i + 1; j++)
        {
            if (j % 2 == 0)
            {
                cout << i + 1;
            }
            else
            {
                cout << "*";
            }
        }
        for (int j = 0; j < ((col - 1) / 2) - i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}