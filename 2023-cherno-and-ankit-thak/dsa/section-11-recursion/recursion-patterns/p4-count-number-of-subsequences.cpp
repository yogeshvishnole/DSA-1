/*

So we are going to learn three patterns -
1. Print all subsequences
2. Print one subseuence
3. Count subsequences
In this file we are going to see the print all subsequences
In the next file it will be print one subsequence and in the next file
it will count subsequences with given sum

ALL THREE ARE IMP TECHNIQUES IN PROBLEM SOLVING

Given a array, count numnber subsequences of the given array whose sum is equal to the
given sum.
So given arr = [1,2,1] desired sum = 2, so we have to print all subsequences (in same order as given
 arr) whose sum is equal to desired sum of 2.

 ANS - [1,1] and [2]

 So approach same backtracking pick and not pick approach and return one  in the final
(when index== length of given arr) if currentSum == desired sum otherwise return 0, and finally sum both the
pick and not pick calls return values and return their sum, that will nbe our count
code.

*/
#include <iostream>
#include <vector>
using namespace std;

int countSubsequences(int index, int currentSum, int &desiredSum, int inputArr[], int &sizeOfInputArr)
{

    if (index == sizeOfInputArr)
    {

        if (currentSum == desiredSum)
        {
            // return 1

            return 1;
        }
        return 0;
    }

    // pick the element
    int countOnPickingCurEl = countSubsequences(index + 1, currentSum + inputArr[index], desiredSum, inputArr, sizeOfInputArr);

    // not pick the element
    // remove the current element from tempSubsequenceStore because we added it above
    int countOnNotPickingCurEl = countSubsequences(index + 1, currentSum, desiredSum, inputArr, sizeOfInputArr);
    return countOnPickingCurEl + countOnNotPickingCurEl;
}

int main()
{
    int inputArr[] = {1, 2, 1};
    int sizeOfInputArr = 3;
    int desiredSum = 2;

    vector<int> tempSubsequenceStore;
    cout << countSubsequences(0, 0, desiredSum, inputArr, sizeOfInputArr) << endl;
}