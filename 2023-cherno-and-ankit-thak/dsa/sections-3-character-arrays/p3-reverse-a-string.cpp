#include <iostream>
using namespace std;

int lengthOfString(char str[])
{
    int strLen = 0;
    while (str[strLen] != '\0')
    {
        strLen++;
    }
    return strLen;
}

void reverseString(char str[100])
{
    int end = lengthOfString(str) - 1;
    int start = 0;

    while (start < end)
    {
        swap(str[start], str[end]);
        start++;
        end--;
    }
}

int main()
{

    char str[100];

    cout << "Enter the string to reverse: ";

    cin.getline(str, 100);

    cout << "String before reversal: " << str << endl;

    reverseString(str);

    cout << "String after reversal: " << str << endl;
}