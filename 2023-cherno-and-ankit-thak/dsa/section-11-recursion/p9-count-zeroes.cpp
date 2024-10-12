/*
Given a number
Input - 10320
Output - the number of zeroes in the input number = 2

 */

#include <iostream>
using namespace std;

int countZeroes(int number)
{
    // Base Case
    if (number == 0)
        return 0;

    int remainder = number % 10;
    int smallNumber = number / 10;

    if (remainder == 0)
        return 1 + countZeroes(smallNumber);
    else
        return countZeroes(smallNumber);
}

int main(int argc, char **argv)
{
    cout << "Number of zeroes in 10320 is : " << countZeroes(10320) << endl;
}