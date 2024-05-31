#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n)
{
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return false;
    }

    return true;
}

void printPrimes(int n)
{
    for (int i = 1; i <= n; i++)
    {
        if (isPrime(i) == 1)
            cout << i << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    printPrimes(n);
}