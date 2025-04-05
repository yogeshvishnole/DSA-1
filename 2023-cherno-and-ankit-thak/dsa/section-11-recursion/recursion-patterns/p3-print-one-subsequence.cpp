/*

So we are going to learn three patterns -
1. Print all subsequences
2. Print one subseuence
3. Count subsequences
In this file we are going to see the print all subsequences
In the next file it will be print one subsequence and in the next file
it will count subsequences with given sum

ALL THREE ARE IMP TECHNIQUES IN PROBLEM SOLVING

Given a array, print one subsequences of the given array whose sum is equal to the
given sum.
So given arr = [1,2,1] desired sum = 2, so we have to print all subsequences (in same order as given
 arr) whose sum is equal to desired sum of 2.

 ANS - [1,1] and [2]

 So approach same backtracking pick and not pick approach and print one subsequence in the final
(when index== length of given arr) recursion call and return true, if one function call returned the
true we will not do any further recursion calls, so very minor code changes from print all subsequeces
code.

*/
#include <iostream>
#include <vector>
using namespace std;

bool printOneSubsequence(int index, int currentSum, int &desiredSum, vector<int> &tempSubsequenceStore, int inputArr[], int &sizeOfInputArr)
{

    if (index == sizeOfInputArr)
    {

        if (currentSum == desiredSum)
        {
            // print the subsequence
            for (auto el : tempSubsequenceStore)
            {
                cout << el << " ";
            }
            cout << endl;

            return true;
        }
        return false;
    }

    // pick the element
    tempSubsequenceStore.push_back(inputArr[index]);
    if (printOneSubsequence(index + 1, currentSum + inputArr[index], desiredSum, tempSubsequenceStore, inputArr, sizeOfInputArr) == true)
        return true;

    // not pick the element
    // remove the current element from tempSubsequenceStore because we added it above
    tempSubsequenceStore.pop_back();
    if (printOneSubsequence(index + 1, currentSum, desiredSum, tempSubsequenceStore, inputArr, sizeOfInputArr) == true)
        return true;
}

int main()
{
    int inputArr[] = {1, 2, 1};
    int sizeOfInputArr = 3;
    int desiredSum = 2;

    vector<int> tempSubsequenceStore;
    printOneSubsequence(0, 0, desiredSum, tempSubsequenceStore, inputArr, sizeOfInputArr);
}