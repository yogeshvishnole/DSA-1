/*
Given array -
5,4,3,2,1
We need to find if 2 is present in given array if yes return its index
and is 7 is present in the array if present return index otherwise return -1\

We will solve the above problem using the linear search
Approach -> loop through the whole array and find if any key is matches the target

Time complexity = O(n)
Space complexity = O(1)

 */
#include <iostream>
#include <vector>
using namespace std;

int linearSearch(vector<int> &v, int target)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == target)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int size;
    cout << "Enter the size of array: ";
    cin >> size;

    vector<int> v(size);

    cout << "Enter the elements of the array: ";
    int arrayEl;
    for (int i = 0; i < size; i++)
    {
        cin >> v[i];
    }

    int key;
    cout << "Enter the key to search : ";
    cin >> key;

    int pos = linearSearch(v, key);

    if (pos != -1)
    {
        cout << "Key found at position : " << pos << endl;
    }
    else
    {
        cout << "Key not found" << endl;
    }
}