/* 

This problem is a variation of unbounded knapsack problem, this problem is so 
similar to unbounded knapsack that the code of both two problems is same, if we
keep the same variable naming, bhai sidhi bhasha me inhone bando ko confuse karne
ke liye language change karke yeh problem banayi because unbounded knapack is
very famous problem.

Formally - 

You are given a rod of length N and a price array prices, where prices[i] 
represents the price of a rod of length i + 1.

Your task is to determine the maximum profit you can obtain by cutting the rod 
into smaller lengths and selling those pieces.

Constraints:
You can make as many cuts as needed.
The sum of the pieces' lengths must not exceed N.
You can sell pieces of any available length from 1 to N.

Example 1
Input:
N = 8
prices = {1, 5, 8, 9, 10, 17, 17, 20};
Output:
22
Explanation:
We can cut the rod into pieces of lengths {2, 6}:

Length 2 → Price 5
Length 6 → Price 17
Total profit = 5 + 17 = 22 ✅ (Max possible)

Example 2
Input:
N = 4
prices = {2, 5, 7, 8};
Output:
10
Explanation:
We can cut the rod into two pieces of length 2:

Length 2 → Price 5
Length 2 → Price 5
Total profit = 5 + 5 = 10 ✅ (Max possible)
 */