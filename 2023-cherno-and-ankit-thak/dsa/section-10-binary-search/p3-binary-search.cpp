/*
Binary serach is efiicient algorithm to search elements sorted in arrays in O(logn) time
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// using iteration
int binarySearch(vector<int> const &v, int key)
{
    int start = 0;
    int end = v.size() - 1;

    int middle;

    while (start <= end)
    {
        int curRangeSize = end - start + 1;
        // infficient as start and end can big integers and their sum might overflow
        // from the integer range
        // so we can write (start + end)/2 in the following way = (s + (e-s)/2)
        // middle = (start + end) / 2;
        // Below is more optimized
        middle = start + (end - start) / 2;
        // if our value is greater than INT_MAX it is called overflow
        // if our value is less than INT_MIN it is called underflow

        if (v[middle] == key)
        {
            return middle;
        }
        else if (v[middle] > key)
        {

            end = middle - 1;
        }
        else
        {
            start = middle + 1;
        }
    }
    return -1;
}

int main()
{
    int size;
    cout << "Enter the size of array: ";
    cin >> size;

    vector<int> v(size);

    cout << "Enter the elements of the array: ";
    int arrayEl;
    for (int i = 0; i < size; i++)
    {
        cin >> v[i];
    }

    int key;
    cout << "Enter the key to search : ";
    cin >> key;

    int pos = binarySearch(v, key);

    if (pos != -1)
    {
        cout << "Key found at position : " << pos << endl;
    }
    else
    {
        cout << "Key not found" << endl;
    }
}