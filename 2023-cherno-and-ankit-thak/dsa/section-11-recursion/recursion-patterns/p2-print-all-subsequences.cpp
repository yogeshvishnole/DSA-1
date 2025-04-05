/*

So we are going to learn three patterns -
1. Print all subsequences
2. Print one subseuence
3. Count subsequences
In this file we are going to see the print all subsequences
In the next file it will be print one subsequence and in the next file
it will count subsequences with given sum

ALL THREE ARE IMP TECHNIQUES IN PROBLEM SOLVING

Given a array, print all the subsequences of the given array whose sum is equal to the
given sum.
So given arr = [1,2,1] desired sum = 2, so we have to print all subsequences (in same order as given
 arr) whose sum is equal to desired sum of 2.

 ANS - [1,1] and [2]

 So approach sam ebacktracking pick and not pick approach and print the subsequence in the final
(when index== length of given arr) recursion call.

*/
#include <iostream>
#include <vector>
using namespace std;

void printAllSubsequences(int index, int currentSum, int &desiredSum, vector<int> &tempSubsequenceStore, int inputArr[], int &sizeOfInputArr)
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
        }
        return;
    }

    // pick the element
    tempSubsequenceStore.push_back(inputArr[index]);
    printAllSubsequences(index + 1, currentSum + inputArr[index], desiredSum, tempSubsequenceStore, inputArr, sizeOfInputArr);

    // not pick the element
    // remove the current element from tempSubsequenceStore because we added it above
    tempSubsequenceStore.pop_back();
    printAllSubsequences(index + 1, currentSum, desiredSum, tempSubsequenceStore, inputArr, sizeOfInputArr);
}

int main()
{
    int inputArr[] = {1, 2, 1};
    int sizeOfInputArr = 3;
    int desiredSum = 2;

    vector<int> tempSubsequenceStore;
    printAllSubsequences(0, 0, desiredSum, tempSubsequenceStore, inputArr, sizeOfInputArr);
}