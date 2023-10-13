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

int binaryToDecimal(int binaryNumber)
{

    int decimalNumber = 0;
    int i = 0;
    while (binaryNumber > 0)
    {
        int bit = binaryNumber % 10;
        decimalNumber += pow(2, i++) * bit;
        binaryNumber = binaryNumber / 10;
    }

    return decimalNumber;
}

// int binary(int n)
// {
//     int binary = 0;
//     int i = 0;

//     while (n > 0)
//     {
//         int bit = n & 1;
//         binary += bit * pow(10, i++);
//         n = n >> 1;
//     }
//     return binary;
// }

int main()
{

    int decimalNumber;
    cout << "Enter the binary value: " << endl;
    cin >> decimalNumber;
    cout << binaryToDecimal(decimalNumber) << endl;
}