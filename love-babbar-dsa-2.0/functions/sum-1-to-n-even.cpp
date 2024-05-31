#include <iostream>
using namespace std;

int sum1tonEven(int n)
{
    int sum = 0;
    for (int i = 0; i <= n; i++)
    {
        if (i % 2 == 0)
            sum += i;
    }
    return sum;
}

int main()
{
    int n;
    cin >> n;
    cout << sum1tonEven(n);
}