/*
Given char arr= "abc"
Output - its length  = 3
 */

#include <iostream>
using namespace std;

int findLength(char arr[])
{
    if (arr[0] == '\0')
        return 0;
    return 1 + findLength(arr + 1);
}

int main(int argc, char **argv)
{
    char arr[] = "abc";
    cout << "Length of arr 'abc' is : " << findLength(arr) << endl;
}