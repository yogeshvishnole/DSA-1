/*
Given an character arr - abcdab and an char which is already in arr = a and a newChar = x
Output replace all existingChar with newChar so - xbcdxb

 */

#include <iostream>
using namespace std;

void replaceCharacters(char arr[], char existingChar, char newChar)
{
    if (arr[0] == '\n')
        return;
    if (arr[0] == existingChar)
        arr[0] = newChar;
    replaceCharacters(arr + 1, existingChar, newChar);
}

int main(int argc, char **argv)
{
    char arr[] = "abcdab";
    cout << "Char arr before: " << arr << endl;
    replaceCharacters(arr, 'a', 'x');
    cout << "Char arr after replacing a with x: " << arr << endl;
}