/*
Tower of hanoi is a game in which we need to move disk from source tower to destination tower
the game of rules are like that small disk can never be above the large disks and only
one disk can be move at a time, to fulfill this steps one extra helper tower is also provided
see a video of it to visualize the problem.

Question is in how many steps n disks can be transferred from source to destination via helper
actually there is straight forward formula that (2 raise to the power n) -1

But we need to sove it via the recursion
 */

#include <iostream>
using namespace std;

int toh(int n)
{
    if (n == 1)
        return 1;

    return toh(n - 1) + 1 + toh(n - 1);
}

void stepsInToh(int n, char s, char d, char h)
{

    if (n == 0)
    {
        return;
    }

    stepsInToh(n - 1, s, h, d);
    cout << "Moving disk " << n << " from " << s << " to " << d << endl;
    stepsInToh(n - 1, s, d, h);
}

int main()
{
    cout << toh(2) << endl;
    stepsInToh(2, 'A', 'C', 'B');
}