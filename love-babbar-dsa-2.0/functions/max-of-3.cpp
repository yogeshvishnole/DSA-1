#include <iostream>
using namespace std;

int maxOf3(int a, int b, int c)
{
    if (a > b)
    {
        if (a > c)
        {
            return a;
        }
        else
        {
            return c;
        }
    }
    else if (b > c)
    {
        return b;
    }
    else
    {
        return c;
    }
}

int main()
{

    cout << maxOf3(3, 3, 1);
}