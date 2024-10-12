/*
Given Input array - [5,5,6,5,5,6],k=5
Output last index of k in array - 4

Given Input array - [5,5,6,5,5,6],k=6
Output first index of k in array - 5

We will use iterative recursion approach here
 */
#include <iostream>
using namespace std;

// moving from end to start
int lastIndex(int arr[], int size, int el, int i)
{
    if (i == -1)
        return -1;
    if (arr[i] == el)
        return i;
    return lastIndex(arr, size, el, i - 1);
}

// without using the iterator and moving from end to start
int lastIndex2(int arr[], int size, int el)
{
    if (size == 0)
        return -1;
    if (arr[size - 1] == el)
        return size - 1;
    return lastIndex2(arr, size - 1, el);
}

// with using the iterator but moving from start to end
int lastIndex3(int arr[], int size, int el, int i)
{
    if (i == size)
        return -1;
    int index = arr[i] == el ? i : -1;

    int indexInReArr = lastIndex3(arr, size, el, i + 1);

    return indexInReArr == -1 ? index : indexInReArr;
}

int main(int argc, char **argv)
{
    int arr[] = {5, 5, 6, 5, 5, 6};
    cout << "Last index of 5 is: " << lastIndex(arr, 6, 5, 5) << endl;
    cout << "Last index of 5 is: " << lastIndex2(arr, 6, 5) << endl;
    cout << "Last index of 5 is: " << lastIndex3(arr, 6, 5, 0) << endl;
    cout << "Last index of 1 is: " << lastIndex3(arr, 6, 1, 0) << endl;
    cout << "Last index of 6 is: " << lastIndex(arr, 6, 6, 5) << endl;
    cout << "Last index of 6 is: " << lastIndex2(arr, 6, 6) << endl;
    cout << "Last index of 6 is: " << lastIndex3(arr, 6, 6, 0) << endl;
    cout << "Last index of 1 is: " << lastIndex3(arr, 6, 1, 0) << endl;
}