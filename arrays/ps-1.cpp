#include <iostream>
using namespace std;

int main()
{
    int arr[10];

    for (int i = 0; i < 10; i++)
    {
        cout << "Enter the element at index " << i << " : ";
        cin >> arr[i];
    }

    cout << "Printing after taking input :" << endl;

    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " " << endl;
    }
    cout << endl;
    for (int i = 0; i < 10; i++)
    {
        arr[i] = arr[i] * 2;
    }

    cout << "Printing after double up :" << endl;

    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " " << endl;
    }
}