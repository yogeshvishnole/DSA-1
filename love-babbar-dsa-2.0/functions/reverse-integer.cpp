#include <iostream>
#include <cmath>
using namespace std;

int reverse(int x)
{
    int reverse = 0;
    while (x)
    {
        int digit = x % 10;
        // reverse += digit * pow(10, count);se
        reverse = reverse * 10 + digit;

        // count++;
        x = x / 10;
    }
    return reverse;
}

int main()
{
    cout << reverse(321) << endl;
}