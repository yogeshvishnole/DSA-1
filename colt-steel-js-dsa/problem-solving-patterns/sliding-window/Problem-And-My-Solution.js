/* Write a function called maxSubarraySum which accepts
an array of integers and a number called n. The function
should calculate the maximum sum of n consecutive
elements in the array. */

/* maxSubarraySum([1,2,5,2,8,1,5],2) // 10 COPY
maxSubarraySum( [1,2,5,2,8,1,5],4) // 17
maxSubarraySum([4,2,1,6],1) // 6
maxSubarraySum([4,2,1,6,2],4) // 13
maxSubarraySum( ( ),4) // null */

function maxSubarraySum(arr, n) {
  if (n > arr.length) {
    return null;
  }
  let subarraySum = 0;
  for (let i = 0; i < n; i++) {
    subarraySum += arr[i];
  }

  let maxSubarraySum = subarraySum;
  for (let i = n; i < arr.length; i++) {
    subarraySum = subarraySum - arr[i - n] + arr[i];
    if (subarraySum > maxSubarraySum) {
      maxSubarraySum = subarraySum;
    }
  }
  return maxSubarraySum;
}

console.log(
  "maxSubarraySum([1, 2, 5, 2, 8, 1, 5], 2)",
  maxSubarraySum([1, 2, 5, 2, 8, 1, 5], 2)
);
console.log(
  "maxSubarraySum( [1,2,5,2,8,1,5],4)",
  maxSubarraySum([1, 2, 5, 2, 8, 1, 5], 4)
);
console.log(
  "maxSubarraySum([4,2,1,6,2],4)",
  maxSubarraySum([4, 2, 1, 6, 2], 4)
);
console.log("maxSubarraySum([4,2,1,6],1)", maxSubarraySum([4, 2, 1, 6], 1));
console.log("maxSubarraySum( [],4)", maxSubarraySum([], 4));
