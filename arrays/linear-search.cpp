#include <iostream>
using namespace std;

int linearSearch(int elemToFind, int arr[], int n)
{
    for (int i; i < n; i++)
    {
        if (arr[i] == elemToFind)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    int arr[5] = {3, 9, 4, 1, 6};
    cout << linearSearch(0, arr, 5) << endl;
}