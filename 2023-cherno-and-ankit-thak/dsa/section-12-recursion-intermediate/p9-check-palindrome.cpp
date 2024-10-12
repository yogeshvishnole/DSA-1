/*
Given input arr - [1,2,1]
Output true if arr is palindrome else false = true
Given input arr - [1,2,1,1]
Output true if arr is palindrome else false = false

 */

#include <iostream>
using namespace std;

bool isPalindrome(int arr[], int start, int end)
{
    // Base case
    if (start == end)
    {
        return true;
    }

    return arr[start] == arr[end] && isPalindrome(arr, start + 1, end - 1);
}

int main(int argc, char **argv)
{
    int arr[] = {1, 2, 1};
    int arr2[] = {1, 2, 1, 1};
    cout << "Is 121 palindrome: " << isPalindrome(arr, 0, 2) << endl;
    cout << "Is 1211 palindrome: " << isPalindrome(arr, 0, 3) << endl;
}