#include <iostream>
using namespace std;

int main()
{
    // outer loop row
    for (int i = 0; i < 3; i++)
    {

        for (int j = 0; j < 5; j++)
        {
            if (i == 0 || i == 2)
            {
                cout << "* ";
            }
            else if (j == 0 || j == 4)
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