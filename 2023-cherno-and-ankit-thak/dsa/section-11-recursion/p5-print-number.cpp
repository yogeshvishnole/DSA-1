/*

Problem is
Input n = 5;
Output Print elements from 1 to 5 like 1,2,3,4,5\
Input n=3
Output 1,2,3
We can easily solve it by iteration but you have to solve it bvy recursion
 */

#include <iostream>
using namespace std;

// tail recursion or backtracing recursion or post order recursion
void printNumbers(int n)
{
    if (n == 1)
    {
        cout << 1 << " ";
    }
    else
    {
        printNumbers(n - 1);

        cout << n << " ";
    }
}


// head recursion or pre order recursion
void printNumbersDesc(int n)
{
    if (n == 0)
    {
        return;
    }

    cout << n << " ";

    printNumbersDesc(n - 1);
}

int main(int argc, char **argv)
{
    printNumbers(5);
    cout << endl;
    printNumbersDesc(5);
}