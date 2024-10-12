/*

Understanding the question - Given a strig abcd, find its all prefixes
Input abcd
Ouput will be a,ab,abc,abcd.
Input yogesh
Output - y,yo,yog,yoge,yoges,yogesh

 */

#include <iostream>
#include <cstring>
using namespace std;

// my o(n2) solution space O(1)
void printPrefixes1(char str[])
{
    int strLen = strlen(str);
    for (int i = 0; i < strLen; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << str[j];
        }
        cout << endl;
    }
}

// my O(n) solution with O(n) space
void printPrefixes2(char str[])
{
    // are easy he, create a new string as same length of original and append characters one by one and print
    char strTemp[100];
    int strLen = strlen(str);
    for (int i = 0; i < strLen; i++)
    {

        strTemp[i] = str[i];
        strTemp[i + 1] = '\0';
        cout << strTemp << endl;
    }
}

int main()
{
    char str[100];
    cout << "Enter the str: ";
    cin >> str;
    cout << "Below are all the prefixes of str: " << endl;
    printPrefixes2(str);
}