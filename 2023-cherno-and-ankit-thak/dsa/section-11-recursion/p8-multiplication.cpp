/*
We need to found m*n using the recursion
Now we know that m * n = m+m+m+m+m...n times
so mul(m,n) = m+mul(m,n-1);
  */

#include <iostream>
using namespace std;

int mul(int m, int n)
{

    // base case
    if (n == 0)
        return 0;

    return m + mul(m, n - 1);
}

int main(int argc, char **argv)
{
    cout << "Mul of 4 and 5 is: " << mul(4, 5) << endl;
}