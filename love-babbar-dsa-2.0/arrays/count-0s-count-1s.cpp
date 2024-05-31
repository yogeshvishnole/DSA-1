#include <iostream>
using namespace std;

int count0s(int arr[], int size)
{
    int count0 = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == 0)
        {
            count0++;
        }
    }
    return count0;
}

int count1s(int arr[], int size)
{
    int count1 = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == 1)
        {
            count1++;
        }
    }
    return count1;
}

int main()
{
    int arr[] = {0, 0, 1, 0, 1, 1, 0, 0, 0};
    int size = 9;

    cout << "no. of 0s " << count0s(arr, 9) << endl;
    cout << "no. of 1s " << count1s(arr, 9) << endl;
}