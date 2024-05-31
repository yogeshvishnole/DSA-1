#include <iostream>
using namespace std;

void shiftArrayLeftBy1(int arr[], int size)
{
    int temp = arr[0];
    for (int i = 0; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    arr[size - 1] = temp;
}

int main()
{
    int size = 6;
    int arr[6] = {10, 20, 30, 40, 50, 60};
    shiftArrayLeftBy1(arr, size);
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " " << endl;
    }
}