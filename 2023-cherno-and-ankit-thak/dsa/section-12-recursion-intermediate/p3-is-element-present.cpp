/*

Given an array = [1,2,3,4,5]
Output is 5 present in array - true

Given an array  = [2,3,4,6,7]
Output is 5 present in array - false

 */

#include <iostream>
using namespace std;

bool isElementPresent(int *arr, int size, int key)
{
    // Base case
    if (size == 1)
    {
        if (arr[0] == key)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // recursive case
    bool smallAns = isElementPresent(arr, size - 1, key);

    // calculation
    return smallAns ? smallAns : arr[size - 1] == key;
}

bool isElementPresent2(int *arr, int size, int key)
{
    // Base case
    if (size == 1)
    {
        if (arr[0] == key)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // recursive case
    bool smallAns = isElementPresent(arr + 1, size - 1, key);

    // calculation
    return smallAns ? smallAns : arr[0] == key;
}

// simulation of iterative approach in recursion
bool isElementPresent3(int *arr, int size, int key, int i)
{
    if (i == size)
    {
        return false;
    }
    if (arr[i] == key)
        return true;

    return isElementPresent3(arr, size, key, i + 1);
}

int main(int argc, char **argv)
{
    int arr[] = {1, 2, 3, 4, 5};
    cout << isElementPresent(arr, 5, 2) << endl;
    cout << isElementPresent2(arr, 5, 2) << endl;
    cout << isElementPresent3(arr, 5, 2, 0) << endl;
    cout << isElementPresent(arr, 5, 6) << endl;
    cout << isElementPresent2(arr, 5, 6) << endl;
    cout << isElementPresent3(arr, 5, 6, 0) << endl;
}