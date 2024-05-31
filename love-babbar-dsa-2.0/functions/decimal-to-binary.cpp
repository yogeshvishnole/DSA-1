#include <iostream>
#include <cmath>
using namespace std;

int decimalToBinary(int n)
{

    int num = 0;
    int i = 0;
    while (n > 0)
    {
        num += (n % 2) * pow(10, i);
        n = n / 2;
        i++;
    }
    return num;
}

int main()
{
    int n;
    cin >> n;
    cout << decimalToBinary(n) << endl;
}