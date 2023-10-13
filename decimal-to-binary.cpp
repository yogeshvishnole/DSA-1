#include <iostream>
#include <cmath>
using namespace std;

// string reverseString(string strToReverse)
// {
//     string reversedStr = "";
//     int strLength = strToReverse.length();
//     for (int i = strLength - 1; i >= 0; i--)
//     {
//         reversedStr += strToReverse[i];
//     }
//     return reversedStr;
// }

int decimalToBinary1(int decimalNumber)
{
    // division method
    int binary = 0;
    int i = 0;
    while (decimalNumber > 0)
    {
        int rem = decimalNumber % 2;
        binary += rem * pow(10, i++);
        decimalNumber = decimalNumber / 2;
    }
    return binary;
}

int decimalToBinary2(int n)
{
    int binary = 0;
    int i = 0;

    while (n > 0)
    {
        int bit = n & 1;
        binary += bit * pow(10, i++);
        n = n >> 1;
    }
    return binary;
}

int main()
{

    int decimalNumber;
    cout << "Enter the decimal value: " << endl;
    cin >> decimalNumber;
    cout << decimalToBinary2(decimalNumber) << endl;
}