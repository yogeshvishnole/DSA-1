#include <iostream>
#include <vector>
using namespace std;

void mergeSortedArrays(int arr[], int start1, int end1, int start2, int end2)
{

    int sizeOfCombineArray = end2 - start1 + 1;

    vector<int> store(sizeOfCombineArray);

    int ar1Pointer = start1;
    int ar2Pointer = start2;
    int storePointer = 0;

    while (ar1Pointer <= end1 && ar2Pointer <= end2)
    {
        if (arr[ar1Pointer] <= arr[ar2Pointer])
        {
            store[storePointer] = arr[ar1Pointer];
            ar1Pointer++;
        }
        else
        {
            store[storePointer] = arr[ar2Pointer];
            ar2Pointer++;
        }
        storePointer++;
    }

    if (ar1Pointer <= end1)
    {
        while (ar1Pointer <= end1)
        {
            store[storePointer] = arr[ar1Pointer];
            ar1Pointer++;
            storePointer++;
        }
    }

    if (ar2Pointer <= end2)
    {
        while (ar2Pointer <= end2)
        {
            store[storePointer] = arr[ar2Pointer];
            ar2Pointer++;
            storePointer++;
        }
    }

    for (int i = start1, j = 0; i <= end2; i++, j++)
    {
        arr[i] = store[j];
    }
}

void mergeSort(int arr[], int start, int end)
{

    if (start >= end)
    {
        return;
    }

    int n = end - ((end - start) / 2);

    mergeSort(arr, start, n - 1);
    mergeSort(arr, n, end);
    mergeSortedArrays(arr, start, n - 1, n, end);
}

int main()
{
    int arr[] = {3, 6, 2, 9};

    for (auto el : arr)
    {
        cout << el << " ";
    }
    cout << endl;
    mergeSort(arr, 0, 3);
    for (auto el : arr)
    {
        cout << el << " ";
    }
    cout << endl;
}