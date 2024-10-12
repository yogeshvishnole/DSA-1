#include <bits/stdc++.h>
using namespace std;

int fact(int n)
{
    //  1st step base case
    if (n == 0)
        return 1;

    // 2nd step Assumption recursive case
    int smallAns = fact(n - 1);

    // 3rd step calculation
    return n * smallAns;
}

int main(int argc, char **argv)
{

    // Recursion is based on PMI (principle of mathemeatical induction)

    //    steps of PMI

    // 1st step Start with trivial problem --> base  case
    // 2nd step Assumption F(K) or F(k-1) is true
    // 3rd step using step 2 prove F(k+1) or F{k) is true

    cout << fact(4) << endl;
}