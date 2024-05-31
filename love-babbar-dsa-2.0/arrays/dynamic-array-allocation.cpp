#include <iostream>
using namespace std;

void printArray(int arr[], int n)
{
    cout << "Array elements are " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
}

int main()
{
    // Static memory allocation
    // int arr[5] = {1,2,3,4,5};

    // Dynamic array allocation
    int n;
    cin >> n;

    int *arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    printArray(arr, n);
}