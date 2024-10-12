/*
Power of x^n = x*x*...upto n times
 pow(x,n) = x*pow(x,n-1);

 pow(x,0) = 1;

 */

#include <iostream>
using namespace std;

int pow(int base, int exponent)
{
    // base case
    if (exponent == 0)
    {
        return 1;
    }
    if (exponent == 1)
    {
        return base;
    }

    // induction step
    return base * pow(base, exponent - 1);
}

int main(int argc, char *argv[])
{
    cout << "Power of 2 raise to the power 8 is: " << pow(2, 8) << endl;
}