#include <iostream>
using namespace std;

int reverseArray(int arr[], int size)
{
    for (int i = 0; i < (size / 2); i++)
    {
        swap(arr[i], arr[size - i - 1]);
    }
}

int main()
{
    int arr[6] = {10, 20, 30, 40, 50, 60};
    cout << "Array before reverse: " << endl;
    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << " ";
    }
    reverseArray(arr, 6);
    cout << "Array after reverse: " << endl;
    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << " ";
    }
}