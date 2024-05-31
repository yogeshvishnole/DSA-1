#include <iostream>
using namespace std;

int minElem(int arr[], int size)
{
    int min = arr[0];

    for (int i = 0; i < size; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }

    return min;
}

int main()
{

    int arr[7] = {20, 4, 15, 2, 6, 8, 11};
    cout << minElem(arr, 7);
}