#include <iostream>
using namespace std;

int main()
{
    cout << "Rectangle Pattern" << endl;

    // outer loop shows rows logic
    for (int i = 0; i < 3; i++)
    {
        // print 5 stars
        for (int j = 0; j < 5; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}