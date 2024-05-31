#include <iostream>
using namespace std;

bool isEven(int n)
{
    return n % 2 == 0;
}

int main()
{
    cout << isEven(11);
}