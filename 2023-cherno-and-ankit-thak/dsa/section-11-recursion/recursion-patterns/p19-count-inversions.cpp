/*
https://takeuforward.org/data-structure/count-inversions-in-an-array/
*/

#include <iostream>
using namespace std;

int merge(int arr[], int start1, int end1, int start2, int end2)
{
    int count = 0;
    int ansArr[end2 - start1 + 1];
    int i = start1;
    int j = start2;
    int k = 0;
    while (i <= end1 && j <= end2)
    {
        if (arr[i] <= arr[j])
        {
            ansArr[k] = arr[i];
            i++;
        }
        else
        {
            ansArr[k] = arr[j];
            j++;
            count += end1 - i + 1;
        }
        k++;
    }

    while (i <= end1)
    {
        ansArr[k] = arr[i];
        i++;
        k++;
    }
    while (j <= end2)
    {
        ansArr[k] = arr[j];
        j++;
        k++;
    }

    for (int i = start1; i <= end2; i++)
    {
        arr[i] = ansArr[i - start1];
    }
    return count;
}

int mergeSort(int arr[], int start, int end)
{
    int count = 0;
    if (end <= start)
    {
        return count;
    }
    int mid = start + (end - start) / 2;
    count += mergeSort(arr, start, mid);
    count += mergeSort(arr, mid + 1, end);
    count += merge(arr, start, mid, mid + 1, end);
    return count;
}

int countInversions(int arr[], int n)
{
    int ans = mergeSort(arr, 0, n - 1);
    return ans;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;
    cout << countInversions(arr, n) << endl;
}