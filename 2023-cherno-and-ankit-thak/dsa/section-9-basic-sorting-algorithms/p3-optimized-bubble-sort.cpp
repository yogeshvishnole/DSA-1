/*

We have two arrays -

4,3,5,1,2
And another
1,2,3,4,5 -> already sorted
If we give both array to bubble sort function of previous file it will take O(n2) time
for both sorted array and unsorted arrays, so we need to optimize this to O(n) for
already sorted array. It is possible to do so by counting the no. of swaps if no swap in
a cycle means the arrays is already sorted we will stop our further swap cycles or bubbling
cycles.
 */
#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int> &v)
{

    for (int i = 0; i < v.size() - 1; i++)
    {
        int flag = 0;
        for (int j = 0; j < v.size() - 1 - i; j++)
        {
            if (v[j] > v[j + 1])
            {
                swap(v[j], v[j + 1]);
                flag = 1;
            }
        }

        if (flag == 0)
        {
            break;
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
    vector<int> v{1, 2, 3, 4, 8}; // will take O(n) time for this alreasy sorted array
    cout << "Before sorting: " << endl;
    printVector(v);
    bubbleSort(v);
    cout << "After sorting: " << endl;
    printVector(v);
}
