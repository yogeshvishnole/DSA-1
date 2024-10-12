/*

Given Input array - [5,5,6,5,5,6],k=5
Output first index of k in array - 4

Given Input array - [5,5,6,5,5,6],k=6
Output first index of k in array - 5

We will use iterative recursion approach here
 */
#include <iostream>
using namespace std;

int firstIndex(int arr[], int size, int el, int i)
{
    if (i == size)
        return -1;
    if (arr[i] == el)
        return i;
    return firstIndex(arr, size, el, i + 1);
}

int main(int argc, char **argv)
{
    int arr[] = {5, 5, 6, 5, 5, 6};
    cout << "First index of 5 is: " << firstIndex(arr, 6, 5, 0) << endl;
    cout << "First index of 6 is: " << firstIndex(arr, 6, 6, 0) << endl;
}