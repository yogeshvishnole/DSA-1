/*
Merge sort is an advance sortiuing algorithm with an impressive time complexoity of
n*logn. How merge sort works, we divide the array in two parts until we get array of single sizes
now we know that single size arrays are sorted, then we merge that sortes arrays which has time
complexity of O(n),means for n inputs n steps are involved.Now for each break n steps are taken
now our array is breaked into how many small arrays =
n/2 then n/4 the n/8 .... n/2^k
where k is the no. of step
now n/2^k = 1(size of array)
then n = 2^k
takibg log of base 2 on both sides
logn = log2^k
logn = k*log2 (loga^b = alogb)
logn = k (log2 == 1)
k = logn
so we break array  into k small arrays
so to merge eash k arrays we need n steps
so time complexitry of merge sort == n*logn
 */

#include <iostream>
using namespace std;

void mergeArray(int arr[], int s1, int e1, int s2, int e2)
{
    int p1 = s1;
    int p2 = s2;
    int helperArr[e2 + 1];
    int i = 0;
    while (p1 <= e1 && p2 <= e2)
    {
        if (arr[p1] < arr[p2])
        {
            helperArr[i] = arr[p1];
            p1++;
        }
        else
        {
            helperArr[i] = arr[p2];
            p2++;
        }
        i++;
    }

    if (p1 <= e1)
    {
        for (int j = p1; j <= e1; j++)
        {
            helperArr[i] = arr[j];
            i++;
        }
    }
    else
    {
        for (int j = p2; j <= e2; j++)
        {
            helperArr[i] = arr[j];
            i++;
        }
    }

    for (int k = s1, b = 0; k <= e2; k++, b++)
    {
        arr[k] = helperArr[b];
    }
    // for (int g = 0; g < i; g++)
    // {
    //     cout << helperArr[g] << " ";
    // }
    // cout << endl;
}

void mergeSort(int arr[], int start, int end)
{
    if (start >= end)
    {
        return;
    }

    int mid = ((end - start) / 2) + start;

    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);
    mergeArray(arr, start, mid, mid + 1, end);
    // cout << start << " " << mid << " " << end << endl;
    // for (int i = 0; i < 6; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;
}

int main(int argc, char **argv)
{
    /*   // mergin array demo
      // Time complexity = O(n)
      // Space complexity = O(n) (because of the auxiliary array)
      int arr[] = {3, 4, 9, 5, 7, 8};
      for (int i = 0; i < 6; i++)
      {
          cout << arr[i] << " ";
      }
      cout << endl;
      mergeArray(arr, 0, 2, 3, 5);
      for (int i = 0; i < 6; i++)
      {
          cout << arr[i] << " ";
      }
      cout << endl; */

    // merge sort demo
    int arr2[] = {5, 9, 7, 8, 4};
    for (int i = 0; i < 5; i++)
    {
        cout << arr2[i] << " ";
    }
    cout << endl;
    mergeSort(arr2, 0, 4);
    for (int i = 0; i < 5; i++)
    {
        cout << arr2[i] << " ";
    }
    cout << endl;
}
