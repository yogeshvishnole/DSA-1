#include <iostream>
using namespace std;

void shiftArrayByk(int arr[], int size, int k)
{
    int temp[k];

    for (int i = size - k, j = 0; i < size; i++, j++)
    {
        temp[j] = arr[i];
    }

    for (int i = size - 1; i > k - 1; i--)
    {
        arr[i] = arr[i - k];
    }

    for (int i = 0; i < k; i++)
    {
        arr[i] = temp[i];
    }
}

int main()
{
    int size = 6;
    int arr[6] = {10, 20, 30, 40, 50, 60};

    shiftArrayByk(arr, size, 3);

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}