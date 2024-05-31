#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int count = 1;
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < (2 * i + 1); j++)
        {
            if (j % 2 == 0)
            {
                cout << count;
                count++;
            }
            else
            {
                cout << "*";
            }
        }
        cout << endl;
    }

    count = n * (n + 1) / 2;
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < (2 * (n - 1 - i) + 1); j++)
        {
            if (j % 2 == 0)
            {
                cout << count - (n - 1 - j / 2);
            }
            else
            {
                cout << "*";
            }
        }
        count = count - (n - 1 - i);
        cout << endl;
    }
}