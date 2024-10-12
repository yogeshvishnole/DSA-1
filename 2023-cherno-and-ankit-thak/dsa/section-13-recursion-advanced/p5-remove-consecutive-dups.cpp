/*
Given input char arr = aabbbcdda
Output arr = abcda, we have to remove consecutive duplicates from the arr
 */

#include <iostream>
using namespace std;

void removeConsecutiveDups(char arr[])
{
    if (arr[0] == '\0' || arr[1] == '\0')
        return;

    if (arr[1] == arr[0])
    {
        for (int i = 0; arr[i] != '\0'; i++)
        {
            arr[i] = arr[i + 1];
        }
        removeConsecutiveDups(arr);
    }
    else
    {
        removeConsecutiveDups(arr + 1);
    }
}

int main(int argc, char **argv)
{
    char arr[] = "aabbbcdda";
    cout << "Char arr before removing consecutive dups: " << arr << endl;
    removeConsecutiveDups(arr);
    cout << "Char arr after removing the consecutive dups: " << arr << endl;
}