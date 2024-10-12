/*
Review the docs from the goodnotes
 */
#include <iostream>
using namespace std;

int searchInRotatedSortedArray(int arr[], int size, int target)
{
    int start = 0;
    int end = size - 1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        // condition if mid lies in upper part of graph
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] > arr[start])
        {
            if (target <= arr[mid] && target >= arr[start])
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        else
        {
            // condition if mid lies in lower part of graph
            if (target >= arr[mid] && target <= arr[end])
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
    }
    return -1;
}

int main(int argc, char **argv)
{
    int arr[] = {3, 4, 5, 1, 2};
    // Lets find 4
    cout << "1 finds at index : " << searchInRotatedSortedArray(arr, 5, 1) << endl;
    // Lets find 9
    cout << "9 finds at index : " << searchInRotatedSortedArray(arr, 5, 9) << endl;
}
