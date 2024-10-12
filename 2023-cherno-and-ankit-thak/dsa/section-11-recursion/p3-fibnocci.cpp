/*
fibnocci series is
0 1 1 2 3 5 8 13 ....
so fib(n) = fib(n-1) + fib(n-2)
and base conditions fib(1) == 0,fib(2) == 1 and fib(3) == 1
so lets solve it by recursion
 */

#include <iostream>
using namespace std;

int fib(int n)
{
    // base condtion is  -
    if (n == 1)
        return 0;
    if (n == 2)
        return 1;
    if (n == 3)
        return 1;

    // induction hypothesis
    int smallAns = fib(n - 1) + fib(n - 2);

    // induction
    return smallAns;
}

int main(int argc, char **argv)
{

    // Below two lines are just for understanding the inputs of the main function
    cout << "Value of argc is : " << argc << endl;
    cout << "Value of argv is : " << argv[0] << endl;
    cout << "The 9th fib should be 21: " << fib(9) << endl;
}