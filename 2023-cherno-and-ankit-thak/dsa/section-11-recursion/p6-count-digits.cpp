/*
Problem Count no. of digits in a number
Input = 4025
Output = 4
Input 403
Ouput = 3

Questions will numbewr can be negative Ans No

 */

#include <iostream>
using namespace std;

int countDigits(int n)
{
    // Base Case
    if (n / 10 == 0)
    {
        return 1;
    }

    return 1 + countDigits(n / 10);
}

int main(int arc, char **argv)
{
    cout << "Number of digits in  4025 is: " << countDigits(4025) << endl;
    cout << "Number of digits in  40256 is: " << countDigits(40256) << endl;
    cout << "Number of digits in  0 is: " << countDigits(0)<<endl;
}