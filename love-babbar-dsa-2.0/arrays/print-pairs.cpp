#include <iostream>
using namespace std;

void printPairs(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = size - 1; j > 0; j--)
        {
            cout << arr[i] << " " << arr[j] << endl;
        }
    }
}

int main()
{
    int arr[3] = {10, 20, 30};
    printPairs(arr, 3);
}