#include <iostream>
using namespace std;

int main()
{
    cout << "Square Pattern" << endl;

    // outer loop shows rows logic
    for (int i = 0; i < 4; i++)
    {
        // print 4 stars
        for (int j = 0; j < 4; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}