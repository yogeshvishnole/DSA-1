#include <iostream>
using namespace std;

int partition(int arr[], int start, int end)
{

    // choose any element as pivot element I choose the middle element as pivot element
    int pivotEl = end - (end - start) / 2;

    int startp = start;
    int endp = end;

    // place the pivot element at its sortec position

    while (startp < endp)
    {
        while (arr[startp] <= arr[pivotEl] && startp <= end - 1)
        {
            startp++;
        }
        while (arr[endp] > arr[pivotEl] && endp >= start + 1)
        {
            endp--;
        }
        if (startp < endp)
        {
            swap(arr[startp], arr[endp]);
        }
    }
    swap(arr[endp], arr[pivotEl]);

    return endp;
}

void quickSort(int arr[], int start, int end)
{

    if (start >= end)
    {
        return;
    }

    int partitionIndex = partition(arr, start, end);

    // sort the next two partitions
    quickSort(arr, start, partitionIndex - 1);
    quickSort(arr, partitionIndex + 1, end);
}

int main()
{
    int arr[] = {
        3,
        2,
        2,
        9,
        5};

    for (auto el : arr)
    {
        cout << el << " ";
    }
    cout << endl;
    quickSort(arr, 0, 5);
    for (auto el : arr)
    {
        cout << el << " ";
    }
    cout << endl;
}