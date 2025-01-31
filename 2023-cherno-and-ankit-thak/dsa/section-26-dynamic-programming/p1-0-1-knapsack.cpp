/*
Given N items where each item has some weight and profit associated with it and also given a
bag with capacity W, [i.e., the bag can hold at most W weight in it]. The task is to put the
items into the bag such that the sum of profits associated with them is the maximum possible.

Note: The constraint here is we can either put an item completely into the bag or cannot put
it at all [It is not possible to put a part of an item into the bag].

Input: N = 3, W = 4, profit[] = {1, 2, 3}, weight[] = {4, 5, 1}
Output: 3
Explanation: There are two items which have weight less than or equal to 4. If we select the
item with weight 4, the possible profit is 1. And if we select the item with weight 1, the
possible profit is 3. So the maximum possible profit is 3. Note that we cannot put both the
items with weight 4 and 1 together as the capacity of the bag is 4.


Input: N = 3, W = 3, profit[] = {1, 2, 3}, weight[] = {4, 5, 6}
Output: 0
 */

/*
We will first solve it via recursion and using the choice diagram

choices here are -

if(weight of given item <= Capacity){
  case 1 include the item
  case 2 do not include the item
}else  if(weight of given item > Capacity){
   only case do not include the item
}

the above statement is our choice diagram.

so if we solve our problem recursion it goes like this -

int knapsack(int wt[],int val[],int W,int n){
// Base condition
// choice diagram
}

Now very effective way of getting the base case is think about the smallest valid inputs.
so here smallest inputs are if no items means n == 0 or if capacity is 0 simple enough
now lets write the code for 0-1 knapsack
 */

#include <iostream>
using namespace std;

int knapsack(int wt[], int val[], int W, int n)
{
    // Base condtion code
    if (n == 0 || W == 0)
    {
        return 0;
    }

    // Choice diagram implementation
    if (wt[n - 1] <= W)
    {
        return max(val[n - 1] + knapsack(wt, val, W - wt[n - 1], n - 1), knapsack(wt, val, W, n - 1));
    }
    else if (wt[n - 1] > W)
    {
        return knapsack(wt, val, W, n - 1);
    }
}

int main(int argc, char **argv)
{

    // int wt[] = {};
    // int val[] = {};
    // int W = 0;
    // int n = 0;

    // int wt[] = {4, 5, 1};
    // int val[] = {1, 2, 3};
    // int W = 4;
    // int n = 3;

    int wt[] = {4, 5, 6};
    int val[] = {1, 2, 3};
    int W = 3;
    int n = 3;

    cout << knapsack(wt, val, W, n) << endl;
}