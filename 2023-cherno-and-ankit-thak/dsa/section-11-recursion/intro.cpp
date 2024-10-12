/*

What is recursion ?
A function calling itself is called recursion.

When to use recursion ?

When a problem can be breaked into smaller problem of the same nature then we can solve such
problems with recursion.

For example n! = n*(n-1)*(n-2)...*1
n! = n*(n-1)!
Or in terms of functions
fact(n) = n*fact(n-1)

Lets solve the factorial problem with recursion

 */

#include <iostream>
using namespace std;

int fact(int n)
{
    if (n < 0)
        return -1;
    // base or terminating condition is most important,if we do not have terminatimg condition recursion
    // will stuck into the infinite loop
    if (n == 1 || n == 0)
    {
        return 1;
    }
    return n * fact(n - 1);
}

int main()
{
    cout << fact(5) << endl;
}