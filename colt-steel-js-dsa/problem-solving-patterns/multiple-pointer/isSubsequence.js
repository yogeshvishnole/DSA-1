/* 

Multiple Pointers - isSubsequence
Write a function called isSubsequence which takes in two strings and checks whether the characters in the first string form a subsequence of the characters in the second string. In other words, the function should check whether the characters in the first string appear somewhere in the second string, without their order changing.

Examples:

isSubsequence('hello', 'hello world'); // true
isSubsequence('sing', 'sting'); // true
isSubsequence('abc', 'abracadabra'); // true
isSubsequence('abc', 'acb'); // false (order matters)
Your solution MUST have AT LEAST the following complexities:

Time Complexity - O(N + M)

Space Complexity - O(1)

*/

// @param testStr
function isSubsequence(testStr, str) {
  let left = 0;
  let right = str.length - 1;

  let leftCurChar = 0;
  let rightCurChar = testStr.length - 1;

  while (
    right >= left &&
    rightCurChar >= 0 &&
    leftCurChar <= testStr.length - 1 &&
    leftCurChar <= rightCurChar
  ) {
    if (testStr.charAt(leftCurChar) === str.charAt(left)) {
      leftCurChar++;
    }
    if (testStr.charAt(rightCurChar) === str.charAt(right)) {
      rightCurChar--;
    }
    left++;
    right--;
  }

  if (
    rightCurChar < 0 ||
    leftCurChar > testStr.length - 1 ||
    leftCurChar > rightCurChar
  ) {
    return true;
  }
  return false;
}

console.log(
  `isSubsequence('hello', 'hello world')`,
  isSubsequence("hello", "hello world")
);
console.log(`isSubsequence('sing', 'sting')`, isSubsequence("sing", "sting"));
console.log(
  `isSubsequence('abc', 'abracadabra')`,
  isSubsequence("abc", "abracadabra")
);
console.log(`isSubsequence('abc', 'acb')`, isSubsequence("abc", "acb"));
