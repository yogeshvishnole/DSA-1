#include <iostream>
using namespace std;

int uniqueElementInArray(int arr[], int size)
{
    int uniqueElement = arr[0];
    for (int i = 1; i < size; i++)
    {
        uniqueElement = uniqueElement ^ arr[i];
    }
    return uniqueElement;
}

int main()
{
    int arr[9] = {2, 10, 11, 13, 10, 2, 15, 13, 15};
    cout << "Unique element in array is : " << uniqueElementInArray(arr, 9) << endl;
}