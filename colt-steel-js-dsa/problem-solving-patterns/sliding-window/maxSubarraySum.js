/* 

Sliding Window - maxSubarraySum

Given an array of integers and a number, write a function called maxSubarraySum, which finds the maximum sum of a subarray with the length of the number passed to the function.

Note that a subarray must consist of consecutive elements from the original array. In the first example below, [100, 200, 300] is a subarray of the original array, but [100, 300] is not.

maxSubarraySum([100,200,300,400], 2) // 700
maxSubarraySum([1,4,2,10,23,3,1,0,20], 4)  // 39 
maxSubarraySum([-3,4,0,-2,6,-1], 2) // 5
maxSubarraySum([3,-2,7,-4,1,-1,4,-2,1],2) // 5
maxSubarraySum([2,3], 3) // null
Constraints:

Time Complexity - O(N)

Space Complexity - O(1)
*/

function maxSubarraySum(inputArr, n) {
  if (inputArr.length < n) return null;
  let curWindowSum = inputArr.slice(0, n).reduce((sum, cur) => sum + cur, 0);
  let maxSum = curWindowSum;

  let windowStart = 1;
  let windowEnd = n;

  while (windowEnd <= inputArr.length - 1) {
    curWindowSum =
      curWindowSum - inputArr[windowStart - 1] + inputArr[windowEnd];
    if (curWindowSum > maxSum) {
      maxSum = curWindowSum;
    }
    windowStart++;
    windowEnd++;
  }

  return maxSum;
}

console.log(
  "maxSubarraySum([100,200,300,400], 2)",
  maxSubarraySum([100, 200, 300, 400], 2)
); // 700
console.log(
  "maxSubarraySum([1,4,2,10,23,3,1,0,20], 4)",
  maxSubarraySum([1, 4, 2, 10, 23, 3, 1, 0, 20], 4)
); // 39
console.log(
  "maxSubarraySum([-3,4,0,-2,6,-1], 2)",
  maxSubarraySum([-3, 4, 0, -2, 6, -1], 2)
); // 5
console.log(
  "maxSubarraySum([3,-2,7,-4,1,-1,4,-2,1], 2)",
  maxSubarraySum([3, -2, 7, -4, 1, -1, 4, -2, 1], 2)
); // 5
console.log("maxSubarraySum([2,3], 3)", maxSubarraySum([2, 3], 3)); // null
