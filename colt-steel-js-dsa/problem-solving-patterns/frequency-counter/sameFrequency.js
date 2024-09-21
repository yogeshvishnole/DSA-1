/* 
Question - 
Frequency Counter - sameFrequency
Write a function called sameFrequency. Given two positive integers, find out if the two numbers have the same frequency of digits.

Your solution MUST have the following complexities:

Time: O(N)

Sample Input:

sameFrequency(182,281) // true
sameFrequency(34,14) // false
sameFrequency(3589578, 5879385) // true
sameFrequency(22,222) // false
*/

function numberToArr(num) {
  let numArr = [];
  while (num !== 0) {
    let digit = num % 10;
    num = Math.floor(num / 10);
    numArr.push(digit);
  }
  return numArr;
}

function reverseArr(arr) {
  let start = 0;
  let end = arr.length - 1;

  while (start < end) {
    [arr[start], arr[end]] = [arr[end], arr[start]];
    start++;
    end--;
  }
  return arr;
}

console.log(reverseArr(numberToArr(182)));

function sameFrequency(num1, num2) {
  let num1Freq = {};
  let num2Freq = {};

  let num1Arr = numberToArr(num1);
  let num2Arr = numberToArr(num2);

  if (num1Arr.length !== num2Arr.length) {
    return false;
  }

  for (let num of num1Arr) {
    num1Freq[num] = ++num1Freq[num] || 1;
  }
  for (let num of num2Arr) {
    num2Freq[num] = ++num1Freq[num] || 1;
  }

  for (let num in num1Freq) {
    if (num1Freq[num] !== num2Freq[num]) {
      return false;
    }
  }

  return true;
}

console.log("sameFrequency(182, 281)", sameFrequency(182, 281)); // true
console.log("sameFrequency(34, 14)", sameFrequency(34, 14)); // false
console.log("sameFrequency(3589578, 5879385)", sameFrequency(3589578, 5879385)); // true
console.log("sameFrequency(22, 222)", sameFrequency(22, 222)); // false
