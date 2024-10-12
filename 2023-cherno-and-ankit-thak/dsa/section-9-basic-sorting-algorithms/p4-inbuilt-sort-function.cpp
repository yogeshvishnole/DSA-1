/*
We have a inbuilt sort function in cpp in algorithms header file
If you dont want to remember the names of all the header files
simply include the bits/stdc++.h header file, it is master header file and includes
all other header files.
#include<bits/stdc++.h>
 */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
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
    int a[5] = {3, 1, 4, 2, 5};
    cout << "Before sorting: " << endl;
    printArray(a, 5);
    sort(a, a + 5);
    cout << "After sorting: " << endl;
    printArray(a, 5);
    vector<int> v{1, 2, 3, 4, 8}; // will take O(n) time for this alreasy sorted array
    cout << "Before sorting: " << endl;
    printVector(v);
    sort(v.begin(), v.end());
    cout << "After sorting: " << endl;
    printVector(v);
}