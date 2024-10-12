/*
Given a string str = "12345"
Output an integer = 12345
Simply convert a string to integer
 */

#include <iostream>
#include <cmath>
using namespace std;

int stringToInteger(string str)
{
    // Base case
    if (str.length() == 0)
    {
        return 0;
    }

    // Recursion
    int smallAns = stringToInteger(str.substr(1));

    // Calculation
    int firstDigit = str[0] - '0';
    int multiplier = 1;
    // I am mmanually calculating powe rof 10 because pow function return floating
    // point number but I needed the integer
    for (int i = 1; i < str.length(); i++)
    {
        multiplier *= 10;
    }

    return (firstDigit * multiplier) + smallAns;
}

int main()
{
    string str = "12345";
    int strToInt = stringToInteger(str);
    cout << strToInt << endl;
}