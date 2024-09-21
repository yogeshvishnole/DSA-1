/*

Sorting is the process of rearranging the items in a collection (e.g. an array) so that the items are in some kind of order.
Example:
- Sorting numbers from smallest to largest
- Sorting names alphabetically
- Sorting movies based on release year

There are many algorithms (and different variations of these algorithms) that can be used to sort data.

Below is the list of sorting algorithms used -
1. Bubble Sort
2. Selection Sort
3. Insertion Sort
4. Merge Sort
5. Quick Sort
6. Radix Sort
7. Counting Sort
8. Bucket Sort

In this program we will discuss about Selection Sort. */

#include <iostream>
#include <vector>
using namespace std;

int findSmallest(vector<int> &v, int startIndex, int endIndex)
{
    int smallestIndex = startIndex;
    int smallest = v[startIndex];

    for (int i = startIndex; i <= endIndex; i++)
    {

        if (v[i] < smallest)
        {
            smallest = v[i];
            smallestIndex = i;
        }
    }

    return smallestIndex;
}

void selectionSort(vector<int> &v)
{

    for (int i = 1; i < v.size(); i++)
    {
        int smallest = findSmallest(v, i, v.size() - 1);
        if (v[i - 1] > smallest)
        {
            swap(v[smallest], v[i - 1]);
        }
    }
}

void printVector(vector<int> &v)
{
    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> v{7, 5, 3, 6, 8};
    cout << "Before sorting: " << endl;
    printVector(v);
    selectionSort(v);
    cout << "After sorting: " << endl;
    printVector(v);
}
