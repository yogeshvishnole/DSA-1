#include <iostream>
using namespace std;

void shiftArrayBy1(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        swap(arr[0], arr[i]);
    }
}

int main()
{
    int size = 6;
    int arr[6] = {10,
                  20,
                  30,
                  40,
                  50,
                  60};
    shiftArrayBy1(arr, size);
    cout << "array after shifting : " << endl;

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}