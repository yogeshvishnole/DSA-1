/*
Given input array = 5,5,6,5,6 el = 5
Output - occurences of 5 = 3

Given input array = 5,5,6,5,6 el = 5
Output - occurences of 6 = 2

 */

#include <iostream>
using namespace std;

int countOccurences(int arr[], int size, int el)
{
    if (size == 0)
        return 0;

    return (arr[size - 1] == el ? 1 : 0) + countOccurences(arr, size - 1, el);
}

// lets take the ans var from outside
void countOccurences2(int arr[], int size, int el, int i, int &ans)
{
    if (i == size)
        return;
    if (arr[i] == el)
        ans++;
    countOccurences2(arr, size, el, i + 1, ans);
}

int main(int argc, char **argv)
{
    int arr[] = {5, 5, 6, 5, 6};
    cout << "count of 5 is : " << countOccurences(arr, 5, 5) << endl;
    cout << "count of 6 is : " << countOccurences(arr, 5, 6) << endl;
    int ans5 = 0;
    int ans6 = 0;
    countOccurences2(arr, 5, 5, 0, ans5);
    countOccurences2(arr, 5, 6, 0, ans6);
    cout << "count of 5 is : " << ans5 << endl;
    cout << "count of 6 is : " << ans6 << endl;
}