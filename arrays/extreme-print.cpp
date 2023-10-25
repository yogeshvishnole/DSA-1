#include <iostream>
using namespace std;

void extremePrint(int arr[], int size)
{
    int i = 0;
    int j = size - 1;

    while (i <= j)
    {
        if (i == j)
        {
            cout << arr[i] << endl;
        }
        else
        {
            cout << arr[i] << " " << arr[j] << " ";
        }
        i++;
        j--;
    }
}

int main()
{
    int arr[6] = {10, 20, 30, 40, 50, 60};
    extremePrint(arr, 6);
}