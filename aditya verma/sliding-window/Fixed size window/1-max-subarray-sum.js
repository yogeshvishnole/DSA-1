/* 

One way to solve sliding window problems is by your general logic 
And one way is to follow a pattern which will be used in all problems

Recommendation - 
Here I will solve problems by both ways, but I you will practised the pattern, you do not hve to think about the code
in the challenges and this is a plus point go with the pattern.

Below pattern is for the Fixed size window problems
*/

// Max sub array sum without pattern

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

// Using the pattern

function maxSubarraySumSWPattern(inputArr, k) {
  // inputArr is the list
  // k is the windows size
  // and we have to find the max sum of the window

  // initialize windowStart and windowEnd vars
  let i = 0; // start of window
  let j = 0; // end of window

  // preparing for the window calculations
  let windowSum = 0;
  let maxWindowSum = Number.NEGATIVE_INFINITY;
  while (j < inputArr.length) {
    // CALCULATIONS
    windowSum = windowSum + inputArr[j];
    // Check if windows size hits
    if (j < k - 1) {
      // window size not hits
      j++; // reaching forward to complete the window
    } else if (j - i + 1 === k) {
      // window size hits
      // derive answer of the current windiw from the calculations of previous windows
      maxWindowSum = Math.max(maxWindowSum, windowSum);
      // remove the previous area calculations from the window
      windowSum -= inputArr[i];
      // slide the window forward
      i++;
      j++;
    }
  }
  if (maxWindowSum === Number.NEGATIVE_INFINITY) {
    return null;
  }
  return maxWindowSum;
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
console.log(
  "maxSubarraySumSWPattern([100,200,300,400], 2)",
  maxSubarraySumSWPattern([100, 200, 300, 400], 2)
); // 700
console.log(
  "maxSubarraySumSWPattern([1,4,2,10,23,3,1,0,20], 4)",
  maxSubarraySumSWPattern([1, 4, 2, 10, 23, 3, 1, 0, 20], 4)
); // 39
console.log(
  "maxSubarraySumSWPattern([-3,4,0,-2,6,-1], 2)",
  maxSubarraySumSWPattern([-3, 4, 0, -2, 6, -1], 2)
); // 5
console.log(
  "maxSubarraySumSWPattern([3,-2,7,-4,1,-1,4,-2,1], 2)",
  maxSubarraySumSWPattern([3, -2, 7, -4, 1, -1, 4, -2, 1], 2)
); // 5
console.log(
  "maxSubarraySumSWPattern([2,3], 3)",
  maxSubarraySumSWPattern([2, 3], 3)
); // null
