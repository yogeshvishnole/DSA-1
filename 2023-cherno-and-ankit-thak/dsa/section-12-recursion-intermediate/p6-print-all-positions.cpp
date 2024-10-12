/*

Given array input - 5,5,6,5,6,7 and el = 5
Output - print all indexex of el = 5 ,Ans =  0,1,3

Given array input - 5,5,6,5,6,7 and el = 7
Output - print all indexex of el = 7,Ans =  5

Given array input - 5,5,6,5,6,7 and el = 5
Output - print all indexex of el = 6,Ans =  2,4



 */

#include <iostream>
using namespace std;

void printAllPos(int arr[], int size, int el, int i)
{
    if (i == size)
        return;
    else
    {
        if (arr[i] == el)
            cout << i << " ";
    }
    printAllPos(arr, size, el, i + 1);
}

int main(int argc, char **argv)
{

    int arr[] = {5, 5, 6, 5, 6, 7};
    printAllPos(arr, 6, 5, 0);
    cout << endl;
    printAllPos(arr, 6, 6, 0);
    cout << endl;
    printAllPos(arr, 6, 7, 0);
    cout << endl;
}