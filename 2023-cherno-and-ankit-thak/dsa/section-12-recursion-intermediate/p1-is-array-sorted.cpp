/*
Given input - an arr [1,2,3,4,5]
Output - if input array is sorted or not = true
input - [7,2,3,4,5]
oyput - false
 */

#include <iostream>
using namespace std;

// by minimizing the array by removing end elements
bool isArraySorted(int arr[], int size)
{

    // Base case
    if (size == 1)
        return true;

    if (arr[size - 1] > arr[size - 2])
    {
        return true && isArraySorted(arr, size - 1);
    }
    else
        return false;
}

// by minimizing the array by removing starting elements
bool isArraySorted2(int arr[], int size)
{
    if (size == 1)
        return true;

    if (arr[0] < arr[1])
        return isArraySorted2(arr + 1, size - 1);
    else
    {
        return false;
    }
}

int main(int arc, char **argv)
{
    int arr[] = {1, 2, 3, 4, 5};
    cout << isArraySorted2(arr, 5) << endl;
}