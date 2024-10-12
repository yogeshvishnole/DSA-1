/*
Given input  string - ABC
Print all its permutations -
ABC
ACB
BAC
BCA
CAB
CBA
 */

#include <iostream>
using namespace std;

void printPermutations(char arr[], int i = 0)
{

    // Base case
    if (arr[i] == '\0')
    {
        cout << arr << endl;
    }

    for (int j = i; arr[j] != '\0'; j++)
    {
        swap(arr[i], arr[j]);
        printPermutations(arr, i + 1);
        swap(arr[j], arr[i]);
    }
}

int main()
{
    char arr[] = "ABC";
    printPermutations(arr);
}