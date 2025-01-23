#include <iostream>
#include <vector>
using namespace std;

void inplaceHeapSort(vector<int> &array)
{
    // Lets first convert the array into the min heap

    for (int i = 0; i < array.size(); i++)
    {
        int curIndex = i;
        while (curIndex > 0)
        {
            int curParentIndex = (curIndex - 1) / 2;
            if (array[curParentIndex] > array[curIndex])
            {
                swap(array[curParentIndex], array[curIndex]);
                curIndex = curParentIndex;
            }
            else
            {
                break;
            }
        }
    }

    // now lets remove the min and insert at correct position
    for (int i = 0; i < array.size(); i++)
    {
        swap(array[0], array[array.size() - i - 1]);
        // lets down heapify
        int lastIndex = array.size() - i - 1;

        int curParentIndex = 0;
        while (true)
        {
            int minIndex = curParentIndex;
            int leftIndex = 2 * minIndex + 1;
            int rightIndex = 2 * minIndex + 2;

            if (leftIndex < lastIndex && array[leftIndex] < array[minIndex])
            {
                minIndex = leftIndex;
            }

            if (rightIndex < lastIndex && array[rightIndex] < array[minIndex])
            {
                minIndex = rightIndex;
            }

            if (minIndex == curParentIndex)
                break;

            swap(array[curParentIndex], array[minIndex]);
        }
    }
}

int main()
{
    vector<int> v{9, 3, 5, 11, 2, 1};
    cout << "Before sorting : " << endl;
    for (int item : v)
    {
        cout << item << " ";
    }
    cout << endl;
    inplaceHeapSort(v);
    cout << "After sorting : " << endl;
    for (int item : v)
    {
        cout << item << " ";
    }
    cout << endl;
}
