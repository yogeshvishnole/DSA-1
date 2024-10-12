
/*
Given an array like -
[2,2,1,1,2]
Find the majority element in the array, majority element is the element which appears more than
n/2 times in the array, assume input array will always contains the majority element.
We will use moores voting algorithm to solve this problem
 */

#include <iostream>
using namespace std;

int findMajorityElement(int arr[], int size)
{
    int majority = arr[0];
    int count = 1;
    for (int i = 1; i < size; i++)
    {
        if (arr[i] == majority)
        {
            count++;
        }
        else
        {
            count--;
            if (count == 0)
            {
                majority = arr[i];
                count = 1;
            }
        }
    }

    // Lets assume if all the inputs provided will not contain majority element then
    // how we find out whether the element provided in majority or not, we will count the
    // number of occurences of majority element in the array if it is greater than n/2 we will
    // return the majority otherwise will return -1
    return majority;
}

int main(int argc, char **argv)
{
    // int arr[] = {2, 2, 2, 1};
    int arr[] = {4, 7, 4, 4, 7, 4, 4, 9, 4, 3};
    cout << findMajorityElement(arr, 10) << endl;
}
