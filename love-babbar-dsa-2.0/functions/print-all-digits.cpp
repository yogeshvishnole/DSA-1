#include <iostream>
using namespace std;

void printDigits(int number)
{

    cout << "Digits are as follows : " << endl;
    while (number > 0)
    {
        int digit = number % 10;
        number = number / 10;
        cout << digit << endl;
    }
}

int main()
{
    int number;
    cin >> number;

    printDigits(number);
}