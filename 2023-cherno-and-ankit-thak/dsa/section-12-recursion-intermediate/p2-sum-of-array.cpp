/*
Given input = [1,2,3,4,5]
Ouput = sum of the array = 15
 */

#include <iostream>
using namespace std;

//  Approach 1 break the array from end
int sumOfArray(int arr[], int n)
{
    if (n == 1)
        return arr[0];
    return arr[n - 1] + sumOfArray(arr, n - 1);
}
// Approach 2 break the array from start

int sumOfArray2(int arr[], int n)
{
    if (n == 1)
        return arr[0];
    return arr[0] + sumOfArray(arr + 1, n - 1);
}

int main(int arc, char **argv)
{
    int arr[] = {1, 2, 3, 4, 5};
    cout << sumOfArray(arr, 5) << endl;
    cout << sumOfArray2(arr, 5) << endl;
}