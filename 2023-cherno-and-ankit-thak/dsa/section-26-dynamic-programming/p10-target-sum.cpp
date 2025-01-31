/*

Read the problem statement and its approach, this problem
solution is exactly that is of p9, thats why I am not writing the code for it.

Problem Statement: Target Sum
You are given an array nums of N integers and a target sum T. You need to assign
either a + or - sign to each element in nums such that the resulting sum equals T.

Return the total number of ways to achieve this target.

Mathematical Formulation
Each number can contribute to the total sum in two ways:

With a positive sign (+num)
With a negative sign (-num)
Let:

S1 be the sum of numbers assigned +
S2 be the sum of numbers assigned -

Since the total sum of the array is:
S=S1+S2

We need to find:
S1−S2=T

Rearranging:
S1=(S+T)/2
​

Thus, the problem reduces to finding the number of subsets with sum (S + T) / 2.
This is equivalent to the "Count of subsets with a given sum" problem.

Constraints:
The array can contain zeroes and positive integers.
The sum of elements should be greater than or equal to T, i.e., S >= T.
(S + T) should be even, otherwise, a valid partition is not possible.
Example 1
Input:
nums = {1, 1, 1, 1, 1};
T = 3;
Output:
5
Explanation:
Total sum = 1 + 1 + 1 + 1 + 1 = 5
Subset sum to find:
S1=(5+3)/2=4
Valid ways to achieve target sum 3:
+1 -1 +1 +1 +1 = 3
+1 +1 -1 +1 +1 = 3
+1 +1 +1 -1 +1 = 3
+1 +1 +1 +1 -1 = 3
-1 +1 +1 +1 +1 = 3
Thus, count = 5.

Example 2
Input:
nums = {2, 3, 5, 6, 8, 10};
T = 10;
Output:
3
Explanation:
Total sum = 34, subset sum to find:
S1=(34+10)/2=22
Valid subsets with sum 22:
{2, 3, 5, 6, 6}
{3, 5, 6, 8}
{2, 6, 8, 6}
Thus, count = 3.


  */
