/*
Quick sort

It is also an advanced sorting algorithm
It works as follows select any element as pivot index, as per my preference I will select
last element as pivot element. Now swap the  position of pivot element with the element, which
is at the posititon of pivot element in the sorted version of the array.
For example we have an array -
5,9,3,7,8,4 My pivot element = 4, Now sorted version of this array is 3,4,5,7,8,9
so I will swap 4 with 9 because index 1 is the position of pivot element 4 in the sorted
array.

now after that our array will look like -
5,4,3,7,8,9

Now we need to partition our array around the pivot element, all the elements which are smaller
than pivot must come to its left and all elements greater than that come to its right.So, our
array after partionining will look like this -
3,4,5,7,8,9
So, our two partitions are -
3
AND 5,7,8,9
Now sort the above two partions using recursion and finally our array will become sorted.

 */

#include <iostream>
using namespace std;

// This function will find the position of the pivot element
// partition the elements around that into smaller and greater groups
int partition(int arr[], int start, int end)
{
    int pivotPos = 0;
    for (int i = start; i < end; i++)
    {
        if (arr[i] < arr[end])
        {
            pivotPos++;
        }
    }

    pivotPos = start + pivotPos;
    swap(arr[pivotPos], arr[end]);

    int first = start;
    int last = end;

    while (first <= pivotPos && last >= pivotPos)
    {
        if (arr[first] > arr[pivotPos])
        {
            swap(arr[first], arr[last]);
        }
        else
        {
            first++;
        }
        if (arr[last] < arr[pivotPos])
        {
            swap(arr[last], arr[first]);
        }
        else
        {
            last--;
        }
    }
    // cout << pivotPos << " ";
    return pivotPos;
}

void quickSort(int arr[], int start, int end)
{
    if (start >= end)
    {
        return;
    }

    int pivot = partition(arr, start, end);
    quickSort(arr, start, pivot - 1);
    quickSort(arr, pivot + 1, end);
}

int main(int argc, char **argv)
{
    // quick sort demo
    int arr2[] = {5, 9, 3, 7, 8, 4};
    for (int i = 0; i < 5; i++)
    {
        cout << arr2[i] << " ";
    }
    cout << endl;
    quickSort(arr2, 0, 4);
    for (int i = 0; i < 5; i++)
    {
        cout << arr2[i] << " ";
    }
    cout << endl;
}