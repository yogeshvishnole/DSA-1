#include <iostream>
using namespace std;

bool isEven(int n)
{
    if (n & 1 == 1)
        return 0;
    else
        return 1;
}

int main()
{
    cout << "Enter the number : " << endl;

    int number;
    cin >> number;

    cout << isEven(number) << endl;
}