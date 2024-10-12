#include <iostream>
using namespace std;

int lengthOfString(char str[])
{
    int strLen = 0;
    while (str[strLen] != '\0'  )
    {
        strLen++;
    }
    return strLen;
}

int main()
{
    char name[5];
    cout << "Enter your name: ";
    cin >> name;
    cout << "Your name is " << name << endl;
    cout<<lengthOfString(name);
    return 0;
}