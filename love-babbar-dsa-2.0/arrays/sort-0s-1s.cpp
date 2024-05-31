#include <iostream>
using namespace std;

void sort0s1s(int arr[], int size)
{
    int count0s = 0;
    int count1s = 0;

    for (int i = 0; i < size; i++)
    {
        if (arr[i])
        {
            count1s++;
        }
        else
        {
            count0s++;
        }
    }

    for (int i = 0; i < count0s; i++)
    {
        arr[i] = 0;
    }

    for (int i = count0s; i < size; i++)
    {
        arr[i] = 1;
    }
}

// void sort011sTwoPointer(int arr[], int size)
// {
//     int i = 0;
//     int j = size - 1;

//     while (i <= j)
//     {
//         if (arr[j] == 1)
//         {
//             j++;
//         }
//         if (arr[i] == 1)
//         {
//             swap(arr[i], arr[j])
//         }
//     }
// }

int main()
{

    int arr01[] = {0, 1, 0, 1, 1, 0, 0, 0, 0};

    int size = 9;

    cout << "Array before sorting : " << endl;

    for (int i = 0; i < size; i++)
    {
        cout << arr01[i] << " ";
    }

    sort0s1s(arr01, size);

    cout << "Array after sorting : " << endl;

    for (int i = 0; i < size; i++)
    {
        cout << arr01[i] << " ";
    }
}