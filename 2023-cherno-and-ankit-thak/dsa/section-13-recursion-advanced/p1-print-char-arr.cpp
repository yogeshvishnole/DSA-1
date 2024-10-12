/*

Problem1
Given char arr ['a','b','c']
Print it "abc";
Problem1
Given char arr ['a','b','c']
Reverse print it "cba";

 */

#include <iostream>
using namespace std;

void print(char arr[])
{
    // Base case
    if (arr[0] == '\0')
        return;

    cout << arr[0];

    print(arr + 1);
}
void reversePrint(char arr[])
{
    // Base case
    if (arr[0] == '\0')
        return;

    reversePrint(arr + 1);

    cout << arr[0];
}

int main(int argc, char **argv)
{
    char arr[] = "abc";
    print(arr);
    cout << endl;
    reversePrint(arr);
    cout << endl;
}