/*

Problem - Find the sum of digits using the recursion
Input 12345
Ouput = 1+2+3+4+5 = 15

Input 402
Output = 4+0+2 = 6

constraint n>=1

 */

#include <iostream>
using namespace std;

int sumOfDigits(int n)
{
    if (n / 10 == 0)
        return n;

    int remainder = n % 10;

    return remainder + sumOfDigits(n / 10);
}

int main(int arc, char **argv)
{
    cout << "sum of digits in  4025 is: " << sumOfDigits(4025) << endl;
    cout << "sum of digits in  40256 is: " << sumOfDigits(40256) << endl;
    cout << "sum of digits in  0 is: " << sumOfDigits(0) << endl;
}