#include <iostream>
using namespace std;

int sum1ton(int n)
{
    return (n * (n + 1)) / 2;
}

int main()
{
    int n;
    cin >> n;
    cout << sum1ton(n) << endl;
}