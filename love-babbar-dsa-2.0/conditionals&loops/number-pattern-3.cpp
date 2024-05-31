#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            char ch = 64 + j + 1;
            cout << ch;
        }

        for (int j = 0; j < i; j++)
        {
            char ch = 64 + i - j;
            cout << ch;
        }
        cout << endl;
    }
}