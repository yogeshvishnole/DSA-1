/*

Given array input - 5,5,6,5,6,7 and el = 5
Output - store all indexex of el in an array or vector [0,1,3]

Given array input - 5,5,6,5,6,7 and el = 7
Output -store all indexex of el in an array or vector  [5]

Given array input - 5,5,6,5,6,7 and el = 5
Output -store all indexex of el in an array or vector [2,4]



 */

#include <iostream>
#include <vector>
using namespace std;

// solution with vector
void storeAllPos(int arr[], int size, int el, int i, vector<int> &v)
{
    if (i == size)
        return;
    else
    {
        if (arr[i] == el)
            v.push_back(i);
    }
    storeAllPos(arr, size, el, i + 1, v);
}

// solution with arr, you need also return the occurences of the element
// so that you can print them later or you can know the size of the arr
int storeAllPosArr(int arr[], int size, int el, int i, int ans[], int ansIndex)
{
    if (i == size)
        return 0;
    else
    {
        if (arr[i] == el)
        {
            ans[ansIndex] = i;
            return 1 + storeAllPosArr(arr, size, el, i + 1, ans, ansIndex + 1);
        }
        else
        {
            return storeAllPosArr(arr, size, el, i + 1, ans, ansIndex);
        }
    }
}

void printVectors(vector<int> v)
{
    for (auto el : v)
    {
        cout << el << " ";
    }
    cout << endl;
}

int main(int argc, char **argv)
{

    vector<int> v5;
    vector<int> v6;
    vector<int> v7;
    int arr[] = {5, 5, 6, 5, 6, 7};
    storeAllPos(arr, 6, 5, 0, v5);
    storeAllPos(arr, 6, 6, 0, v6);
    storeAllPos(arr, 6, 7, 0, v7);
    printVectors(v5);
    printVectors(v6);
    printVectors(v7);
    int ansArr[10];
    int ansIndex5 = 0;
    int occurences5 = storeAllPosArr(arr, 6, 5, 0, ansArr, ansIndex5);
    for (int i = 0; i < occurences5; i++)
    {
        cout << ansArr[i] << " ";
    }
    cout << endl;
    int ansArr6[10];
    int ansIndex6 = 0;
    int occurences6 = storeAllPosArr(arr, 6, 6, 0, ansArr6, ansIndex6);
    for (int i = 0; i < occurences6; i++)
    {
        cout << ansArr6[i] << " ";
    }
    cout << endl;
    int ansArr7[10];
    int ansIndex7 = 0;
    int occurences7 = storeAllPosArr(arr, 6, 7, 0, ansArr7, ansIndex7);
    for (int i = 0; i < occurences7; i++)
    {
        cout << ansArr7[i] << " ";
    }
    cout << endl;
}