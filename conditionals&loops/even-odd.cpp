#include <iostream>
using namespace std;

int main()
{
    int num;
    cout << "Enter the number to find even or odd" << endl;
    cin >> num;
    if (num % 2 == 0)
    {
        cout << "even";
    }
    else
    {
        cout << "oddd";
    }
}