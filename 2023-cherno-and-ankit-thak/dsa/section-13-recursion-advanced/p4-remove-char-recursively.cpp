/*
Given input arr = abcda, and a existing char = a
Output we have to remove th existing character from the array
 */

#include <iostream>
using namespace std;

void removeChar(char arr[], char existingChar)
{
    // Base case

    if (arr[0] == '\0')
        return;

    if (arr[0] == existingChar)
    {
        for (int i = 0; arr[i] != '\0'; i++)
        {
            arr[i] = arr[i + 1];
        }
        removeChar(arr, existingChar);
    }
    else
    {
        removeChar(arr + 1, existingChar);
    }
}

int main(int argc, char **argv)
{
    char arr[] = "abcda";
    cout << "String before removing a: " << arr << endl;
    removeChar(arr, 'a');
    cout << "String after removing a: " << arr << endl;
}