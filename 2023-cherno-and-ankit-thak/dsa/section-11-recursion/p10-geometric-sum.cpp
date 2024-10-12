/*
Given input -  k an integer
Output will be -
1/pow(2,0) + 1/pow(2,1) + 1/(pow(2,3) + .... + 1/pow(2,k);

Example for k = 3
Output will be -
1/pow(2/0) + 1/pow(2,1) + 1/pow(2,2) + 1/pow(2,3) = 1+0.5+0.25+0.125 = 1.875
 */

#include <iostream>
#include <cmath>
using namespace std;

double geometricSum(int k)
{
    // Base Case
    if (k == 0)
        return 1;

    // recursive case
    double smallAns = geometricSum(k - 1);

    // calculation
    return smallAns + (1.0 / pow(2, k));
}

int main(int argc, int **argv)
{
    cout << "Geometric Series sum when k=3 is " << geometricSum(3) << endl;
}