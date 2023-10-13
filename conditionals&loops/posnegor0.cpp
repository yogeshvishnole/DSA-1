#include <iostream>
using namespace std;

int main()
{
    int number;

    cin >> number;

    if (number > 0)
    {
        cout << "positive";
    }
    else if (number < 0)
    {
        cout << "negative";
    }
    else
    {
        cout << "0";
    }
}