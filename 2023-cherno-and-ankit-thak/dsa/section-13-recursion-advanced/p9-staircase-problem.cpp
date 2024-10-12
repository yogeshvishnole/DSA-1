/*
Find the number of ways to reach nth stair, when user can only jump max of 3 jump at a time.

So for stair 0 only 1 way
for stair 1 only 1 way
for stair 2 - 1,1 and 2 = 2 ways
for stair 3 - 1,1,1 and 1,2 and 2,1 and 3

Now to reach nth step user can take 1 step from n-1th stair
or 2 steps from n-2th stair or 3 jump from n-3rd stair he has none other option than
this 3 so
f(n) = f(n-1) + f(n-2) + f(n-3);
 */
#include <iostream>
using namespace std;

int countWays(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    if (n == 2)
        return 2;

    return countWays(n - 1) + countWays(n - 2) + countWays(n - 3);
}

int main()
{
    cout << countWays(4) << endl;
}